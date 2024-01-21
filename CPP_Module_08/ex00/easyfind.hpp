#ifndef EASYFIND_HPP_
# define EASYFIND_HPP_

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int i)
{
  typename T::iterator  it = std::find(container.begin(), container.end(), i);

  if (container.end() == it) {
    throw std::runtime_error("Integer was not found in the container.");
  }
  else {
    return it;
  }
}

#endif
