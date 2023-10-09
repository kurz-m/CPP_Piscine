#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
public:
  Contact(void);
  ~Contact(void);

  void  create_new();
  void  display_details() const;

  void  set_first_name(const std::string first_name);
  const std::string get_first_name() const;
  void  set_last_name(const std::string last_name);
  const std::string get_last_name() const;
  void  set_nickname(const std::string nickname);
  const std::string get_nickname() const;
  void  set_phone_number(const std::string phone_number);
  void  set_darkest_secret(const std::string darkest_secret);

private:
  std::string   first_name_;
  std::string   last_name_;
  std::string   nickname_;
  std::string   phone_number_;
  std::string   darkest_secret_;

  const std::string center_output_(const std::string& out, int width) const;
  void  reset_input_(std::string& input, short& max_tries);
  void  ask_details_(const std::string ask, std::string& detail);
};

#endif // CONTACT_HPP_
