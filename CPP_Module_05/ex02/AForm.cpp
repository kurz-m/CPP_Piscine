#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
  : name_("undefined"), signed_(false), sign_grade_(1), execute_grade_(1) {}

AForm::AForm(
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

AForm::AForm(const AForm& rhs)
  : name_(rhs.name_), signed_(rhs.signed_),
    sign_grade_(rhs.sign_grade_), execute_grade_(rhs.execute_grade_) {}

AForm& AForm::operator=(const AForm& rhs)
{
  if (this != &rhs) {
    signed_ = rhs.signed_;
  }
  return *this;
}

AForm::~AForm() {}

const std::string&  AForm::get_name() const
{
  return name_;
}

const bool&  AForm::get_signature() const
{
  return signed_;
}

const unsigned int&  AForm::get_sign_grade() const
{
  return sign_grade_;
}

const unsigned int&  AForm::get_execute_grade() const
{
  return execute_grade_;
}

void  AForm::be_signed(const Bureaucrat &B)
{
  if (true == signed_) {
    throw AlreadySigned();
  }
  if (B.get_grade() > sign_grade_) {
    throw GradeTooLowException();
  }
  signed_ = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
  return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
  return "Grade is too low!";
}

const char* AForm::AlreadySigned::what() const throw()
{
  return "AForm is already signed!";
}

std::ostream& operator<<(std::ostream& o, const AForm& F)
{
  return o << "Form:\t\t" << F.get_name()
           << "\nSigned?:\t" << F.get_signature()
           << "\nSign grade:\t" << F.get_sign_grade()
           << "\nExec grade:\t" << F.get_execute_grade()
           << std::endl;
}
