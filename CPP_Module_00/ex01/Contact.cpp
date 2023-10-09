#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void  Contact::create_new()
{
  const std::string questions[5] = {
    "First name: ",
    "Last name: ",
    "Nickname: ",
    "Phone number: ",
    "Darkest secret: "
  };
  std::string* details_[5] = {
    &first_name_,
    &last_name_,
    &nickname_,
    &phone_number_,
    &darkest_secret_
  };

  std::cout << "|-------------------------------------------|\n|"
              << center_output_("This is the entry mask for a new contact", 43)
            << "|\n"
            << "|" << center_output_("Please insert your details.", 43) << "|\n"
            << "|" << std::string(43, '-') << "|"
            << std::endl;
  for (int i = 0; i < 5; i++) {
    ask_details_(questions[i], *details_[i]);
  }
  std::cout << "|-------------------------------------------|\n"
            << "|" << center_output_(nickname_, 43) << "|\n"
            << "|" << center_output_(" was added to the phonebook", 43) << "|\n"
            << "|" << std::string(43, '-') << "|"
            << std::endl;
}

void  Contact::ask_details_(const std::string ask, std::string& detail_)
{
  std::string input;
  short max_tries = 0;
  bool  done = false;

  while (done == false && max_tries < 5) {
    std::cout << ask;
    std::getline(std::cin, input);
    if (input.empty() == false) {
      detail_ = input;
      done = true;
    }
    else {
      ++max_tries;
      std::cout << "Field cannot be empty, please try again\n"
                << "You have " << 5 - max_tries << " tries left"
                << std::endl;
    }
  }
}

void  Contact::display_details() const
{

  std::cout << "First name: " << first_name_ << '\n'
            << "Last name: " << last_name_ << '\n'
            << "Nickname: " << nickname_ << '\n'
            << "Phone number: " << phone_number_ << '\n'
            << "Darkest secret: " << darkest_secret_
            << std::endl;
}

const std::string   Contact::center_output_(const std::string& out, int width) const
{
  int   padding = width - out.size();
  int   padding_left = padding / 2;
  int   padding_right = padding - padding_left;

  return std::string(padding_left, ' ') + out + std::string(padding_right, ' ');
}

const std::string Contact::get_first_name() const
{
  return first_name_;
}

void  Contact::set_first_name(const std::string first_name)
{
  first_name_ = first_name;
}

const std::string Contact::get_last_name() const
{
  return last_name_;
}

void  Contact::set_last_name(const std::string last_name)
{
  last_name_ = last_name;
}

const std::string Contact::get_nickname() const
{
  return nickname_;
}

void  Contact::set_nickname(const std::string nickname)
{
  nickname_ = nickname;
}

void  Contact::set_phone_number(const std::string phone_number)
{
  phone_number_ = phone_number;
}

void  Contact::set_darkest_secret(const std::string darkest_secret)
{
  darkest_secret_ = darkest_secret;
}
