#include <iostream>
#include <sstream>
#include <iomanip>

int main()
{
  std::string test("42.0f");

  float test1;

  std::istringstream  inbuf(test);
  inbuf >> test1;

  if (true == inbuf.eof()) {
    std::cout << "double\n";
  }
  else {
    std::cout << "float\n";
  }
  std::cout << inbuf;

  std::cout << std::fixed << std::setprecision(1) << test1 << std::endl;

  std::cout.unsetf(std::ios::fixed);

  std::cout << std::setprecision(-1) << test1;
  return 0;
}
