#ifndef FORM_HPP_
# define FORM_HPP_

#include <exception>
#include <cstdlib>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
  Form();
  Form(const std::string&, bool, unsigned int, unsigned int);
  Form(const Form&);
  Form& operator=(const Form&);
  ~Form();

  const std::string& get_name() const;
  const bool& get_signature() const;
  const unsigned int& get_sign_grade() const;
  const unsigned int& get_execute_grade() const;

  void  be_signed(const Bureaucrat& B);

  class GradeTooHighException: public std::exception {
    virtual const char* what() const throw();
  };
  class GradeTooLowException: public std::exception {
    virtual const char* what() const throw();
  };
  class AlreadySigned: public std::exception {
    virtual const char* what() const throw();
  };

private:
  const std::string name_;
  bool  signed_;
  const unsigned int  sign_grade_;
  const unsigned int  execute_grade_;
};

std::ostream& operator<<(std::ostream& o, const Form& F);

#endif
