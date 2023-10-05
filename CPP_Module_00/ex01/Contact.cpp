#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::get_first_name(void) const
{
  return first_name_;
}

void  Contact::set_first_name(std::string first_name)
{
  first_name_ = first_name;
}

std::string Contact::get_last_name(void) const
{
  return last_name_;
}

void  Contact::set_last_name(std::string last_name)
{
  last_name_ = last_name;
}

std::string Contact::get_nickname(void) const
{
  return nickname_;
}

void  Contact::set_nickname(std::string nickname)
{
  nickname_ = nickname;
}

std::string Contact::get_phone_number(void) const
{
  return phone_number_;
}

void  Contact::set_phone_number(std::string phone_number)
{
  phone_number_ = phone_number;
}

std::string Contact::get_darkest_secret(void) const
{
  return darkest_secret_;
}

void  Contact::set_darkest_secret(std::string darkest_secret)
{
  darkest_secret_ = darkest_secret;
}
