#ifndef DATE_HPP_
# define DATE_HPP_

#include <cstdlib>
#include <istream>

#define DB_INPUT "data.csv"

typedef unsigned int uint;

class Date {
public:
  Date();
  explicit Date(const std::string&);
  Date(const Date&);
  Date& operator=(const Date&);
  ~Date();

  bool operator<(const Date&) const;
  bool operator<=(const Date&) const;
  bool operator>(const Date&) const;
  bool operator>=(const Date&) const;
  bool operator==(const Date&) const;
  bool operator!=(const Date&) const;

  uint get_year() const;
  uint get_month() const;
  uint get_day() const;

private:
  void populate_date_();
  bool is_leap_year_() const;
  void is_valid_() const;

  enum {
     YEAR,
     MONTH,
     DAY,
  };

  std::string input_;
  uint  year_;
  uint  month_;
  uint  day_;
};

std::ostream& operator<<(std::ostream&, const Date&);

#endif
