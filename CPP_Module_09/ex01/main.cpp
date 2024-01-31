#include "RPN.hpp"
#include <cstdlib>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Usage: ./RPN 1 2 +\n";
  }
  else {
    RpnCalculator rpn(argv[1]);
    try {
      if (ADVANCED == 0) {
        rpn.rpn_calculator();
      }
      else {
        rpn.rpn_calculator_adv();
      }
    }
    catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
  return EXIT_SUCCESS;
}
