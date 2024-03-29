#ifndef SERIALIZER_HPP_
# define SERIALIZER_HPP_

#include <string>
#include <cstdlib>
#include <stdint.h>

struct Data;

class Serializer {
public:
  ~Serializer();

  static uintptr_t  serialize(Data* ptr);
  static Data*  deserialize(uintptr_t raw);

private:
  Serializer();
  Serializer(const Serializer&);
  Serializer& operator=(const Serializer&);

};

#endif
