#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main()
{
  string s{"Hello, World!"};
  int num_upper = 0;
  for_each(s.cbegin(), s.cend(), [&num_upper](char c) {
    if (isupper(c))
    {
      ++num_upper;
    }
  });

  cout << num_upper << " uppercase letters in " << s << endl;
}
