#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : entries_(0)
{
  return;
}

PhoneBook::~PhoneBook(void)
{
  return;
}

void  PhoneBook::add_entry()
{
  
}

int  PhoneBook::show_overview() const
{
  switch (entries_) {
    case 0:
      std::cout << "The phonebook has no entries to search through." << std::endl;
      return false;
    default:
      formatted_entries();
      return true;;
  }
}

void  PhoneBook::display_contact(int i) const
{
  Contact contact(contact_[i]);
}


