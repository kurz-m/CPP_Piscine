#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <cstddef>
#include <utility>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <deque>

#define UNDEFINED -1

enum ContainerType {
  VECTOR,
  DEQUE
};

template<typename Container, typename Pairs>
class PmergeMe {
public:
  PmergeMe(Container& vec, ContainerType type);
  ~PmergeMe();

  void sort();

private:
  PmergeMe(const PmergeMe& rhs);
  PmergeMe &operator=(const PmergeMe& rhs);

  void merge_core_(Pairs& main);
  void split_pairs_();
  void insert_pend_();
  Pairs create_pairs_(Container input);
  Container precalculate_jcbsthal_(Container input);
  bool is_sorted(const Container& vec);
  void print_(const std::string& str, const Container& vec);
  void print_time_();

  Container main_; // container for holding the main chain
  Pairs pairs_; // container for the initial pairing
  Container pend_; // container for holding the pend chain
  Container jcbsthal_; // container for pre-calculated jacobsthal number
  int leftover_; // int if there is a odd amount of numbers
  int offset_; // offset for inserting via insertion sort
  clock_t start_;
  clock_t end_;
  double elapsed_;
  ContainerType type_;
};

#include "PmergeMe.cpp"

#endif
