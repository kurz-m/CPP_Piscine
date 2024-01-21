#ifndef ARRAY_HPP_
# define ARRAY_HPP_

#include <cstdlib>
#include <exception>

template<typename T>
class Array {
public:
  Array(): array_(NULL), size_(0) {}

  Array(unsigned int n): array_(new T[n]()), size_(n) {}

  Array(const Array<T>& rhs)
    : array_(new T[rhs.size_]), size_(rhs.size_)
  {
    for (size_t i = 0; i < rhs.size_; i++) {
      array_[i] = rhs.array_[i];
    }
  }

  Array<T>& operator=(const Array<T>& rhs)
  {
    if (this != &rhs) {
      delete[] array_;
      size_ = rhs.size_;
      array_ = new T[rhs.size_];
      for (size_t i = 0; i < rhs.size_; i++) {
        array_[i] = rhs.array_[i];
      }
    }
    return *this;
  }

  ~Array()
  {
    delete[] array_;
  }

  size_t  size() const
  {
    return size_;
  }

  T&  operator[](size_t index)
  {
    if (index >= size_) {
      throw OutOfBound();
    }
    return array_[index];
  }

  class OutOfBound: public std::exception {
    virtual const char* what() const throw()
    {
      return "Index out of bounds";
    }
  };

private:
  T*  array_;
  size_t  size_;
};

#endif
