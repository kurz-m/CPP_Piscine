#ifndef RPN_HPP_
#define RPN_HPP_

#include <stack>
#include <string>
#include <cctype>
#include <iostream>

class RpnCalculator {
public:
  RpnCalculator(const std::string&);
  ~RpnCalculator();

  void  rpn_calculator();

private:
  RpnCalculator();
  RpnCalculator(const RpnCalculator&);
  RpnCalculator& operator=(const RpnCalculator&);

  bool is_valid_() const;
  void  skip_space_(std::string::const_iterator&);

  std::stack<int> stack_;
  std::string input_;
  char  tmp_value_;
};

#endif
