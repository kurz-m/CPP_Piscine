#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

std::string to_upper(std::string s)
{
  std::string::iterator   it;

  for (it = s.begin(); it != s.end(); it++) {
    *it = std::toupper(static_cast<unsigned char>(*it));
  }
  return s;
}

int main(void)
{
  uint8_t max_tries = 0;
  PhoneBook phonebook;
  std::string input;

  while (42 && max_tries < 5) {
    std::cout << "what do you want?: ";
    std::getline(std::cin, input);
    input = to_upper(input);
    if (input.compare("ADD") == 0) {

    }
    else if (input.compare("SEARCH") == 0) {
      switch (phonebook.show_overview()) {
        case 0:
          break;
        default:
          std::cout << "Choose an index between 1 - 8." << std::endl;
          while (42 && max_tries < 5) {
            std::getline(std::cin, input);
            if (std::atoi(input.c_str()) > 0 && std::atoi(input.c_str()) < 9) {
              phonebook.display_contact(std::atoi(input.c_str()));
            }
          }
          break;
      }
    }
    else if (input.compare("EXIT") == 0) {
      break;
    }
    else {
      ++max_tries;
      std::cout << "Please choose one of the provided options" << std::endl;
      std::cout << "You have " << 5 - max_tries << " tries left" << std::endl;
    }
  }
  return 0;
}
