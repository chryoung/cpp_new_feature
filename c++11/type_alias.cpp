#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using Ownership = std::unordered_map<std::string, std::vector<std::string>>;

int main()
{
  Ownership ownership;
  ownership["Alice"] = {"Apple", "Banana"};
  for (const auto& who : ownership)
  {
    for (const auto& what: who.second)
    {
      std::cout << who.first << " has " << what << "." << std::endl;
    }
  }

  return 0;
}
