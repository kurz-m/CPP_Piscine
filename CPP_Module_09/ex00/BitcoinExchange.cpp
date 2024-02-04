#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
  populate_db_();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&)
{
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::populate_db_()
{
  std::ifstream ifstrm(DB_INPUT);
  if (ifstrm.fail()) {
    throw std::invalid_argument("could not open database file");
  }
  std::string buffer;
  std::getline(ifstrm, buffer);
  while(std::getline(ifstrm, buffer)) {
    Date date(buffer.substr(0, buffer.find(DB_DEL)));
    std::istringstream stream(buffer.substr(buffer.find(DB_DEL) + 1));
    stream >> tmp_float_;
    if (stream.fail() || tmp_float_ < 0) {
       throw std::invalid_argument("not a valid bitcoin value");
    }
    db_.insert(std::pair<Date, float>(date, tmp_float_));
  }
}
