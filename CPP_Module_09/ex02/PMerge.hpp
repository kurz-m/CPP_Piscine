#ifndef __PMERGE_HPP__
#define __PMERGE_HPP__

#include <map>

typedef unsigned int uint;

template <typename T>
class Pmerge {
public:
  Pmerge();
  Pmerge(const Pmerge &rhs);
  Pmerge &operator=(const Pmerge &rhs);
  ~Pmerge();

private:
  uint offset_;
  T box_;
  std::multimap<int, int> pre_sort_;
};

#endif
