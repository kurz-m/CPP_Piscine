#include "Contact.hpp"
#include <iostream>

int main(void)
{
  Contact     name;
  std::string input;

  do {
    std::cout << "Please, enter your name: ";
    std::getline(std::cin, input);
    name.set_first_name(input);
    if (input.compare("EXIT") == 0)
      break;
    std::cout << "Hello, " << name.get_first_name() << "!" << std::endl;
  } while(true);


  return 0;
}
