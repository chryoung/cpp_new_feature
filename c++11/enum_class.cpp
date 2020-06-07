#include <iostream>

using namespace std;

enum class RGB
{
  Red = 0,
  Green = 1,
  Blue = 2,
};

int main()
{
  RGB rgb = RGB::Green;

  switch (rgb)
  {
    case RGB::Red:
      cout << "Hot red\n";
      break;
    case RGB::Green:
      cout << "Spring green\n";
      break;
    case RGB::Blue:
      cout << "Ocean blue\n";
      break;
    default:
      break;
  }

  return 0;
}