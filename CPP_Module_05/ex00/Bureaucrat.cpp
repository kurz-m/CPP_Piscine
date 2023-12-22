#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("no_name"), grade_(1) {}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade)
  : name_(name), grade_(grade)
{
  if (grade > 150) {
    throw GradeTooLowException();
  }
  else if (grade < 1) {
    throw GradeTooHighException();
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
  : name_(rhs.name_), grade_(rhs.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
  if (this != &rhs) {
    *this = rhs;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string&  Bureaucrat::get_name() const
{
  return name_;
}

unsigned int  Bureaucrat::get_grade() const
{
  return grade_;
}

void  Bureaucrat::improve_grade()
{
  if (grade_ == 1) {
    throw GradeTooHighException();
  }
  --grade_;
}

void  Bureaucrat::lower_grade()
{
  if (grade_ == 150) {
    throw GradeTooLowException();
  }
  ++grade_;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return "grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return "grade is too low!";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& B)
{
  return o << "Bureaucrat: " << B.get_name()
           << " has the bureaucratic grade: " << B.get_grade() << std::endl;
}
