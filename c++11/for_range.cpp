#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  srand(time(nullptr));
  vector<int> v(10);

  for (auto& i : v)
  {
    i = rand() % 100;
  }

  for (const auto& i : v)
  {
    cout << i << " ";
  }

  cout << endl;
}
