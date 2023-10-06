#include "Harl.hpp"

std::string to_upper(std::string s)
{
  std::string::iterator   it;

  for (it = s.begin(); it != s.end(); it++) {
    *it = std::toupper(static_cast<unsigned char>(*it));
  }
  return s;
}

int main(int argc, char* argv[])
{
  if (argc != 2) {
    std::cout << "Usage: ./harl <DEBUG|INFO|WARNING|ERROR>" << std::endl;
    return EXIT_FAILURE;
  }
  Harl  harl;
  harl.complain(to_upper(argv[1]));

  return EXIT_SUCCESS;
}
