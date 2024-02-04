#include "Date.hpp"
#include <sstream>
#include <stdexcept>

Date::Date() : year_(0), month_(0), day_(0) {}

Date::Date(std::string& input) : input_(input)
{
  populate_date_();
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

uint Date::get_year() const
{
  return year_;
}

uint Date::get_month() const
{
  return month_;
}

uint Date::get_day() const
{
  return day_;
}

void Date::populate_date_()
{
  size_t i = 0;
  std::string buffer;
  std::stringstream stream(input_);

  while (std::getline(stream, buffer, '-')) {
    std::istringstream istream(buffer);
    switch (i) {
    case YEAR:
      istream >> year_;
      break;
    case MONTH:
      istream >> month_;
      break;
    case DAY:
      istream >> day_;
      break;
    default:
      throw std::invalid_argument("not a valid date format");
    }
    ++i;
    if (istream.fail()) {
      throw std::invalid_argument("date is not a number");
    }
  }
}

bool  Date::is_leap_year_() const
{
  return year_ % 4 == 0 && (year_ % 100 != 0 || year_ % 400 == 0);
}

void  Date::is_valid_() const
{
  const int days_in_month[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

  if (year_ < 0 || month_ < 1 || month_ > 12) {
    throw std::invalid_argument("invalid date");
  }

  uint days = days_in_month[month_];
  if (month_ == 2 && is_leap_year_()) {
    ++days;
  }

  if ((day_ >= 1 && day_ <= days) == false) {
    throw std::invalid_argument("wrong amount of days in month");
  }
}

std::ostream& operator<<(std::ostream& ostream, const Date& date)
{
  return ostream << date.get_year() << "-"
                 << date.get_month() << "-"
                 << date.get_day();
}
