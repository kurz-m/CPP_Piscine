#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>

#include "PMergeMe_test.hpp"

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "Please provide input arguments." << std::endl;
  }
  std::istringstream stream;
  std::vector<int> nbr_vector;
  int tmp = UNDEFINED;
  for (int i = 1; i < argc; ++i) {
    stream.str(argv[i]);
    stream >> tmp;
    if (stream.fail() || tmp < 0) {
      std::cerr << "Failed to extract correct number." << std::endl;
      return EXIT_FAILURE;
    }
    stream.clear();
    nbr_vector.push_back(tmp);
  }
  PmergeMe vec(nbr_vector);
  vec.sort();
  return 0;
}