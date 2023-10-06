#include "Replacer.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cout << "Usage: ./replacer <filename> <find> <replace>" << std::endl;
    return EXIT_FAILURE;
  }
  Replacer  replacer(argv[1], argv[2], argv[3]);
  replacer.replace_str();

  return EXIT_SUCCESS;
}
