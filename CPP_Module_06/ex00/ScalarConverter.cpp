#include "ScalarConverter.hpp"
#include <cctype>
#include <sstream>

ScalarConverter::ScalarConverter() 
  : type_(UNKNOWN),
    input_("empty"),
    out_char_(0),
    out_int_(0),
    out_float_(0),
    out_double_(0)
{}

ScalarConverter::ScalarConverter(const std::string& str) 
  : type_(UNKNOWN),
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

  container.find_type_();
}

void ScalarConverter::find_type_()
{
  find_special_();
  if (UNKNOWN != type_) {
    return;
  }
  if (input_.length() == 1 && std::isalpha(input_[0]) != 0) {
    type_ = CHAR;
    return;
  }
  std::istringstream  inbuf(input_);
  inbuf >> out_int_;
  if (true == inbuf.fail()) {
    type_ = INVALID;
    return;
  }
  else if (true == inbuf.eof()) {
    type_ = INT;
    return;
  }
  inbuf.clear();
  inbuf.str(input_);
  inbuf >> out_double_;
  if (true == inbuf.eof()) {
    type_ = DOUBLE;
    return;
  }
  inbuf.clear();
  inbuf.str(input_);
  inbuf >> out_float_;
  char  leftover;
  inbuf >> leftover;
  if (true == inbuf.eof() && ('f' == leftover || 'F' == leftover)) {
    type_ = FLOAT;
    return;
  }
  type_ = INVALID;
}
