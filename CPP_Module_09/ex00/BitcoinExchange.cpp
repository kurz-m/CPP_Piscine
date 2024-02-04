#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
  generate_db_();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&)
{
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::generate_db_()
{

}
