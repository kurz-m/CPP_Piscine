#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <vector>
#include <stdexcept>

class Span {
public:
  explicit Span(size_t N = 0);
  Span(size_t, int, int);
  Span(const Span&);
  Span& operator=(const Span&);
  ~Span();

  void  add_number(int);

  template<typename It>
  void  add_range(const It& first, const It& last)
  {
    if (elements_.size() + std::distance(first, last) > capacity_) {
      throw std::length_error("Capacity of Span is reached.");
    }
    elements_.insert(elements_.end(), first, last);
  }

  void  add_range(int, int);

  const int& operator[](size_t index) const;

  size_t  get_size() const;
  size_t  longest_span();
  size_t  shortest_span();

private:
  std::vector<int>  elements_;
  size_t  capacity_;
};

std::ostream& operator<<(std::ostream&, const Span&);

#endif
