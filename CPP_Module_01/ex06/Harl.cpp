#include "Harl.hpp"

Harl::Harl() : complain_level_(-1) {}

Harl::~Harl() {}

void    Harl::complain(std::string level)
{
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for (int i = 0; i < LEVELS; ++i) {
    if (levels[i].compare(level) == 0) {
      complain_level_ = i;
    }
  }
  filter_();
  
  std::cout << "Cannot find your complain in the book of complains." << std::endl;
}

void    Harl::filter_()
{
  enum filter {debug, info, warning, error};
  switch(complain_level_) {
    case debug:
      debug_();
      // explicit fallthrough
    case info:
      info_();
      // explicit fallthrough
    case warning:
      warning_();
      // explicit fallthrough
    case error:
      error_();
      break;
    default:
      std::cout
        << "Likely grumbling about the lack "
        << "of zero-gravity coffee flavors aboard the spaceship."
        << std::endl;
  }
}

void    Harl::debug_()
{
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "Testing the zero-gravity reaction of this new space-jelly "
    << "sandwich. Results are... sticky." << std::endl;
}

void    Harl::info_()
{
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "Spacewalk log, day 42: Noticed Earth looks a bit like a "
    << "blueberry muffin from this angle. Note: Maybe I'm just hungry."
    << std::endl;
}

void    Harl::warning_()
{
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "Not entirely sure, but I believe the moon might be following "
    << "us. Oh, wait, that's its regular orbit." << std::endl;
}

void    Harl::error_()
{
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "Houston, we have a problem. I left the spaceship keys inside "
    << "the spaceship. We might need a space locksmith." << std::endl;
}
