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
  };

  static void convert(const std::string&);

  ~ScalarConverter();

private:
  ScalarConverter();
  ScalarConverter(const std::string&);
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);

  Type  get_type();
  void  from_char();
  void  from_int();
  void  from_float();
  void  from_double();

  Type        type_;
  std::string input_;
  char        out_char_;
  int         out_int_;
  float       out_float_;
  double      out_double_;
};

#endif
