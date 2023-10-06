#ifndef REPLACER_HPP_
#define REPLACER_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Replacer {

public:
  Replacer(std::string filename, std::string find, std::string replace);
  ~Replacer();

  void  replace_str();

private:
  std::string   infile_;
  std::string   outfile_;
  std::string   buff_;
  std::string   find_;
  std::string   replace_;

  void  set_outfile(std::string filename);
  void  read_file(std::ifstream& istrm);
  std::string   create_output();
};

#endif
