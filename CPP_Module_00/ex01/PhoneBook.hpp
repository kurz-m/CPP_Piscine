#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <iostream>
#include "Contact.hpp"

#define MAX_ENTRY 8

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();

private:
  Contact contact_[MAX_ENTRY];
  int     index_;
};

#endif // PHONEBOOK_HPP_
