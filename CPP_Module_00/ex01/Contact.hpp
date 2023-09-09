#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <string>

class Contact {
public:
  Contact(void);
  ~Contact(void);

  std::string get_first_name(void) const;
  void   set_first_name(std::string first_name);

  std::string get_last_name(void) const;
  void  set_last_name(std::string last_name);

  std::string get_nickname(void) const;
  void  set_nickname(std::string nickname);

  std::string get_phone_number(void) const;
  void  set_phone_number(std::string phone_number);

  std::string get_darkest_secret(void) const;
  void  set_darkest_secret(std::string darkest_secret);

private:
  std::string   first_name_;
  std::string   last_name_;
  std::string   nickname_;
  std::string   phone_number_;
  std::string   darkest_secret_;
};

#endif // CONTACT_HPP_
