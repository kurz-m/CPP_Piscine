#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& rhs)
{
  *this = rhs;
}

Serializer& Serializer::operator=(const Serializer&)
{
  return *this;
}

Serializer::~Serializer() {}
