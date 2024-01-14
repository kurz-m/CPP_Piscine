#ifndef AFORM_HPP_
# define AFORM_HPP_

#include <exception>
#include <cstdlib>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
  AForm();
  AForm(const std::string&, bool, unsigned int, unsigned int, const std::string&);
  AForm(const AForm&);
  AForm& operator=(const AForm&);
  virtual ~AForm();

  const std::string& get_name() const;
  const bool& get_signature() const;
  const unsigned int& get_sign_grade() const;
  const unsigned int& get_execute_grade() const;

  void  be_signed(const Bureaucrat& B);
  virtual void  execute(const Bureaucrat&) const = 0;

  class GradeTooHighException: public std::exception {
    virtual const char* what() const throw();
  };
  class GradeTooLowException: public std::exception {
    virtual const char* what() const throw();
  };
  class AlreadySignedException: public std::exception {
    virtual const char* what() const throw();
  };
  class NotSignedException: public std::exception {
    virtual const char* what() const throw();
  };

protected:
  void  check_form_(const Bureaucrat&) const;

  const std::string name_;
  bool  signed_;
  const unsigned int  sign_grade_;
  const unsigned int  execute_grade_;
  std::string target_;
};

std::ostream& operator<<(std::ostream& o, const AForm& F);

#endif
