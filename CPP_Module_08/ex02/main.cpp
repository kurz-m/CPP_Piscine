#include "MutantStack.hpp"
#include <cstdlib>
#include <iostream>
#include <list>

void  print_test_name(const std::string& test_name)
{
  std::cout << "[TEST] " << test_name << "\n";
}

template<typename T, typename Container>
MutantStack<T, Container>  create_random_stack(size_t size)
{
  MutantStack<T, Container>  stack;
  std::srand(time(NULL));
  for (size_t i = 0; i < size; ++i) {
    stack.push(std::rand());
  }
  return stack;
}

void  test_creating_rnd_stack()
{
  print_test_name("random stack generation.");
  MutantStack<int> stack = create_random_stack< int, std::deque<int> >(10);

  std::cout << stack;
  std::cout << "pop one element\n";
  stack.pop();
  std::cout << stack;
  std::cout << std::endl;
}

void  test_list_container()
{
  print_test_name("take list container");
  MutantStack<
    int,
    std::list<int>
  >
  stack = create_random_stack< int, std::list<int> >(10);

  std::cout << "Top of stack: " << stack.top() << "\n";
  std::cout << "pop one element\n";
  stack.pop();
  std::cout << "Top of stack: " << stack.top() << "\n";
}

int main()
{
  test_creating_rnd_stack();

  test_list_container();

  return EXIT_SUCCESS;
}
