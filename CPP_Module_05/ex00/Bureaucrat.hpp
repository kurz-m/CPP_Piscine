#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

#include <exception>
#include <cstdlib>
#include <iostream>
#include <string>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const std::string&, unsigned int);
  Bureaucrat(const Bureaucrat&);
  Bureaucrat& operator=(const Bureaucrat&);
  ~Bureaucrat();

  const std::string& get_name() const;
  unsigned int  get_grade() const;
  void  improve_grade();
  void  lower_grade();

  class GradeTooHighException: public std::exception {
    virtual const char* what() const throw();
  };
  class GradeTooLowException: public std::exception {
    virtual const char* what() const throw();
  };

private:
  const std::string name_;
  unsigned int  grade_;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& B);

#endif
