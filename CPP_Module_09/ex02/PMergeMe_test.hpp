#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <cstddef>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

#define UNDEFINED -1

// TODO: add 'template <typename Container, typename Pairs>'
// this helps for then templating
template <typename Container, typename Pairs>
class PmergeMe {
public:
  PmergeMe(const Container& vec)
    : main_(vec),
      jcbsthal_(precalculate_jcbsthal_()),
      leftover_(UNDEFINED)
      {
        create_pairs_();
      }
  ~PmergeMe() {}

  void sort()
  {
    merge_core_(pairs_);
    split_pairs_();
  }

private:
  PmergeMe(const PmergeMe& rhs)
  {
    *this = rhs;
  }

  PmergeMe &operator=(const PmergeMe& rhs)
  {
    if (this != &rhs) {
      main_ = rhs.main_;
      pend_ = rhs.pend_;
      leftover_ = rhs.leftover_;
    }
    return *this;
  }

  void merge_core_(Pairs& main)
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

  void split_pairs_()
  {
    typename Pairs::iterator it;
    for (it = pairs_.begin(); it < pairs_.end(); ++it) {
      main_.push_back(it->first);
      pend_.push_back(it->second);
    }
    typename Container::iterator cit;
    for (cit = main_.begin(); cit < main_.end(); ++cit) {
      std::cout << *cit << " ";
    }
    std::cout << std::endl;
  }

  void create_pairs_()
  {
    if (main_.size() % 2 != 0) {
      leftover_ = main_.back();
    }
    for (size_t i = 0; i + 1 < main_.size(); i += 2) {
      if (main_[i] < main_[i + 1]) {
        pairs_.push_back(std::pair<int, int>(main_[i + 1], main_[i]));
      }
      else {
        pairs_.push_back(std::pair<int, int>(main_[i], main_[i + 1]));
      }
    }
    main_.clear();
    // std::vector<std::pair<int, int> >::iterator it;
    // for (it = pend_.begin(); it < pend_.end(); ++it) {
    //   std::cout << "Top:" << it->first << std::endl;
    //   std::cout << "Bottom:" << it->second << std::endl;
    // }
  }

  std::vector<int> precalculate_jcbsthal_()
  {
    size_t threshold = main_.size() / 2 + 1;
    std::vector<int> tmp_jacob;
    for (size_t i = 3; i < threshold; ++i) {
      tmp_jacob.push_back(((1 << i) - (i % 2 == 0 ? 1 : -1)) / 3);
    }
    return tmp_jacob;
  }

  Container main_;
  Pairs pairs_;
  Container pend_;
  Container jcbsthal_;
  int leftover_;
};

#endif
