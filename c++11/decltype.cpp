#include <iostream>

struct A { double x; };
const A* a;

decltype(a->x) y;       // type of y is double (declared type)
decltype((a->x)) z = y; // type of z is const double& (lvalue expression)

int main()
{
  int i = 33;
  decltype(i) j = i * 2;

  std::cout << "i = " << i << ", "
            << "j = " << j << '\n';

  auto f = [](int a, int b) -> int
           {
             return a * b;
           };

  decltype(f) g = f; // the type of a lambda function is unique and unnamed
  i = f(2, 2);
  j = g(3, 3);

  std::cout << "i = " << i << ", "
            << "j = " << j << '\n';
}
