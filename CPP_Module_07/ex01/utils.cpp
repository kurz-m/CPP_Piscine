#include "utils.hpp"

void  log_level(const std::string& fmt, debug_e level)
{
  switch (level) {
    case TEST:
      std::cout << CYAN << "[TEST] " << fmt << RESET << std::endl;
      break;
    case INFO:
      std::cout << YELLOW << "[INFO] " << fmt << RESET << std::endl;
      break;
    case DEBUG:
      std::cout << MAGENTA << "[DEBUG] " << fmt << RESET << std::endl;
      break;
    case ERROR:
      std::cerr << RED << "[ERROR] " << fmt << RESET << std::endl;
      break;
  }
}
