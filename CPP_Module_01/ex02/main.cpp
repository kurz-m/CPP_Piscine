#include <iostream>
#include <string>
#include <cstdlib>

int main(void)
{
  const std::string str = "HI THIS IS BRAIN";

  const std::string*  stringPTR = &str;
  const std::string&  stringREF = str;

  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "           Address of string variable            " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "&str: " << &str << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "           Address held by stringPTR             " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "stringPTR: " <<  stringPTR << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "           Address held by stringREF             " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "&stringREF: " << &stringREF << std::endl;
  
  std::cout << std::endl;;
  std::cout << "#################################################" << std::endl;
  std::cout << "#################################################" << std::endl;
  std::cout << "#################################################" << std::endl;
  std::cout << std::endl;;

  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "             Value of string variable            " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "str: " << str << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "             Value held by stringPTR             " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "*stringPTR: " <<  *stringPTR << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "             Value held by stringREF             " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "stringREF: " << stringREF << std::endl;

  return EXIT_SUCCESS;
}
