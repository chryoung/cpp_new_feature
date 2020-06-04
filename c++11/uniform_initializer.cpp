#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int i{5};
  double d{0.5};
  int iv[5]{5, 4, 3, 2, 1};
  vector<int> v{1, 2, 3, 4, 5};
  string s{"Hello, world!"};

  cout << i << endl
       << d << endl
       << s << endl;
  for (const auto &i : iv)
  {
    cout << i << " ";
  }

  cout << endl;

  for (const auto &i : v)
  {
    cout << i << " ";
  }

  cout << endl;
}
