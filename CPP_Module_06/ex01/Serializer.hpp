#ifndef SERIALIZER_HPP_
# define SERIALIZER_HPP_

#include <string>

struct Data {
  std::string   name;
  unsigned int  number;
};

class Serializer {
public:
  ~Serializer();

private:
  Serializer();
  Serializer(const Serializer&);
  Serializer& operator=(const Serializer&);

  static uintptr_t  serialize(Data* ptr);
  static Data*  deserialize(uintptr_t raw);
};

#endif
