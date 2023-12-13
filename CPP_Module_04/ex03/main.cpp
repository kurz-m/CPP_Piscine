#include <iostream>
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

void test_mand() {
  IMateriaSource *src = new MateriaSource();
  src->learn_materia(new Ice());
  src->learn_materia(new Cure());

  ICharacter *me = new Character("me");

  AMateria *tmp;
  tmp = src->create_materia("ice");
  me->equip(tmp);
  tmp = src->create_materia("cure");
  me->equip(tmp);

  ICharacter *bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;
}

void test_extended() {
  MateriaSource src;
  src.learn_materia(new Ice());
  src.learn_materia(new Cure());

  Character c("bob");
  AMateria *tmp;
  tmp = src.create_materia("ice");
  c.equip(tmp);
  tmp = src.create_materia("cure");
  c.equip(tmp);

  Character e(c);
  e.use(0, c);
  e.use(1, c);

  std::cout << "reverse..." << std::endl;
  c.use(0, e);
  c.use(1, e);
}

int main(int argc, char **argv) {
  if (argc > 1)
  {
    std::string arg = argv[1];
    if (arg == "1") {
      test_mand();
    }
    else if (arg == "2") {
      test_extended();
    }
    else {
      std::cerr << "unrecognized option." << std::endl;
    }
  }
  else {
    std::cerr << "please choose test [1 - 4]!" << std::endl;
  }
  return 0;
}
