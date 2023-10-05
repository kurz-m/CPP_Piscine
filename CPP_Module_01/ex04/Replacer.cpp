#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string find, std::string replace)
  : infile_(filename), find_(find), replace_(replace)
{
  if (find.empty() == true || replace.empty() == true) {
    std::cout << "Error: Cannot replace an empty string" << std::endl;
    return;
  }
}

Replacer::~Replacer() {}

void  Replacer::set_outfile(std::string filename)
{
  outfile_ = filename + ".replace";
}

void  Replacer::replace_str()
{
  return;
}
