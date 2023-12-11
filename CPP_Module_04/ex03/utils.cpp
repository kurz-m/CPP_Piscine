#include "utils.hpp"

void  log_level(const std::string& fmt, const std::string& color, debug_t level)
{
  switch (level) {
    case INFO:
      std::cout << color << "[INFO] " << fmt << RESET << std::endl;
      break;
    case DEBUG:
      std::cout << color << "[DEBUG] " << fmt << RESET << std::endl;
      break;
    case ERROR:
      std::cerr << color << "[ERROR] " << fmt << RESET << std::endl;
      break;
  }

}
