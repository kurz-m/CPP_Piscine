#ifndef DATE_HPP_
# define DATE_HPP_

#include <cstdlib>
#include <istream>

typedef unsigned int uint;

class Date {
public:
  explicit Date(uint, uint,uint);
  explicit Date(std::string&);
  Date(const Date&);
  Date& operator=(const Date&);
  ~Date();

  bool operator<(const Date&) const;
  std::istream& operator>>(std::istream&);

private:
  Date();

  bool is_leap_year() const;
  bool is_valid() const;

  uint  year_;
  uint  month_;
  uint  day_;
};

#endif
