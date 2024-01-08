#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
  : name_("undefined"), signed_(false), sign_grade_(1), execute_grade_(1) {}

Form::Form(
    const std::string& name,
    bool signature,
    unsigned int sign_grade,
    unsigned int execute_grade)
  : name_(name), signed_(signature),
    sign_grade_(sign_grade), execute_grade_(execute_grade)
{
  if (sign_grade_ > 150 || execute_grade_ > 150) {
    throw GradeTooLowException();
  }
  if (sign_grade_ < 1 || execute_grade_ < 1) {
    throw GradeTooHighException();
  }
}

Form::Form(const Form& rhs)
  : name_(rhs.name_), signed_(rhs.signed_),
    sign_grade_(rhs.sign_grade_), execute_grade_(rhs.execute_grade_) {}

Form& Form::operator=(const Form& rhs)
{
  if (this != &rhs) {
    signed_ = rhs.signed_;
  }
  return *this;
}

Form::~Form() {}

const std::string&  Form::get_name() const
{
  return name_;
}

const bool&  Form::get_signature() const
{
  return signed_;
}

const unsigned int&  Form::get_sign_grade() const
{
  return sign_grade_;
}

const unsigned int&  Form::get_execute_grade() const
{
  return execute_grade_;
}

void  Form::be_signed(const Bureaucrat &B)
{
  if (true == signed_) {
    throw AlreadySigned();
  }
  if (B.get_grade() > sign_grade_) {
    throw GradeTooLowException();
  }
  signed_ = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
  return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
  return "Grade is too low!";
}

const char* Form::AlreadySigned::what() const throw()
{
  return "Form is already signed!";
}

std::ostream& operator<<(std::ostream& o, const Form& F)
{
  return o << "Form:\t\t" << F.get_name()
           << "Signed?:\t\t" << F.get_signature()
           << "Sign grade:\t\t" << F.get_sign_grade()
           << "Exec grade:\t\t" << F.get_execute_grade()
           << std::endl;
}
