#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
  : literal_type_(INVALID),
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

static int  ScalarConverter::convert(const std::string& str)
{
  ScalarConverter container;
}
