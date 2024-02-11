#include "PmergeMe.hpp"

template<typename Container, typename Pairs>
PmergeMe<Container, Pairs>::PmergeMe(Container& vec, ContainerType type)
    : leftover_(UNDEFINED),
      pairs_(create_pairs_(vec)),
      jcbsthal_(precalculate_jcbsthal_(vec)),
      offset_(1),
      start_(clock()),
      end_(0),
      elapsed_(0),
      type_(type)
  {}

template<typename Container, typename Pairs>
PmergeMe<Container, Pairs>::~PmergeMe() {}


template<typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::sort()
{
  merge_core_(pairs_);
  split_pairs_();
  insert_pend_();
  elapsed_ = (static_cast<double>(end_ - start_) / CLOCKS_PER_SEC) * 1000000;
  print_time_();
}

template<typename Container, typename Pairs>
PmergeMe<Container, Pairs>::PmergeMe(const PmergeMe& rhs)
{
  *this = rhs;
}

template<typename Container, typename Pairs>
PmergeMe<Container, Pairs>& PmergeMe<Container, Pairs>::operator=(const PmergeMe& rhs)
{
  if (this != &rhs) {
    main_ = rhs.main_;
    pairs_ = rhs.pairs_;
    pend_ = rhs.pend_;
    leftover_ = rhs.leftover_;
    offset_ = rhs.offset_;
  }
  return *this;
}

template<typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::merge_core_(Pairs& main)
{
  if (main.size() <= 1)
    return;

  size_t mid = main.size() / 2;
  Pairs left(main.begin(), main.begin() + mid);
  Pairs right(main.begin() + mid, main.end());

  merge_core_(left);
  merge_core_(right);

  std::merge(left.begin(), left.end(), right.begin(), right.end(), main.begin());
}

template<typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::split_pairs_()
{
  if (pairs_.empty()) {
    std::cerr << "empty\n";
    exit(1);
  }
  typename Pairs::iterator it;
  main_.push_back((pairs_.at(0)).second);
  main_.push_back(pairs_.at(0).first);
  pend_.push_back(pairs_.at(0).second);
  for (it = pairs_.begin() + 1; it != pairs_.end(); ++it) {
    main_.push_back(it->first);
    pend_.push_back(it->second);
  }
  if (leftover_ != UNDEFINED) {
    pend_.push_back(leftover_);
  }
}

template<typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::insert_pend_()
{
  typename Container::iterator it;
  int prev_jcb = 0;
  for (it = jcbsthal_.begin(); it != jcbsthal_.end(); ++it) {
    int i = *it;
    if (i > static_cast<int>(pend_.size() - 1)) {
      i = pend_.size() - 1;
    }
    while (i > prev_jcb) {
      int to_insert = pend_.at(i);
      typename Container::iterator pos = std::lower_bound(main_.begin(),
          main_.begin() + i + offset_, to_insert);
      main_.insert(pos, to_insert);
      ++offset_;
      --i;
    }
    prev_jcb = *it;
  }
  end_ = clock();
}

template<typename Container, typename Pairs>
Pairs PmergeMe<Container, Pairs>::create_pairs_(Container input)
{
  if (input.size() % 2 != 0) {
    leftover_ = input.back();
  }
  Pairs tmp_pairs;
  for (size_t i = 0; i + 1 < input.size(); i += 2) {
    if (input[i] < input[i + 1]) {
      tmp_pairs.push_back(std::pair<int, int>(input[i + 1], input[i]));
    }
    else {
      tmp_pairs.push_back(std::pair<int, int>(input[i], input[i + 1]));
    }
  }
  return tmp_pairs;
}

template<typename Container, typename Pairs>
Container PmergeMe<Container, Pairs>::precalculate_jcbsthal_(Container input)
{
  int threshold = input.size() / 2 + 1;
  Container tmp_jacob;
  tmp_jacob.push_back(2);
  for (int i = 4; tmp_jacob.back() < threshold; ++i) {
    tmp_jacob.push_back((((1 << i) - (i % 2 == 0 ? 1 : -1)) / 3) - 1);
  }
  return tmp_jacob;
}

template<typename Container, typename Pairs>
bool PmergeMe<Container, Pairs>::is_sorted(const Container& vec) const
{
  for (size_t i = 0; i < vec.size() - 1; ++i) {
    if (vec[i] > vec[i + 1]) {
      return false;
    }
  }
  return true;
}

template<typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::print_(const std::string& str, const Container& vec) const
{
  std::cout << str + ":\t";
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
}

template<typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::print_() const
{
  for (size_t i = 0; i < main_.size(); i++) {
    std::cout << main_[i] << " ";
  }
}

template<typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::print_time_() const
{
  std::cout << "Time to process a range of " << main_.size()
            << " elements with ";
  
  if (type_ == VECTOR) {
    std::cout << "std::vector ";
  }
  else if (type_ == DEQUE) {
    std::cout << "std::deque ";
  }
  std::cout << elapsed_ << " μs.\n";
}
