#ifndef SCALARCONVERTER_HPP_
# define SCALARCONVERTER_HPP_

#include <string>

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
  static int  convert(const std::string&);
  ~ScalarConverter();

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);

  Type    literal_type_;
  char    out_char_;
  int     out_int_;
  float   out_float_;
  double  out_double_;
};

#endif
