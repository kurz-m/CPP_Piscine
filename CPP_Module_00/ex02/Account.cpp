#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

  int   Account::_nbAccounts = 0;
  int   Account::_totalAmount = 0;
  int   Account::_totalNbDeposits = 0;
  int   Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
  static int    index = 0;

  _accountIndex = index;
  ++index;
  _totalAmount += _amount;
  ++_nbAccounts;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "created\n";
}

Account::~Account()
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "closed\n";
}

void    Account::_displayTimestamp()
{
  std::time_t   now = std::time(NULL);
  std::tm*  local = std::localtime(&now);

  std::cout << std::setfill('0')
            << "[" << 1900 + local->tm_year
            << std::setw(2) << local->tm_mon + 1
            << std::setw(2) << local->tm_mday << "_"
            << std::setw(2) << local->tm_hour
            << std::setw(2) << local->tm_min
            << std::setw(2) << local->tm_sec << "] ";
}

int  Account::getNbAccounts()
{
  return _nbAccounts;
}

int  Account::getTotalAmount()
{
  return _totalAmount;
}

int  Account::getNbDeposits()
{
  return _totalNbDeposits;
}

int  Account::getNbWithdrawals()
{
  return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos()
{
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";"
            << "total:" << getTotalAmount() << ";"
            << "deposits:" << getNbDeposits() << ";"
            << "withdrawals:" << getNbWithdrawals() << "\n";
}

void    Account::displayStatus() const
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "deposits:" << _nbDeposits << ";"
            << "withdrawals:" << _nbWithdrawals << "\n";
}

void    Account::makeDeposit(int deposit)
{
  _amount += deposit;
  ++_nbDeposits;
  _totalAmount += deposit;
  ++_totalNbDeposits;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount - deposit << ";"
            << "deposit:" << deposit << ";"
            << "amount:" << _amount << ";"
            << "nb_deposits:" << _nbDeposits << "\n";
}

bool    Account::makeWithdrawal(int withdrawal)
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";"
            << "withdrawal:";
  if (withdrawal > _amount) {
    std::cout << "refused\n";
    return false;
  }
  _amount -= withdrawal;
  ++_nbWithdrawals;
  _totalAmount -= withdrawal;
  ++_totalNbWithdrawals;
  std::cout << withdrawal << ";"
            << "amount:" << _amount << ";"
            << "nb_withdrawals:" << _nbWithdrawals << "\n";
  return true;
}

int Account::checkAmount() const
{
  return _amount;
}
