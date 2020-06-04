#include <iostream>

using namespace std;

void Show(int* number)
{
    if (!number)
    {
        cout << "nullptr" << endl;
    }
    else
    {
        cout << *number << endl;
    }
    
}

void Show(int number)
{
    cout << number << endl;
}

int main()
{
    Show(0);
    Show(nullptr);
}