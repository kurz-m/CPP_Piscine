#ifndef BRAIN_HPP_
# define BRAIN_HPP_

#include <string>

#include "utils.hpp"

#define BRAIN_SIZE 100

class Brain {
public:
  Brain();
  Brain(const Brain&);
  Brain& operator=(const Brain&);
  ~Brain();

  void  create_idea(const std::string&);
  void  list_ideas() const;
  void  print_addr() const;

private:
  std::string  ideas_[BRAIN_SIZE];
  int   curr_idea;
};

#endif
