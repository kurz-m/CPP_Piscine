#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string find, std::string replace)
  : infile_(filename), find_(find), replace_(replace)
{
  if (find.empty() == true || replace.empty() == true) {
    std::cout << "Error: Cannot replace an empty string" << std::endl;
    return;
  }
  set_outfile(filename);
}

Replacer::~Replacer() {}

void  Replacer::set_outfile(std::string filename)
{
  outfile_ = filename + ".replace";
}

void Replacer::read_file(std::ifstream& istrm)
{
  buff_.assign(std::istreambuf_iterator<char>(istrm), std::istreambuf_iterator<char>());
}

std::string Replacer::create_output()
{
  size_t    pos = 0;
  size_t    i;
  std::string   output;

  do {
    i = buff_.find(find_, pos);
    if (i != buff_.npos) {
      output += buff_.substr(pos, i - pos) + replace_;
      pos = i + find_.length();
    }
    else {
      output += buff_.substr(pos);
    }
  } while (i != buff_.npos);
  return output;
}

void  Replacer::replace_str()
{
  std::ifstream istrm(infile_.c_str());
  std::ofstream ostrm(outfile_.c_str());

  if (istrm.fail() == true) {
    std::cout << "Could not open the file: " << infile_ << std::endl;
    return;
  }
  if (ostrm.fail() == true) {
    std::cout << "Could not open the file: " << outfile_ << std::endl;
    return;
  }
  read_file(istrm);
  istrm.close();
  ostrm << create_output();
  ostrm.close();
  return;
}
