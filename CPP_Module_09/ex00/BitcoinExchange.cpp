#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
  try {
    populate_db_();
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
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
    Date date(buffer.substr(0, buffer.find(",")));
    stream.str(buffer.substr(buffer.find(",") + 1));
    stream >> tmp_float_;
    if (stream.fail() || tmp_float_ < 0) {
       throw std::invalid_argument("not a valid bitcoin value");
    }
    db_.insert(std::pair<Date, float>(date, tmp_float_));
    stream.clear();
  }
}

void BitcoinExchange::read_input(const std::string &input)
{
  std::ifstream ifstrm(input.c_str());
  if (ifstrm.fail()) {
    throw std::invalid_argument("could not open input file");
  }

  BitcoinExchange::DataBase::const_iterator db_it;
  std::string buffer;
  std::getline(ifstrm, buffer);
  std::istringstream stream;

  while (std::getline(ifstrm, buffer)) {
    if (buffer.empty()) {
      continue;
    }
    try {
      date_ = Date(buffer.substr(0, buffer.find("|")));
    }
    catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
      continue;
    }
    // stream.clear();
    stream.str(buffer.substr(buffer.find("|") + 1));
    stream >> ratio_;
    if (stream.fail() || ratio_ > 1000 || ratio_ < 0) {
      std::cerr << "Error: ratio is not between 0 and 1000" << std::endl;
      stream.clear();
      continue;
    }
    stream.clear();
    user_query_ = UserQuery(date_, ratio_);
    db_it = db_.lower_bound(user_query_.first);
    if (db_it == db_.begin()) {
      std::cerr << "Error: no valid entry found" << std::endl;
      continue;
    }
    else if (db_it == db_.end()) {
      std::cerr << "date is above last database entry" << std::endl;
      --db_it;
    }
    else if (user_query_.first < db_it->first){
      --db_it;
    }
    std::cout << user_query_.first << " => " << user_query_.second
              << " * " << db_it->second
              <<  " = " << db_it->second * user_query_.second << std::endl;
  }
  ifstrm.close();
}
