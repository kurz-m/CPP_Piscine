#include "RPN.hpp"
#include <stdexcept>
#include <cstdlib>
#include <sstream>

static const std::string operators("+-*/");

RpnCalculator::RpnCalculator(const std::string& input)
  : input_(input)
{
}

RpnCalculator::RpnCalculator(const RpnCalculator& rhs)
{
  *this = rhs;
}

RpnCalculator& RpnCalculator::operator=(const RpnCalculator& rhs)
{
  if (this != &rhs) {
    input_ = rhs.input_;
  }
  return *this;
}

RpnCalculator::~RpnCalculator() {}

void RpnCalculator::rpn_calculator()
{
  std::string::iterator it;;

  for (it = input_.begin(); it != input_.end(); ++it) {
    if (std::isdigit(*it)) {
      stack_.push(std::atoi(&(*it)));
    }
    else if (operators.find(*it) != std::string::npos) {
      if (stack_.size() < 2) {
        throw std::invalid_argument("Input was not in RPN format.");
      }
      int b = stack_.top();
      stack_.pop();
      int a = stack_.top();
      stack_.pop();
      switch (*it) {
      case '+':
        stack_.push(a + b);
        break;
      case '-':
        stack_.push(a - b);
        break;
      case '*':
        stack_.push(a * b);
        break;
      case '/':
        if (b == 0) {
          throw std::invalid_argument("Cannot divide by 0");
        }
        stack_.push(a / b);
        break;
      }
    }
    else {
      skip_space_(it);
    }
  }
  if (stack_.size() > 1) {
    throw std::logic_error("Not enough mathematical operators for the given numbers");
  }
  std::cout << stack_.top();
}

void RpnCalculator::rpn_calculator_adv()
{
  std::string::iterator it;;

  for (it = input_.begin(); it != input_.end(); ++it) {
    if (parse_nbr_(it, input_.end()) == true) {
      stack_.push(tmp_value_);
    }
    else if (operators.find(*it) != std::string::npos) {
      if (stack_.size() < 2) {
        throw std::invalid_argument("Input was not in RPN format.");
      }
      int b = stack_.top();
      stack_.pop();
      int a = stack_.top();
      stack_.pop();
      switch (*it) {
      case '+':
        stack_.push(a + b);
        break;
      case '-':
        stack_.push(a - b);
        break;
      case '*':
        stack_.push(a * b);
        break;
      case '/':
        if (b == 0) {
          throw std::invalid_argument("Cannot divide by 0");
        }
        stack_.push(a / b);
        break;
      }
    }
    else {
      skip_space_(it);
    }
  }
  if (stack_.size() > 1) {
    throw std::logic_error("Not enough mathematical operators for the given numbers");
  }
  std::cout << stack_.top() << "\n";
}

bool RpnCalculator::parse_nbr_(std::string::iterator& it, const std::string::iterator& eit)
{
  std::istringstream iss(std::string(it, eit));

  iss >> tmp_value_;
  
  if (tmp_value_ < 0 && tmp_value_ > -10) {
    ++it;
  }
  else if (tmp_value_ > 9 || tmp_value_ < -9) {
    throw std::invalid_argument("Numbers are not single digit only.");
  }
  return true;
}

void RpnCalculator::skip_space_(std::string::iterator& it)
{
  if (it != input_.end() && std::isspace(*it) == false) {
    throw std::invalid_argument("You provided a wrong input.");
  }
}
