#include "ScalarConverter.hpp"
#include <cctype>
#include <sstream>

ScalarConverter::ScalarConverter() 
  : type_(INVALID),
    input_("empty"),
    out_char_(0),
    out_int_(0),
    out_float_(0),
    out_double_(0)
{}

ScalarConverter::ScalarConverter(const std::string& str) 
  : type_(INVALID),
    input_(str),
    out_char_(0),
    out_int_(0),
    out_float_(0),
    out_double_(0)
{}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
  *this = rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void  ScalarConverter::convert(const std::string& str)
{
  ScalarConverter container(str);
}

ScalarConverter::Type  ScalarConverter::get_type()
{
  if (input_.length() == 1 && std::isalpha(input_[0]) != 0) {
    return CHAR;
  }
  std::istringstream  inbuf(input_);
  inbuf >> out_int_;
  if (true == inbuf.fail()) {
    return INVALID;
  }
  else if (true == inbuf.eof()) {
    return INT;
  }
  inbuf.clear();
  inbuf.str(input_);

  return INVALID;
}
