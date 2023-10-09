#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

static const std::string   center_output(const std::string& out, int width)
{
  int   padding = width - out.size();
  int   padding_left = padding / 2;
  int   padding_right = padding - padding_left;

  return std::string(padding_left, ' ') + out + std::string(padding_right, ' ');
}

static std::string to_upper(std::string s)
{
  std::string::iterator   it;

  for (it = s.begin(); it != s.end(); it++) {
    *it = std::toupper(static_cast<unsigned char>(*it));
  }
  return s;
}

static void    search_action(const PhoneBook& phonebook)
{
  std::string   input;
  std::stringstream info;
  int   max_tries = 0;

  switch (phonebook.show_overview()) {
    case 0:
      break;
    default:
      info << "Choose an index between 1 - " << phonebook.get_entries();
      std::cout << "\n|" << std::string(43, '-') << "|\n"
                << "|" << center_output(info.str(), 43) << "|\n"
                << "|" << std::string(43, '-') << "|"
                << std::endl;
      while (42 && max_tries < 5) {
        std::getline(std::cin, input);
        if (std::atoi(input.c_str()) > 0
            && std::atoi(input.c_str()) <= phonebook.get_entries()) {
      std::cout << "\n|" << std::string(43, '-') << "|\n"
                << "|" << center_output("Phonebook entry:", 43) << "|\n"
                << "|" << std::string(43, '-') << "|"
                << std::endl;
          phonebook.display_contact(std::atoi(input.c_str()));
          break;
        }
        else if (input.compare("quit") == 0) {
          break;
        }
        else {
          info.str("");
          info.clear();
          ++max_tries;
          info << input << " is not a valid index";
          std::cout << center_output(info.str(), 45) << std::endl;
        }
      }
      break;
  }
}

int main(void)
{
  short max_tries = 0;
  PhoneBook phonebook;
  std::string   input;

  std::cout << "#############################################\n"
            << "       Welcome to my awesome phonebook       \n"
            << std::endl;
  while (42 && max_tries < 5) {
    std::cout << "|-------------------------------------------|\n"
              << "| Please enter one of the following options:|\n"
              << "|            ADD | SEARCH | EXIT            |\n"
              << "|-------------------------------------------|"
              << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      return EXIT_FAILURE;
    }
    input = to_upper(input);
    if (input.compare("ADD") == 0) {
      phonebook.add_entry();
      max_tries = 0;
    }
    else if (input.compare("SEARCH") == 0) {
      search_action(phonebook);
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
