#ifndef UTILS_HPP_
# define UTILS_HPP_

#include <iostream>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"  // Brain
#define BLUE "\033[1;34m"   // Animal
#define MAGENTA "\033[1;35m"// Cat
#define CYAN "\033[1;36m"   // Dog
#define GREEN "\033[1;32m"

enum debug_e {
  TEST,
  INFO,
  DEBUG,
  ERROR,
};

void  log_level(const std::string& fmt, debug_e level);

#endif
