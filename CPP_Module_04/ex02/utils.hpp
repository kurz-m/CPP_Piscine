#ifndef UTILS_HPP_
# define UTILS_HPP_

#include <iostream>

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"  // Brain
#define BLUE "\033[0;34m"   // Animal
#define MAGENTA "\033[0;35m"// Cat
#define CYAN "\033[0;36m"   // Dog
#define GREEN "\033[32m"

void  debug_print(const std::string& fmt, const std::string& color);

#endif
