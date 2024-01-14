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

void  log_level_color(const std::string& fmt, const std::string& color, debug_e level)
{
  switch (level) {
    case TEST:
      std::cout << color << "[TEST] " << fmt << RESET << std::endl;
      break;
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
