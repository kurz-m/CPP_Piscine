#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <map>

class Date;

#define DB_DEL ","
#define INPUT_DEL "|"

class BitcoinExchange {
public:
  BitcoinExchange();
  ~BitcoinExchange();

  void read_input(std::string&);

private:
  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);

  void populate_db_();

  std::map<Date, float> db_;
  std::map<Date, float> user_input_;
  float tmp_float_;
};

#endif
