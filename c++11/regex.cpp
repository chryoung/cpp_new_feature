#include <regex>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    if (regex_match("World is beautiful", regex("World.*$")))
    {
        cout << "Match!" << endl;
    }

    string str1{"Have you questioned the nature of your reality?"};
    smatch m1;
    if (regex_match(str1, m1, regex(".*(questioned)(.*)")))
    {
        cout << "Matched " << m1.size() << endl;
        cout << "All groups:" << endl;
        for (auto& m : m1)
        {
            cout << m << endl;
        }

        cout << "Group 0: " << m1[0] << endl;
    }

    return 0;
}