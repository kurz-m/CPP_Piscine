#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(const Contact& contact)
{
  first_name_ = contact.first_name_;
  last_name_ = contact.last_name_;
  nickname_ = contact.nickname_;
  phone_number_ = contact.phone_number_;
  darkest_secret_ = contact.darkest_secret_;
}

Contact::~Contact(void) {}

void  Contact::set_first_name(std::string first_name)
{
  first_name_ = first_name;
}

void  Contact::set_last_name(std::string last_name)
{
  last_name_ = last_name;
}

void  Contact::set_nickname(std::string nickname)
{
  nickname_ = nickname;
}

void  Contact::set_phone_number(std::string phone_number)
{
  phone_number_ = phone_number;
}

void  Contact::set_darkest_secret(std::string darkest_secret)
{
  darkest_secret_ = darkest_secret;
}
