#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::complain(const std::string level) const
{
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*f[4])() const = {
    &Harl::debug_,
    &Harl::info_,
    &Harl::warning_,
    &Harl::error_
  };

  for (int i = 0; i < LEVELS; ++i) {
    if (levels[i].compare(level) == 0) {
      (this->*f[i])();
      return;
    }
  }
  std::cout << "Cannot find your complain in the book of complains." << std::endl;
}

void    Harl::debug_() const
{
  std::cout << "Testing the zero-gravity reaction of this new space-jelly "
    << "sandwich. Results are... sticky." << std::endl;
}

void    Harl::info_() const
{
  std::cout << "Spacewalk log, day 42: Noticed Earth looks a bit like a "
    << "blueberry muffin from this angle. Note: Maybe I'm just hungry."
    << std::endl;
}

void    Harl::warning_() const
{
  std::cout << "Not entirely sure, but I believe the moon might be following "
    << "us. Oh, wait, that's its regular orbit." << std::endl;
}

void    Harl::error_() const
{
  std::cout << "Houston, we have a problem. I left the spaceship keys inside "
    << "the spaceship. We might need a space locksmith." << std::endl;
}
