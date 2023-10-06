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

  void  complain(std::string level);

private:
  int   complain_level_;

  void  debug_();
  void  info_();
  void  warning_();
  void  error_();
  void  filter_();
};

#endif
