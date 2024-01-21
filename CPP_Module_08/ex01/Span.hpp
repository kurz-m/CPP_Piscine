#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <cstdlib>
#include <vector>
#include <exception>

class Span {
public:
  Span(size_t N = 0);
  Span(const Span&);
  Span& operator=(const Span&);
  ~Span();

  void  add_number(int);

  template<typename It>
  void  add_range(It& first, It& last)
  {
    if (elements_.size() + std::distance(first, last) > capacity_) {
      throw std::exception();
    }
    elements_.insert(elements_.end(), first, last);
  }

  size_t  get_size() const;
  size_t  longest_range();
  size_t  shortest_range();

private:
  std::vector<int>  elements_;
  size_t  capacity_;
};

#endif
