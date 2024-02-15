#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

#include "PmergeMe.hpp"

template<typename T>
bool arr_is_sorted(const T& arr)
{
  for (size_t i = 0; i < arr.size() - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}

bool handle_vector(int argc, char** argv)
{
  std::istringstream stream;
  std::vector<int> nbr_vector;
  int tmp = UNDEFINED;
  for (int i = 1; i < argc; ++i) {
    stream.str(argv[i]);
    stream >> tmp;
    if (stream.fail() || tmp < 0) {
      std::cerr << "Failed to extract correct number." << std::endl;
      return false;
    }
    nbr_vector.push_back(tmp);
    stream.clear();
  }
  if (arr_is_sorted(nbr_vector) == true) {
    std::cout << "Error: array already sorted" << std::endl;
    return false;
  }
  PmergeMe<
    std::vector<int>,
    std::vector<
      std::pair<int, int>
      >
  > vec(nbr_vector, VECTOR);
  vec.sort();
  return true;
}

bool handle_deque(int argc,char** argv)
{
  std::istringstream stream;
  std::deque<int> nbr_deque;
  int tmp = UNDEFINED;
  for (int i = 1; i < argc; ++i) {
    stream.str(argv[i]);
    stream >> tmp;
    if (stream.fail() || tmp < 0) {
      std::cerr << "Failed to extract correct number." << std::endl;
      return false;
    }
    nbr_deque.push_back(tmp);
    stream.clear();
  }
  if (arr_is_sorted(nbr_deque) == true) {
    std::cout << "Error: array already sorted" << std::endl;
    return false;
  }
  PmergeMe<
    std::deque<int>,
    std::deque<
      std::pair<int, int>
      >
  > deq(nbr_deque, DEQUE);
  deq.sort();
  return true;
}
int main(int argc, char** argv)
{
  if (argc < 2) {
    std::cerr << "Please provide input arguments." << std::endl;
    return EXIT_FAILURE;
  }
  if (handle_vector(argc, argv) == false) {
    return EXIT_FAILURE;
  }
  if (handle_deque(argc, argv) == false) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
