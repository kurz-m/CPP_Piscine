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
  void  set_outfile(const std::string& filename);
  void  read_file(std::ifstream& istrm);
  std::string create_output() const;

  const std::string infile_;
  const std::string find_;
  const std::string replace_;
  std::string outfile_;
  std::string buff_;
};

#endif
