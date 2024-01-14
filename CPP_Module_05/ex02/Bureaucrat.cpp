#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "utils.hpp"

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
    grade_ = rhs.grade_;
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

void  Bureaucrat::sign_form(AForm& F)
{
  try {
    F.be_signed(*this);
    log_level(std::string(name_ + " signed " + F.get_name()), INFO);
  }
  catch (std::exception &e) {
    log_level(
        std::string(name_ + " couldn't sign " + F.get_name() +
        " because its " + e.what()), INFO);
  }
}

void  Bureaucrat::execute_form(const AForm &F)
{
  try {
    F.execute(*this);
    log_level(std::string(name_ + " executed " + F.get_name()), INFO);
  }
  catch (std::exception &e) {
    log_level(
        std::string(name_ + " couldn't execute " + F.get_name() +
        " because its " + e.what()), INFO);
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& B)
{
  return o << "Bureaucrat: " << B.get_name()
           << " has the bureaucratic grade: " << B.get_grade() << std::endl;
}
