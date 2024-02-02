#ifndef RPN_HPP_
#define RPN_HPP_

#include <stack>
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>

#ifndef ADVANCED
#define ADVANCED 0
#endif

#define DELIMITER ' '

class RpnCalculator {
public:
  RpnCalculator(const std::string&);
  ~RpnCalculator();

  void  rpn_calculator();

private:
  RpnCalculator();
  RpnCalculator(const RpnCalculator&);
  RpnCalculator& operator=(const RpnCalculator&);

  bool parse_nbr_(std::string&);

  std::stack<float> stack_;
  std::string input_;
  std::stringstream stream_;
  float  tmp_value_;
};

#endif
