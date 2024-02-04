#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <iostream>
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
  std::istringstream stream;

  while(std::getline(ifstrm, buffer)) {
    if (buffer.empty()) {
      continue;
    }
    Date date(buffer.substr(0, buffer.find(DB_DEL)));
    stream.str(buffer.substr(buffer.find(DB_DEL) + 1));
    stream >> tmp_float_;
    if (stream.fail() || tmp_float_ < 0) {
       throw std::invalid_argument("not a valid bitcoin value");
    }
    db_.insert(std::pair<Date, float>(date, tmp_float_));
  }
}

void BitcoinExchange::read_input(std::string &input)
{
  std::ifstream ifstrm(input.c_str());
  if (ifstrm.fail()) {
    throw std::invalid_argument("could not open input file");
  }

  std::string buffer;
  std::getline(ifstrm, buffer);
  std::istringstream stream;

  while (std::getline(ifstrm, buffer)) {
    if (buffer.empty()) {
      continue;
    }
    try {
      date_ = Date(buffer.substr(0, buffer.find(INPUT_DEL)));
    }
    catch (const std::exception&) {
      continue;
    }
    stream.str(buffer.substr(buffer.find(INPUT_DEL) + 1));
    stream >> ratio_;
    if (stream.fail() || tmp_float_ > 1000 || tmp_float_ < 0) {
      std::cerr << "ratio is not between 0 and 1000" << std::endl;
      continue;
    }
    user_input_ = UserQuery(date_, ratio_);
  }
}
