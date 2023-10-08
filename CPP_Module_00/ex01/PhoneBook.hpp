#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
public:
  enum {MAX_ENTRY = 8};

  PhoneBook();
  ~PhoneBook();

  void  add_entry();
  int get_entries() const;
  void  display_contact(int entry) const;
  int show_overview() const;

private:
  Contact contacts_[MAX_ENTRY];
  int index_;
  int entries_;

  void  formatted_entries_() const;
  const std::string format_(const std::string entry) const;
};

#endif // PHONEBOOK_HPP_
