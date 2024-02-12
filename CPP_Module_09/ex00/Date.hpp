#ifndef DATE_HPP_
# define DATE_HPP_

#include <cstdlib>
#include <istream>

#define DB_INPUT "data.csv"

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

  int get_year() const;
  int  get_month() const;
  int  get_day() const;

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
  int  year_;
  int   month_;
  int   day_;
};

std::ostream& operator<<(std::ostream&, const Date&);

#endif
