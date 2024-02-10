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
class PmergeMe {
public:
  PmergeMe(const std::vector<int>& vec)
    : pairs_(create_pairs_(vec)),
      jcbsthal_(precalculate_jcbsthal_(vec)),
      offset_(1)
  {
    main_.reserve(vec.size() + 3);
    pend_.reserve(vec.size() + 3);
  }
  ~PmergeMe() {}

  void sort()
  {
    merge_core_(pairs_);
    split_pairs_();
    insert_pend_();
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
      pairs_ = rhs.pairs_;
      pend_ = rhs.pend_;
      leftover_ = rhs.leftover_;
      offset_ = rhs.offset_;
    }
    return *this;
  }

  void merge_core_(std::vector<std::pair<int, int> >& main)
  {
    if (main.size() <= 1)
      return;

    size_t mid = main.size() / 2;
    std::vector<std::pair<int, int> > left(main.begin(), main.begin() + mid);
    std::vector<std::pair<int, int> > right(main.begin() + mid, main.end());

    merge_core_(left);
    merge_core_(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), main.begin());
  }

  void split_pairs_()
  {
    std::vector<std::pair<int, int> >::iterator it;
    main_.push_back(pairs_.at(0).second);
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

  void insert_pend_()
  {
    std::vector<int>::iterator it;
    int prev_jcb = 0;
    for (it = jcbsthal_.begin(); it != jcbsthal_.end(); ++it) {
      int i = *it;
      if (i > static_cast<int>(pend_.size() - 1)) {
        i = pend_.size() - 1;
      }
      while (i > prev_jcb) {
        int to_insert = pend_.at(i);
        std::vector<int>::iterator pos = std::lower_bound(main_.begin(),
            main_.begin() + i + offset_, to_insert);
        main_.insert(pos, to_insert);
        ++offset_;
        --i;
      }
      prev_jcb = *it;
    }
  }

  std::vector<std::pair<int, int> > create_pairs_(std::vector<int> input)
  {
    if (input.size() % 2 != 0) {
      leftover_ = input.back();
    }
    std::vector<std::pair<int, int> > tmp_pairs;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
      if (input[i] < input[i + 1]) {
        tmp_pairs.push_back(std::pair<int, int>(input[i + 1], input[i]));
      }
      else {
        tmp_pairs.push_back(std::pair<int, int>(input[i], input[i + 1]));
      }
    }
    // std::vector<std::pair<int, int> >::iterator it;
    // for (it = tmp_pairs.begin(); it < tmp_pairs.end(); ++it) {
    //   std::cout << "Top:" << it->first << std::endl;
    //   std::cout << "Bottom:" << it->second << std::endl;
    // }
    return tmp_pairs;
  }

  std::vector<int> precalculate_jcbsthal_(std::vector<int> input)
  {
    int threshold = input.size() / 2 + 1;
    std::vector<int> tmp_jacob;
    tmp_jacob.push_back(2);
    for (int i = 4; tmp_jacob.back() < threshold; ++i) {
      tmp_jacob.push_back((((1 << i) - (i % 2 == 0 ? 1 : -1)) / 3) - 1);
    }
    for (std::vector<int>::iterator it = tmp_jacob.begin(); it != tmp_jacob.end(); ++it) {
      std::cout << *it << std::endl;
    }
    return tmp_jacob;
  }

  std::vector<int> main_; // container for holding the main chain
  std::vector<std::pair<int, int> > pairs_; // container for the initial pairing
  std::vector<int> pend_; // container for holding the pend chain
  std::vector<int> jcbsthal_; // container for pre-calculated jacobsthal number
  int leftover_; // int if there is a odd amount of numbers
  int offset_; // offset for inserting via insertion sort
};

#endif
