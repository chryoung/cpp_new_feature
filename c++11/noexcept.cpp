#include <iostream>
#include <exception>

using namespace std;

int divide(bool& success, int a, int b) noexcept
{
  if (b == 0)
  {
    success = false;
    return 0;
  }

  success = true;
  return a / b;
}

int divide_violate(int a, int b) noexcept
{
  if (b == 0)
  {
    throw runtime_error("Divided by zero");
  }
  return a / b;
}


int main()
{
  bool is_divided = false;
  cout << divide(is_divided, 8, 2) << endl;
  cout << divide(is_divided, 1, 0) << endl;
  cout << divide(is_divided, 0, 0) << endl;
  try
  {
    divide_violate(1, 0);
  }
  catch (exception& e) // will not catch because of noexcept
  {
    cout << e.what();
  }
}
