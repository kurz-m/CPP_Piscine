#ifndef FORM_HPP_
# define FORM_HPP_

#include <exception>
#include <cstdlib>
#include <iostream>
#include <string>

class Form {
public:
  Form();
  Form(const std::string&, unsigned int);
  Form(const Form&);
  Form& operator=(const Form&);
  ~Form();

  const std::string& get_name() const;

  class GradeTooHighException: public std::exception {
    virtual const char* what() const throw();
  };
  class GradeTooLowException: public std::exception {
    virtual const char* what() const throw();
  };

private:
  const std::string name_;
  bool  signed_;
  const unsigned int  sign_grade_;
  const unsigned int  execute_grade_;
};

#endif
