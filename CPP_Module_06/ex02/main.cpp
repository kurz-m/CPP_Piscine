#include "TypeTools.hpp"
#include <cstdlib>
#include "utils.hpp"

void test_identify_via_pointer()
{
  log_level("Test identify via pointer", TEST);
  Base* ptr = generate();

  identify(ptr);
}

void test_identify_via_ref()
{
  log_level("Test identify via reference", TEST);
  Base* ptr = generate();

  identify(*ptr);
}

int main()
{
  test_identify_via_pointer();
  
  test_identify_via_ref();

  return EXIT_SUCCESS;
}
