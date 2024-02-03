#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <climits>
#include <ostream>

Span::Span(size_t N) : capacity_(N)
{
  elements_.reserve(N);
}

Span::Span(size_t N, size_t amount) : capacity_(N)
{
  add_range(amount);
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
    throw std::length_error("Capacity of Span is reached.");
  }
  elements_.push_back(n);
}

void  Span::add_range(size_t amount)
{
  std::srand(time(NULL));
  if (elements_.size() + amount > capacity_) {
    throw std::length_error("Capacity of Span is reached.");
  }
  for (size_t i = 0; i < amount; ++i) {
    elements_.push_back(std::rand());
  }
}

const int& Span::operator[](size_t index) const
{
  if (index >= elements_.size()) {
    throw std::out_of_range("Index out of range.");
  }
  return elements_[index];
}

size_t  Span::get_size() const
{
  return elements_.size();
}

size_t  Span::longest_span()
{
  if (elements_.size() < 2) {
    throw std::logic_error("Span contains less than 2 numbers.");
  }

  std::vector<int>::iterator  max;
  std::vector<int>::iterator  min;

  max = std::max_element(elements_.begin(), elements_.end());
  min = std::min_element(elements_.begin(), elements_.end());

  return static_cast<size_t>(*max - *min);
}

size_t  Span::shortest_span()
{
  if (elements_.size() < 2) {
    throw std::logic_error("Span contains less than 2 numbers.");
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

std::ostream& operator<<(std::ostream& o, const Span& s)
{
  o << "[";
  for (size_t i = 0; i < s.get_size(); ++i) {
    if (i > 0) {
      o << ", ";
    }
    o << s[i];
  }
  return o << "]";
}
