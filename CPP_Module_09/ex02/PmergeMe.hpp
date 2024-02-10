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
    : main_(vec),
      jcbsthal_(precalculate_jcbsthal_()),
      leftover_(UNDEFINED),
      offset_(0)
      {
        create_pairs_();
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
    for (it = jcbsthal_.begin(); it != jcbsthal_.end(); ++it) {

    }
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

  std::vector<int> main_; // container for holding the main chain
  std::vector<std::pair<int, int> > pairs_; // container for the initial pairing
  std::vector<int> pend_; // container for holding the pend chain
  std::vector<int> jcbsthal_; // container for pre-calculated jacobsthal number
  int leftover_; // int if there is a odd amount of numbers
  int offset_; // offset for inserting via insertion sort
};

#endif
