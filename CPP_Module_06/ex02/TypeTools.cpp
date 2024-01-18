#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <exception>

Base* generate()
{
  std::srand(time(NULL));
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
