#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
  WrongAnimal*  meta = new WrongAnimal();
  WrongAnimal*  fake_cat = new WrongCat();
  Animal* dog = new Dog();
  Animal* cat = new Cat();
  Animal  base;

  std::cout << "What sound makes the " << cat->get_type() << "?\n";
  cat->make_sound();
  std::cout << "What sound makes the " << dog->get_type() << "?\n";
  dog->make_sound();

  std::cout << "What sound makes the " << fake_cat->get_type() << "?\n";
  fake_cat->make_sound();
  std::cout << "What sound makes the " << meta->get_type() << "?\n";
  meta->make_sound();


  delete cat;
  delete dog;
  delete meta;
  delete fake_cat;
  return EXIT_SUCCESS;
}
