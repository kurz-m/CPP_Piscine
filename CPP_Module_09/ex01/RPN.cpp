#include "RPN.hpp"
#include <stdexcept>
#include <cstdlib>

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
  std::string::const_iterator it;;

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

void RpnCalculator::skip_space_(std::string::const_iterator& it)
{
  if (it != input_.end() && std::isspace(*it) == false) {
    throw std::invalid_argument("You provided a wrong input.");
  }
}

bool RpnCalculator::is_valid_() const
{
  return stack_.size() > 1;
}
