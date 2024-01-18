#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
  if (2 == argc) {
    try {
      ScalarConverter::convert(argv[1]);
    }
    catch (const std::invalid_argument& e) {
      std::cerr << "Program recieved " << e.what() << std::endl;
    }
  }
  return EXIT_SUCCESS;
}
