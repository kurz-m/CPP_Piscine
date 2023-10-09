#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : index_(0), entries_(0) {}

PhoneBook::~PhoneBook(void) {}

void  PhoneBook::add_entry()
{
  if (index_ == 8) {
    index_ = 0;
  }
  contacts_[index_].create_new();
  ++index_;
  if (entries_ < 8) {
    ++entries_;
  }
}

int PhoneBook::get_entries() const
{
  return entries_;
}

void  PhoneBook::display_contact(int entry) const
{
  const Contact&  contact = contacts_[entry - 1];

  contact.display_details();
}

int  PhoneBook::show_overview() const
{
  switch (entries_) {
    case 0:
      std::cout << "The phonebook has no entries to display." << std::endl;
      return false;
    default:
      formatted_entries_();
      return true;;
  }
}

void  PhoneBook::formatted_entries_() const
{
  std::cout << "|-------------------------------------------|\n" << std::right
            << "|" << std::setw(10) << "index" << "|"
            << std::setw(10) << "first name" << "|"
            << std::setw(10) << "last name" << "|"
            << std::setw(10) << "nickname" << "|\n"
            << "|-------------------------------------------|"
            << std::endl;
  for (int i = 0; i < entries_; i++) {
    std::cout << std::right
              << "|" << std::setw(10) << i + 1 << "|"
              << std::setw(10) << format_(contacts_[i].get_first_name()) << "|"
              << std::setw(10) << format_(contacts_[i].get_last_name()) << "|"
              << std::setw(10) << format_(contacts_[i].get_nickname()) << "|"
              << std::endl;
  }
  std::cout << "|-------------------------------------------|" << std::endl;
}

const std::string PhoneBook::format_(const std::string entry) const
{
  if (entry.length() > 10) {
    return entry.substr(0, 9) + ".";
  }
  return entry;
}
