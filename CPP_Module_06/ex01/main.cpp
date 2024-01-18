#include "Serializer.hpp"
#include "Data.hpp"
#include "utils.hpp"

void  test_serializer()
{
  log_level("Test serializing the data", TEST);
  Data  data;
  uintptr_t ptr;

  data.content = "test serializing a string";
  log_level(std::string("Data from the struct: ") + data.content, INFO);
  ptr = Serializer::serialize(&data);
  
  std::cout << "Serialized data: " << std::hex << ptr << "\n";
  std::cout << "Original address: " << &data << std::endl;

  log_level("End of first test\n", INFO);
}

void  test_deserializer()
{
  log_level("Test deserializing the data", TEST);
  Data  data;
  Data* de_data;
  uintptr_t ptr;

  data.content = "I am a string";
  ptr = Serializer::serialize(&data);
  de_data = Serializer::deserialize(ptr);

  std::cout << std::string("Data from the original struct: ") + data.content << "\n";
  std::cout << std::string("Data from deserialization: ") + de_data->content << "\n";
  log_level("End of second test\n", INFO);
}

void  test_change_data()
{
  log_level("Test change data from original struct", TEST);
  Data  data;
  Data* de_data;
  uintptr_t ptr;

  data.content = "I am a string";
  ptr = Serializer::serialize(&data);
  de_data = Serializer::deserialize(ptr);

  std::cout << std::string("Data from the original struct before change: ")
    + data.content << "\n";
  std::cout << std::string("Data from deserialization before change: ")
    + de_data->content << "\n";

  log_level("Change of data through the original struct", INFO);
  data.content = "I got changed";
  std::cout << std::string("Data from the original struct after change: ")
    + data.content << "\n";
  std::cout << std::string("Data from deserialization after change: ")
    + de_data->content << "\n";
  log_level("End of third test\n", INFO);
}

void  test_change_from_deserialized()
{
  log_level("Test change data from deserialized variable", TEST);
  Data  data;
  Data* de_data;
  uintptr_t ptr;

  data.content = "I am a string";
  ptr = Serializer::serialize(&data);
  de_data = Serializer::deserialize(ptr);

  std::cout << std::string("Data from the original struct before change: ")
    + data.content << "\n";
  std::cout << std::string("Data from deserialization before change: ")
    + de_data->content << "\n";

  log_level("Change of data through the original struct", INFO);
  de_data->content = "I got changed";
  std::cout << std::string("Data from the original struct after change: ")
    + data.content << "\n";
  std::cout << std::string("Data from deserialization after change: ")
    + de_data->content << "\n";
  log_level("End of fourth test\n", INFO);
}

int main()
{
  test_serializer();

  test_deserializer();

  test_change_data();

  test_change_from_deserialized();

  return EXIT_SUCCESS;
}
