#include "ScalarConverter.hpp"
#include <cctype>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter() 
  : type_(UNKNOWN),
    input_("empty"),
    out_char_(0),
    out_int_(0),
    out_float_(0),
    out_double_(0),
    overflow_(false)
{}

ScalarConverter::ScalarConverter(const std::string& str) 
  : type_(UNKNOWN),
    input_(str),
    out_char_(0),
    out_int_(0),
    out_float_(0),
    out_double_(0),
    overflow_(false)
{}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
  *this = rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
  if (this != &rhs) {
    *this = rhs;
  }
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void  ScalarConverter::convert(const std::string& str)
{
  ScalarConverter container(str);

  container.find_special_();
  if (UNKNOWN == container.type_) {
    container.find_type_();
  }
  container.print_output_();
}

void  ScalarConverter::find_special_()
{
  if ("nanf" == input_ || "-inff" == input_ ||
      "+inff" == input_ || "inff" == input_) {
    if ("inff" == input_) {
      input_ = "+inff";
    }
    type_ = S_FLOAT;
  }
  else if ("nan" == input_ || "-inf" == input_ ||
      "+inf" == input_ || "inf" == input_) {
    if ("inf" == input_) {
      input_ = "+inf";
    }
    type_ = S_DOUBLE;
  }
}

void ScalarConverter::find_type_()
{
  std::istringstream  inbuf(input_);
  if (input_.length() == 1 && std::isalpha(input_[0]) != 0) {
    inbuf >> out_char_;
    type_ = CHAR;
    return;
  }
  inbuf >> tmp_int_;
  if (true == inbuf.fail()) {
    type_ = INVALID;
    return;
  }
  else if (true == inbuf.eof()) {
    type_ = INT;
    if (tmp_int_ > std::numeric_limits<int>::max()
        || tmp_int_ < std::numeric_limits<int>::min()) {
      overflow_ = true;
    }
    out_int_ = tmp_int_;
    return;
  }
  std::string::reverse_iterator rit = input_.rbegin();
  if (*rit == 'f' || *rit == 'F') {
    inbuf.clear();
    inbuf.str(input_.substr(0, input_.size() - 1));
    inbuf >> out_float_;
    if (true == inbuf.eof()) {
      check_float_ = out_float_;
      if (check_float_ > std::numeric_limits<int>::max()
          || check_float_ < std::numeric_limits<int>::min()) {
        overflow_ = true;
      }
      type_ = FLOAT;
      return;
    }
  }
  inbuf.clear();
  inbuf.str(input_);
  inbuf >> out_double_;
  if (true == inbuf.eof()) {
    check_float_ = out_double_;
    if (check_float_ > std::numeric_limits<int>::max()
        || check_float_ < std::numeric_limits<int>::min()) {
      overflow_ = true;
    }
    type_ = DOUBLE;
    return;
  }
  type_ = INVALID;
}

void  ScalarConverter::print_output_()
{
  switch (type_) {
  case CHAR:
    cast_char_();
    break;
  case INT:
    cast_int_();
    break;
  case FLOAT:
    cast_float_();
    break;
  case DOUBLE:
    cast_double_();
    break;
  case S_FLOAT:
    handle_sfloat_();
    break;
  case S_DOUBLE:
    handle_sdouble_();
    break;
  default:
    throw std::invalid_argument("no valid input argument.");
    break;
  }
}

void  ScalarConverter::cast_char_()
{
  std::cout << "char: '" << out_char_ << "'\n"
            << "int: '" << static_cast<int>(out_char_) << "'\n"
            << std::fixed << std::setprecision(1)
            << "float: '" << static_cast<float>(out_char_) << "f'\n"
            << "double: '" << static_cast<double>(out_char_) << "'"
            << std::endl;
}

void  ScalarConverter::cast_int_()
{
  out_char_ = static_cast<char>(out_int_);
  if (std::isprint(out_char_)) {
    std::cout << "char: '" << out_char_ << "'\n";
  }
  else {
    std::cout << "char: 'Non displayable'\n";
  }
  if (true == overflow_) {
    std::cout << "int: 'overflow'\n";
  }
  else {
    std::cout << "int: '" << out_int_ << "'\n";
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: '" << static_cast<float>(out_int_) << "f'\n"
            << "double: '" << static_cast<double>(out_int_) << "'"
            << std::endl;
}

void  ScalarConverter::cast_float_()
{
  out_char_ = static_cast<char>(out_float_);
  if (std::isprint(out_char_)) {
    std::cout << "char: '" << out_char_ << "'\n";
  }
  else {
    std::cout << "char: 'Non displayable'\n";
  }
  if (true == overflow_) {
    std::cout << "int: 'overflow'\n";
  }
  else {
    std::cout << "int: '" << static_cast<int>(out_float_) << "'\n";
  }
  if (0 == fmod(out_float_, 1.0)) {
    std::cout << std::fixed << std::setprecision(1);
  }
  std::cout << "float: '" << out_float_ << "f'\n"
            << "double: '" << static_cast<double>(out_float_) << "'"
            << std::endl;
}

void  ScalarConverter::cast_double_()
{
  out_char_ = static_cast<char>(out_double_);
  if (std::isprint(out_char_)) {
    std::cout << "char: '" << out_char_ << "'\n";
  }
  else {
    std::cout << "char: 'Non displayable'\n";
  }
  if (true == overflow_) {
    std::cout << "int: 'overflow'\n";
  }
  else {
    std::cout << "int: '" << static_cast<int>(out_double_) << "'\n";
  }
  if (0 == fmod(out_double_, 1.0)) {
    std::cout << std::fixed << std::setprecision(1);
  }
  std::cout << "float: '" << static_cast<float>(out_double_) << "f'\n"
            << "double: '" << out_double_ << "'"
            << std::endl;
}

void  ScalarConverter::handle_sfloat_() const
{
  std::cout << "char: 'impossible'\n"
            << "int: 'impossible'\n"
            << "float: '" << input_ << "'\n"
            << "double: '" << input_.substr(0, input_.size() - 1) << "'"
            << std::endl;
}

void  ScalarConverter::handle_sdouble_() const
{
  std::cout << "char: 'impossible'\n"
            << "int: 'impossible'\n"
            << "float: '" << input_ << "f'\n"
            << "double: '" << input_ << "'"
            << std::endl;
}
