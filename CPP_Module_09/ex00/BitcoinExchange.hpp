#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <map>

class Date;

class BitcoinExchange {
public:
  BitcoinExchange();
  ~BitcoinExchange();

  void read_input(std::string&);

private:
  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);

  void generate_db_();

  std::map<Date, float> db_;
  std::map<Date, float> user_input_;
};

#endif
