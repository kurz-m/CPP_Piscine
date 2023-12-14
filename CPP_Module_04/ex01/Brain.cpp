#include "Brain.hpp"

Brain::Brain() : curr_idea(0)
{
  debug_print("Brain constructor called.", CYAN);
}

Brain::Brain(const Brain& rhs)
{
  for (int k = 0; k < BRAIN_SIZE; ++k) {
    ideas_[k] = rhs.ideas_[k];
  }
  debug_print("Brain copy constructor called.", CYAN);
}

Brain& Brain::operator=(const Brain& rhs)
{
  debug_print("Brain copy assignment operator called.", CYAN);
  if (this != &rhs) {
    for (int k = 0; k < BRAIN_SIZE; ++k) {
      ideas_[k] = rhs.ideas_[k];
    }
  }
  return *this;
}

Brain::~Brain()
{
  debug_print("Brain destructor called.", CYAN);
}

void  Brain::create_idea(const std::string& idea)
{
  if (curr_idea < BRAIN_SIZE) {
    std::cout << "Added '" << idea << "' as an idea to the brain." << std::endl;
    ideas_[curr_idea++] = idea;
  }
  else {
    debug_print("The brain ran out of capacity.", CYAN);
  }
}

void  Brain::list_ideas() const
{
  for (int k = 0; k < curr_idea; ++k) {
    std::cout << "Idea " << k + 1 << ": " << ideas_[k] << "\n";
  }
}

void  Brain::print_addr() const
{
  std::cout << "Address of brain: " << this << std::endl;
}
