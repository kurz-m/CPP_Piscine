#include "Zombie.hpp"

int main(void)
{
  Zombie*   horde;
  const int N = 5;

  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "           Creating a horde of zombies           " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  horde = zombieHorde(N, "Thrall");
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "        Announce each member of the horde        " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  for (int i = 0; i < N; i++) {
    std::cout << i + 1 << ". member of the horde:" << std::endl;
    horde[i].announce();
  }
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "        Deleting each member of the horde        " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  delete [] horde;
  return EXIT_SUCCESS;
}
