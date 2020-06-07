#include <iostream>

using namespace std;

class IntContainer
{
public:
  virtual int get() { return 0; }
  virtual void set(int x) = 0;
};

class WholeIntContainer
  : public IntContainer
{
public:
  int get() override { return value; };
  void set(int x) final { value = x; };
protected:
  int value = 0;
};

class HalfIntContainer final
  : public WholeIntContainer
{
public:
  int get() override { return WholeIntContainer::get() * 0.5; };
  // this is not allowed
  // void set(int x) override { value = x * 2; };
};

int main()
{
  WholeIntContainer w;
  HalfIntContainer h;

  w.set(50);
  cout << w.get() << endl;

  h.set(1000);
  cout << h.get() << endl;

  return 0;
}