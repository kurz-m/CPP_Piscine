#include "Span.hpp"
#include <algorithm>
#include <iterator>

Span::Span(size_t N) : capacity_(N)
{
  elements_.reserve(N);
}

Span::Span(const Span& rhs)
{
  *this = rhs;
}

Span& Span::operator=(const Span& rhs)
{
  if (this != &rhs) {
    elements_ = rhs.elements_;
    capacity_ = rhs.capacity_;
  }
  return *this;
}

Span::~Span() {}

void  Span::add_number(int n)
{
  if (elements_.size() == capacity_) {
    throw std::runtime_error("Capacity of Span is reached.");
  }
  elements_.push_back(n);
}

size_t  Span::get_size() const
{
  return elements_.size();
}

size_t  Span::longest_range()
{
  if (elements_.size() < 2) {
    throw std::runtime_error("Span contains less than 2 numbers.");
  }

  std::vector<int>::iterator  max;
  std::vector<int>::iterator  min;

  max = std::max_element(elements_.begin(), elements_.end());
  min = std::min_element(elements_.begin(), elements_.end());

  return static_cast<size_t>(*max - *min);
}

size_t  Span::shortest_range()
{
  if (elements_.size() < 2) {
    throw std::runtime_error("Span contains less than 2 numbers.");
  }

  std::vector<int>  sorted = elements_;
  std::vector<int>::iterator it;

  std::sort(sorted.begin(), sorted.end());
  int shortest = INT_MAX;
  for (it = sorted.begin() + 1; it != sorted.end(); ++it) {
    shortest = std::min(shortest, *it - *(it - 1));
  }
  return static_cast<size_t>(shortest);
}
