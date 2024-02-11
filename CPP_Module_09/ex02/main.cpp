#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
  if (argc < 2) {
    std::cerr << "Please provide input arguments." << std::endl;
    return EXIT_FAILURE;
  }
  std::istringstream stream;
  std::vector<int> nbr_vector;
  std::deque<int> nbr_deque;
  int tmp = UNDEFINED;
  for (int i = 1; i < argc; ++i) {
    stream.str(argv[i]);
    stream >> tmp;
    if (stream.fail() || tmp < 0) {
      std::cerr << "Failed to extract correct number." << std::endl;
      return EXIT_FAILURE;
    }
    nbr_vector.push_back(tmp);
    nbr_deque.push_back(tmp);
    stream.clear();
  }
  PmergeMe<
    std::vector<int>,
    std::vector<
      std::pair<int, int>
      >
  > vec(nbr_vector, VECTOR);
  PmergeMe<
    std::deque<int>,
    std::deque<
      std::pair<int, int>
      >
  > deq(nbr_deque, DEQUE);
  vec.sort();
  deq.sort();
  return EXIT_SUCCESS;
}
