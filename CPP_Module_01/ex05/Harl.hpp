#ifndef HARL_HPP_
#define HARL_HPP_

#include <iostream>
#include <string>
#include <cstdlib>

#define LEVELS 4

class   Harl {

public:
  Harl();
  ~Harl();

  void  complain(const std::string level) const;

private:
  void  debug_() const;
  void  info_() const;
  void  warning_() const;
  void  error_() const;
};

#endif
