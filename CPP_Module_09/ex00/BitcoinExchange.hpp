#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <map>

#include "Date.hpp"

class BitcoinExchange {
public:
  BitcoinExchange();
  ~BitcoinExchange();

  void read_input(const std::string&);

private:
  typedef std::pair<Date, float> UserQuery;
  typedef std::map<Date, float> DataBase;

  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);

  void populate_db_();

  DataBase db_;
  UserQuery user_query_;
  float tmp_float_;
  float ratio_;
  Date date_;
};

#endif
