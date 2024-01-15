#ifndef SCALARCONVERTER_HPP_
# define SCALARCONVERTER_HPP_

#include <string>
#include <cstdlib>
#include <iostream>

class ScalarConverter {
public:
  enum  Type {
    CHAR,
    INT,
    FLOAT,
    S_FLOAT,
    DOUBLE,
    S_DOUBLE,
    INVALID,
    UNKNOWN,
  };

  static void convert(const std::string&);

  ~ScalarConverter();

private:
  ScalarConverter();
  ScalarConverter(const std::string&);
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);

  void  find_type_();
  void  find_special_();
  void  from_char_();
  void  from_int_();
  void  from_float_();
  void  from_double_();

  Type        type_;
  std::string input_;
  char        out_char_;
  int         out_int_;
  float       out_float_;
  double      out_double_;
};

#endif
