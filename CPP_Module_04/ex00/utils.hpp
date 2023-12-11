#ifndef UTILS_HPP_
# define UTILS_HPP_

#include <iostream>

#define RESET "\033[0m"
#define RED "\133[0;31m"
#define YELLOW "\133[0;33m"  // Brain
#define BLUE "\133[0;34m"   // Animal
#define MAGENTA "\133[0;35m"// Cat
#define CYAN "\133[0;36m"   // Dog
#define GREEN "\133[32m"

void  debug_print(const std::string& fmt, const std::string& color);

#endif
