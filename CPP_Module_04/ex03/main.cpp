#include <iostream>
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "utils.hpp"

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

void test_materia() {
  MateriaSource src;
  src.learn_materia(new Ice());
  src.learn_materia(new Cure());
  src.learn_materia(new Ice());
  src.learn_materia(new Cure());
  src.learn_materia(new Cure());

  Character c("bob");
  AMateria *tmp;
  tmp = src.create_materia("ice");
  c.equip(tmp);
  tmp = src.create_materia("cure");
  c.equip(tmp);
  tmp = src.create_materia("ice");
  c.equip(tmp);

  Character e(c);
  e.use(0, c);
  e.use(1, c);
}

void test_capacity() {
  MateriaSource src;
  src.learn_materia(new Ice());
  src.learn_materia(new Cure());

  Character c("bob");
  AMateria *tmp;
  tmp = src.create_materia("ice");
  c.equip(tmp);
  tmp = src.create_materia("cure");
  c.equip(tmp);
  tmp = src.create_materia("ice");
  c.equip(tmp);
  tmp = src.create_materia("cure");
  c.equip(tmp);
  tmp = src.create_materia("ice");
  c.equip(tmp);
  tmp = src.create_materia("cure");
  c.equip(tmp);
  tmp = src.create_materia("ice");
  c.equip(tmp);
  tmp = src.create_materia("cure");
  c.equip(tmp);

  Character e(c);
  e.use(0, c);
  e.use(1, c);
  e.use(2, c);
  e.use(3, c);
  e.use(4, c);
}

void  check_leaks()
{
  system("leaks character");
}

int main(int argc, char **argv) {
  atexit(check_leaks);
  if (argc > 1)
  {
    int test = std::string(argv[1]).compare("1") == 0 ? 0 :
                std::string(argv[1]).compare("2") == 0 ? 1 :
                std::string(argv[1]).compare("3") == 0 ? 2 :
                std::string(argv[1]).compare("4") == 0 ? 3 : 100;
    switch (test) {
    case 0:
      test_mand();
      break;
    case 1:
      test_extended();
      break;
    case 2:
      test_materia();
      break;
    case 3:
      test_capacity();
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
