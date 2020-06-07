#include <type_traits>

int main()
{
  static_assert(std::is_null_pointer<decltype(nullptr)>::value, "nullptr should be nullptr");
}