#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

template <typename Container, typename Pairs>
class PmergeMe {
public:
  PmergeMe() {}
  PmergeMe(const PmergeMe& rhs)
  {
    *this = rhs;
  }

  PmergeMe &operator=(const PmergeMe& rhs)
  {
    if (this != &rhs) {
      *this = rhs;
    }
    return *this;
  }
  ~PmergeMe() {}

private:
  Container  main_;
  Pairs  pairs_;
};

#endif
