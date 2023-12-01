#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
  Animal* dog = new Dog();
  Animal* cat = new Cat();
  Animal  base;

  std::cout << "What make the " << cat->get_type() << "?\n";
  cat->make_sound();
  std::cout << "What make the " << dog->get_type() << "?\n";
  dog->make_sound();

  delete cat;
  delete dog;
  return EXIT_SUCCESS;
}
