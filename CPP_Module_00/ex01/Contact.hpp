#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <string>

class Contact {
public:
  Contact(void);
  Contact(const Contact& contact);
  ~Contact(void);

  void  create_new(Contact& contact);

  void  set_first_name(std::string first_name);
  void  set_last_name(std::string last_name);
  void  set_nickname(std::string nickname);
  void  set_phone_number(std::string phone_number);
  void  set_darkest_secret(std::string darkest_secret);

private:
  std::string   first_name_;
  std::string   last_name_;
  std::string   nickname_;
  std::string   phone_number_;
  std::string   darkest_secret_;
};

#endif // CONTACT_HPP_
