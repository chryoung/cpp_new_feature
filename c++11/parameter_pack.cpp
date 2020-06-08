#include <iostream>
#include <tuple>
#include <utility>

template<class T>
void f(T x)
{
  std::cout << x << "\nEnd\n";
}

template<class T, class ...U>
void f(T x, U... rest)
{
  std::cout << x << " ";
  f(rest...);
}

template<class ...T>
void g(T... args)
{
  f(args...);
}

template<class ...T>
void h(T&&... args)
{
  std::tuple<T...> t{std::forward<T>(args)...};

  std::cout << std::tuple_size<decltype(t)>::value << std::endl;
}

int main()
{
  g(1, 3.14, 'c', "Hello, world");
  h(1, 3.14, 'c', "Hello, world");

  return 0;
}