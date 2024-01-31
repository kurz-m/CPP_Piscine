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
  else {
    std::cerr << "Usage: ./scalarconverter [argument]" << std::endl;
  }
  return EXIT_SUCCESS;
}
