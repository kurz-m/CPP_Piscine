#include "RPN.hpp"
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#include <sstream>

static const std::string operators("+-*/");

RpnCalculator::RpnCalculator(const std::string& input)
  : input_(input) {}

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
  std::string buffer;
  std::stringstream stream(input_);

  while (std::getline(stream, buffer, DELIMITER)) {
    if (parse_nbr_(buffer) == true) {
      stack_.push(tmp_value_);
    }
    else if (operators.find(buffer) != std::string::npos) {
      if (stack_.size() < 2) {
        throw std::invalid_argument("Input was not in RPN format.");
      }
      int b = stack_.top();
      stack_.pop();
      int a = stack_.top();
      stack_.pop();
      switch (buffer[0]) {
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
  }
  if (stack_.size() > 1) {
    throw std::logic_error("Not enough mathematical operators for the given numbers");
  }
  std::cout << stack_.top() << "\n";
}

bool RpnCalculator::parse_nbr_(std::string& nbr)
{
  std::istringstream stream(nbr);

  stream >> tmp_value_;
  if (stream.fail() == true) {
    return false;
  }
  return true;
}
