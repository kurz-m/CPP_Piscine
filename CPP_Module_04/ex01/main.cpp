#include "Dog.hpp"
#include "Cat.hpp"
#include "utils.hpp"

void test_pdf()
{
  Animal* horde[10];
  int i = 0;

  while (i < 5) {
    horde[i++] = new Dog;
  }

  while (i < 10) {
    horde[i++] = new Cat;
  }
  i = 0;
  while (i < 10) {
    horde[i]->make_sound();
    delete horde[i++];
  }
}

void  test_deep()
{
  Dog dog;
  Dog dog2;

  dog.create_idea("Nothing");
  dog.create_idea("Eat bone");
  dog.list_ideas();
  dog.print_addr();
  dog2 = dog;
  dog2.print_addr();
  dog2.list_ideas();

}

void  test_single_idea()
{
  Dog pluto;

  pluto.create_idea("burry a bone.");
  pluto.list_ideas();
}

int main(int argc, char **argv) {
  if (argc > 1)
  {
    int test = std::string(argv[1]).compare("1") == 0 ? 0 :
                std::string(argv[1]).compare("2") == 0 ? 1 :
                std::string(argv[1]).compare("3") == 0 ? 2 : 100;
    switch (test) {
    case 0:
      test_pdf();
      break;
    case 1:
      test_deep();
      break;
    case 2:
      test_single_idea();
      break;
    default:
      log_level("unknown test option.", RED, DEBUG);
    }
  }
  else {
    std::cerr << "please choose test [1 - 4]!" << std::endl;
  }
  return 0;
}
