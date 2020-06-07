#include <type_traits>
#include <iostream>

using namespace std;

void foo() { }

class Bar
{
public:
  virtual void Task() { }
};

class BarA
  : public Bar
{
public:
  void Task() override
  {
    cout << "BarA" << endl;
  }
};

class BarB
  : public Bar
{
public:
  void Task() override
  {
    cout << "BarB" << endl;
  }
};

int main()
{
  cout << is_function<decltype(foo)>::value << endl;
  cout << is_class<Bar>::value << endl;
  cout << is_polymorphic<Bar>::value << endl;
  cout << is_polymorphic<BarA>::value << endl;
  cout << is_polymorphic<BarB>::value << endl;
}