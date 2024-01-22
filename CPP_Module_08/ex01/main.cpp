#include "Span.hpp"
#include <cstdlib>
#include <iostream>

void  print_test_name(const std::string& test_name)
{
  std::cout << "[TEST] " << test_name << "\n";
}

Span  create_random_vector(size_t size)
{
  Span  span(size);
  std::srand(time(NULL));
  for (size_t i = 0; i < size; ++i) {
    span.add_number(std::rand());
  }
  return span;
}

void  test_empty_span()
{
  print_test_name("for empty span.");
  Span  empty(0);

  try {
    empty.add_number(10);
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

}

void  test_add_number()
{
  print_test_name("adding a single number.");
  Span  span(10);

  std::cout << "Before adding number: " << span << "\n";
  span.add_number(42);
  std::cout << "After adding number: " << span << "\n";
}

void  test_add_range_iterators()
{
  int nums[] = {8, 4, 5, 9};
  std::vector<int> v(nums, nums + sizeof(nums) / sizeof(nums[0]));

  print_test_name("adding a range of numbers via iterators.");
  Span  span(10);

  std::cout << "Before adding range: " << span << "\n";
  span.add_range(v.begin() + 1, v.end());
  std::cout << "After adding range: " << span << "\n";
}

void  test_add_range_int()
{
  print_test_name("adding a range of numbers via int.");
  Span  span(10);

  std::cout << "Before adding range: " << span << "\n";
  span.add_range(4, 10);
  std::cout << "After adding range: " << span << "\n";
}

void  test_shortest_range_error()
{
  print_test_name("shortest range error.");
  Span  span(10);

  span.add_number(21);
  try {
    span.shortest_span();
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

void  test_shortest_range()
{
  print_test_name("shortest range.");
  Span  span = create_random_vector(20000);

  std::cout << span.shortest_span() << std::endl;
}

void  test_longest_range_error()
{
  print_test_name("longest range error.");
  Span  span = create_random_vector(1);

  try {
    span.longest_span();
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

void  test_longest_range()
{
  print_test_name("longest range.");
  Span  span = create_random_vector(10000);

  std::cout << span.longest_span() << std::endl;
}

void  test_print_span()
{
  print_test_name("just print span.");
  Span  span = create_random_vector(20);

  std::cout << span << "\n";
}

int main()
{
  test_empty_span();
  test_add_number();
  test_add_range_iterators();
  test_add_range_int();
  test_shortest_range_error();
  test_shortest_range();
  test_longest_range_error();
  test_longest_range();
  test_print_span();

  return EXIT_SUCCESS;
}
