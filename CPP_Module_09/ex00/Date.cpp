#include "Date.hpp"
#include <sstream>
#include <stdexcept>

Date::Date() : year_(0), month_(0), day_(0) {}

Date::Date(uint year, uint month, uint day)
  : year_(year), month_(month), day_(day) {}

Date::Date(std::string& input)
{
  char dash;
  std::istringstream  stream(input);

  stream >> year_ >> dash >> month_ >> dash >> day_;
  if (is_valid() == false) {
    throw std::out_of_range("Date is not valid");
  }
}

Date::Date(const Date& rhs)
  : year_(rhs.year_), month_(rhs.month_), day_(rhs.day_)
{
  *this = rhs;
}

Date& Date::operator=(const Date& rhs)
{
  if (this != &rhs) {
    year_ = rhs.year_;
    month_ = rhs.month_;
    day_ = rhs.day_;
  }
  return *this;
}

Date::~Date() {}

bool  Date::is_leap_year() const
{
  return year_ % 4 == 0 && (year_ % 100 != 0 || year_ % 400 == 0);
}

bool  Date::is_valid() const
{
  const int days_in_month[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

  if (year_ < 0 || month_ < 1 || month_ > 12) {
    return false;
  }

  uint days = days_in_month[month_];
  if (month_ == 2 && is_leap_year() == true) {
    ++days;
  }

  return day_ >= 1 && day_ <= days;
}

bool  Date::operator<(const Date& rhs) const
{
  if (year_ != rhs.year_) {
    return year_ < rhs.year_;
  }
  if (month_ != rhs.month_) {
    return month_ < rhs.month_;
  }
  return day_ < rhs.day_;
}

std::istream& Date::operator>>(std::istream& stream)
{
  char  dash;
  stream >> year_ >> dash >> month_ >> dash >> day_;
  if (is_valid() == false) {
    throw std::out_of_range("Date is not valid");
  }
  return stream;
}
