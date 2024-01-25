#include "Base.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <exception>
#include <fstream>

Base* generate()
{
  std::ifstream urandom("/dev/urandom", std::ios::in | std::ios::binary);

  if (urandom.is_open() == true) {
    uint  seed;
    urandom.read(reinterpret_cast<char*>(&seed), sizeof(seed));
    std::srand(seed);
    urandom.close();
  }
  else {
    std::srand(time(NULL));
  }
  switch (std::rand() % 3) {
  case 0:
    return new A;
  case 1:
    return new B;
  case 2:
    return new C;
  }
  return NULL;
}

void  identify(Base* ptr)
{
  if (dynamic_cast<A*>(ptr) != NULL) {
    log_level("Identified as A!", INFO);
  }
  if (dynamic_cast<B*>(ptr) != NULL) {
    log_level("Identified as B!", INFO);
  }
  if (dynamic_cast<C*>(ptr) != NULL) {
    log_level("Identified as C!", INFO);
  }
}

void  identify(Base& ptr)
{
  try {
    (void)dynamic_cast<A&>(ptr);
    log_level("Identified as A!", INFO);
  }
  catch (const std::exception&) {
  }
  try {
    (void)dynamic_cast<B&>(ptr);
    log_level("Identified as B!", INFO);
  }
  catch (const std::exception&) {
  }
  try {
    (void)dynamic_cast<C&>(ptr);
    log_level("Identified as C!", INFO);
  }
  catch (const std::exception&) {
  }
}
