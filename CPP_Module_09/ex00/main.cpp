#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Usage: ./btc <inputfile>" << std::endl;
    return EXIT_FAILURE;
  }
  const std::string& input = std::string(argv[1]);
  BitcoinExchange btc;

  btc.read_input(input);

  return EXIT_SUCCESS;
}
