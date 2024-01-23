#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <stack>
#include <ostream>

template<
  typename T,
  typename Container = std::deque<T>
>
class MutantStack : public std::stack<T, Container> {
public:
  MutantStack() : std::stack<T, Container>() {}
  MutantStack(const MutantStack& rhs) : std::stack<T, Container>(rhs) {}
  MutantStack& operator=(const MutantStack& rhs)
  {
    std::stack<T, Container>::operator=(rhs);
    return *this;
  }
  ~MutantStack() {}

  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;
  typedef typename Container::reverse_iterator reverse_iterator;
  typedef typename Container::const_reverse_iterator const_reverse_iterator;

  iterator begin()
  {
    return this->c.begin();
  }

  const_iterator begin() const
  {
    return this->c.begin();
  }

  iterator end()
  {
    return this->c.end();
  }

  const_iterator end() const
  {
    return this->c.end();
  }

  reverse_iterator rbegin()
  {
    return this->c.rbegin();
  }

  const_reverse_iterator rbegin() const
  {
    return this->c.rbegin();
  }

  reverse_iterator rend()
  {
    return this->c.rend();
  }

  const_reverse_iterator rend() const
  {
    return this->c.rend();
  }
};

template<typename T, typename Container>
std::ostream& operator<<(std::ostream& o, const MutantStack<T, Container>& stack)
{
  typename MutantStack<T, Container>::const_reverse_iterator rit;

  o << "Stack:\n";

  for (rit = stack.rbegin(); rit != stack.rend(); ++rit) {
    o << *rit << "\n";
  }
  o << "------------\n";
  return o;
}

#endif
