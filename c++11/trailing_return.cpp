#include <iostream>
#include <type_traits>

using namespace std;

template<class T, class U>
auto add(T a, U b) -> decltype(a + b)
{
  return a + b;
}

int main()
{
  auto sum = add(1, 3.14159L);
  double d;
  float f;
  static_assert(is_floating_point<decltype(sum)>::value, "Sum should be floating point.");
  cout << "sizeof(float) = " << sizeof(f) << endl;
  cout << "sizeof(double) = " << sizeof(d) << endl;
  cout << "sizeof(sum) = " << sizeof(sum) << endl;
  cout << sum << endl;

  return 0;
}
