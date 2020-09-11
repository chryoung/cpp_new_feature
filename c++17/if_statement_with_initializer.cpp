#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
   srand(time(nullptr));
   // C++17 if statement with initializer
   if (int random_num = rand(); random_num % 2 == 0) {
      cout << random_num << " is an even number\n";
   } else {
      cout << random_num << " is an odd number\n";
   }
   return 0;
}
