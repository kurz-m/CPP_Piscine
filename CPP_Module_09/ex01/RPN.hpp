#ifndef RPN_HPP_
#define RPN_HPP_

#include <stack>
#include <string>
#include <cctype>
#include <iostream>

#ifndef ADVANCED
#define ADVANCED 0
#endif

class RpnCalculator {
public:
  RpnCalculator(const std::string&);
  ~RpnCalculator();

  void  rpn_calculator();
  void  rpn_calculator_adv();

private:
  RpnCalculator();
  RpnCalculator(const RpnCalculator&);
  RpnCalculator& operator=(const RpnCalculator&);

  bool parse_nbr_(std::string::iterator&, const std::string::iterator&);
  void  skip_space_(std::string::iterator&);

  std::stack<int> stack_;
  std::string input_;
  int  tmp_value_;
};

#endif
