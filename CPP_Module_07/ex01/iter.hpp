#ifndef ITER_HPP_
# define ITER_HPP_

#include <cstdlib>

template<typename T, typename Fn>
void  iter(T* addr, size_t size, Fn func)
{
  for (size_t i = 0; i < size; ++i) {
    func(addr[i]);
  }
}

#endif
