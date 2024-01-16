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
  void  print_output_();
  void  cast_char_();
  void  cast_int_();
  void  cast_float_();
  void  handle_sfloat_() const;
  void  cast_double_();
  void  handle_sdouble_() const;

  Type        type_;
  std::string input_;
  char        out_char_;
  int         out_int_;
  long        tmp_int_;
  float       out_float_;
  double      out_double_;
  long long   check_float_;
  bool        overflow_;
};

#endif
