#include <iostream>
#include <sstream>
#include <iomanip>

int main()
{
  std::string test("42.0");

  double test1;

  std::istringstream  inbuf(test);
  inbuf >> test1;

  std::cout << std::fixed << std::setprecision(1) << test1 << std::endl;

  std::cout.unsetf(std::ios::fixed);

  std::cout << std::setprecision(-1) << test1;
  return 0;
}
