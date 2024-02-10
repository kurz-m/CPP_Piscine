#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <cstddef>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#define UNDEFINED -1


class PmergeMe {
public:
  PmergeMe(const std::vector<int>& vec)
    : main_(vec),
      jcbsthal_(precalculate_jcbsthal_()),
      leftover_(UNDEFINED)
      {
        create_pairs_();
      }
  ~PmergeMe() {}

  void sort()
  {
    merge_core_(pend_, 0, pend_.size() - 1);
    std::vector<std::pair<int, int> >::iterator it;
    for (it = pend_.begin(); it < pend_.end(); ++it) {
      std::cout << "Top:" << it->first << std::endl;
      std::cout << "Bottom:" << it->second << std::endl;
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
      main_ = rhs.main_;
      pend_ = rhs.pend_;
      leftover_ = rhs.leftover_;
    }
    return *this;
  }

  // void mergeSort(std::vector<int>& arr, int start, int end) {
  //     if (start < end) { // Base case: subarray with 1 or fewer elements is already sorted
  //         int mid = start + (end - start) / 2;

  //         // Recursively sort the left and right subarrays
  //         mergeSort(arr, start, mid);
  //         mergeSort(arr, mid + 1, end);

  //         // Merge the sorted subarrays using std::merge
  //         std::merge(arr.begin() + start, arr.begin() + mid + 1,
  //                   arr.begin() + mid + 1, arr.begin() + end + 1);
  //     }
  // }

  void merge_core_(std::vector<std::multimap<int, int> >& main, int start, int end)
  {
    if (start < end) {
      int mid = start + (end - start) / 2;

      merge_core_(main, start, mid);
      merge_core_(main, mid + 1, end);
      std::merge(main.begin() + start, main.begin() + mid + 1,
        main.begin() + mid + 1, main.begin() + end + 1);
    }
  }

  static bool comp_pair_(const std::pair<int, int>& a, const std::pair<int, int>& b)
  {
      return a.first < b.first;
  }

  void create_pairs_()
  {
    if (main_.size() % 2 != 0) {
      leftover_ = main_.back();
    }
    for (size_t i = 0; i + 1 < main_.size(); i += 2) {
      if (main_[i] < main_[i + 1]) {
        pend_.push_back(std::multimap<int, int>(main_[i + 1], main_[i]));
      }
      else {
        pend_.push_back(std::multimap<int, int>(main_[i], main_[i + 1]));
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

  std::vector<int> main_;
  std::vector<std::multimap<int, int> > pend_;
  std::vector<int> jcbsthal_;
  int leftover_;
};

#endif
