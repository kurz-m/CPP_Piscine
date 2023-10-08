#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
public:
  enum {MAX_ENTRY = 8};

  PhoneBook();
  ~PhoneBook();

  void  add_entry();
  int  show_overview() const;
  void  display_contact(int i) const;

private:
  Contact contact_[MAX_ENTRY];
  int index_;
  int entries_;

  void  formatted_entries() const;
};

#endif // PHONEBOOK_HPP_
