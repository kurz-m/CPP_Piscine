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
  short max_tries = 0;
  PhoneBook phonebook;
  std::string input;

  std::cout << "Welcome to my awesome phonebook\n"
            << "Please enter one of the following options:\n"
            << "ADD | SEARCH | EXIT"
            << std::endl;
  while (42 && max_tries < 5) {
    std::getline(std::cin, input);
    input = to_upper(input);
    if (input.compare("ADD") == 0) {
      phonebook.add_entry();
      max_tries = 0;
    }
    else if (input.compare("SEARCH") == 0) {
      switch (phonebook.show_overview()) {
        case 0:
          break;
        default:
          std::cout << "Choose an index between 1 - " << phonebook.get_entries()
                    << "." << std::endl;
          while (42) {
            std::getline(std::cin, input);
            if (std::atoi(input.c_str()) > 0
                && std::atoi(input.c_str()) <= phonebook.get_entries()) {
              phonebook.display_contact(std::atoi(input.c_str()));
              max_tries = 0;
            }
            else {
              ++max_tries;
              if (max_tries == 5) {
                max_tries = 0;
                break;
              }
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
      std::cout << "Please choose one of the provided options\n"
                << "You have " << 5 - max_tries << " tries left"
                << std::endl;
    }
  }
  return 0;
}
