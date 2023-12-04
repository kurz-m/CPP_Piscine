#include "utils.hpp"

void  debug_print(const std::string& fmt, const std::string& color)
{
  std::cout << color << fmt << RESET << std::endl;
}
