#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <cstddef>
#define UNDEFINED -1

#include <vector>

class PmergeMe {
public:
  PmergeMe(const std::vector<int>& vec)
    : internal_(vec),
      jcbsthal_(precalculate_jcbsthal()),
      leftover_(UNDEFINED)
      {
        pend_.reserve(vec.size());
      }
  ~PmergeMe() {}

  void create_pairs()
  {
    if (internal_.size() % 2 != 0) {
      leftover_ = internal_.back();
    }
    for (size_t i = 0; i + 1 < internal_.size(); i += 2) {
      if (internal_[i] < internal_[i + 1]) {
        pend_.push_back(std::pair<int, int>(internal_[i + 1], internal_[i]));
      }
      else {
        pend_.push_back(std::pair<int, int>(internal_[i], internal_[i + 1]));
      }
    }
  }

private:
  PmergeMe(const PmergeMe& rhs)
  {
    *this = rhs;
  }

  PmergeMe &operator=(const PmergeMe& rhs)
  {
    if (this != &rhs) {
      internal_ = rhs.internal_;
      pend_ = rhs.pend_;
      leftover_ = rhs.leftover_;
    }
    return *this;
  }


  std::vector<int> precalculate_jcbsthal()
  {
    size_t threshold = internal_.size() / 2 + 1;
    std::vector<int> tmp_jacob;
    for (size_t i = 3; i < threshold; ++i) {
      tmp_jacob.push_back(((1 << i) - (i % 2 == 0 ? 1 : -1)) / 3);
    }
    return tmp_jacob;
  }


  std::vector<int> internal_;
  std::vector<std::pair<int, int> > pend_;
  std::vector<int> jcbsthal_;
  int leftover_;
};

#endif
