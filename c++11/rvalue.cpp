#include <utility>
#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

constexpr int len = 100;

class ExpensiveIfCopy
{
public:
    ExpensiveIfCopy() : data{new int[len]} {
        cout << "constructor\n";
    }

    ExpensiveIfCopy(const ExpensiveIfCopy &other) : data{new int[len]}
    {
        cout << "copy constructor\n";
        for (int i = 0; i < len; ++i)
        {
            data.get()[i] = other.data.get()[i];
        }
    }

    ExpensiveIfCopy &operator=(const ExpensiveIfCopy &other)
    {
        cout << "copy assignment\n";
        data.reset(new int[len]);
        for (int i = 0; i < len; ++i)
        {
            data.get()[i] = other.data.get()[i];
        }

        return *this;
    }

    ExpensiveIfCopy(ExpensiveIfCopy &&other)
    {
        cout << "move constructor\n";
        data = std::move(other.data);
    }

    ExpensiveIfCopy &operator=(ExpensiveIfCopy &&other)
    {
        cout << "move assignment\n";
        data = std::move(other.data);

        return *this;
    }

    ~ExpensiveIfCopy()
    {
        cout << "delete\n";
    }

    int& operator[](size_t index) {
        return data.get()[index];
    }

    const int& operator[](size_t index) const {
        return data.get()[index];
    }

    void zeroout() {
        memset(data.get(), 0, len);
    }

    bool valid() {
        return data != nullptr;
    }

private:
    std::unique_ptr<int> data;
};

int main()
{
    ExpensiveIfCopy e1;
    // copy constructor
    ExpensiveIfCopy e2(e1);
    cout << "e1 is valid: " << e1.valid() << endl
         << "e2 is valid: " << e2.valid() << endl;

    // move constructor
    ExpensiveIfCopy e3(move(e1));
    cout << "e1 is valid: " << e1.valid() << endl
         << "e2 is valid: " << e2.valid() << endl
         << "e3 is valid: " << e3.valid() << endl;

    // move assignment
    ExpensiveIfCopy e4;
    e4 = move(e3);
    cout << "e3 is valid: " << e3.valid() << endl;
    cout << "e4 is valid: " << e4.valid() << endl;

    // copy assignment
    ExpensiveIfCopy e5;
    e5 = e4;
    cout << "e3 is valid: " << e3.valid() << endl;
    cout << "e4 is valid: " << e4.valid() << endl;
    cout << "e5 is valid: " << e5.valid() << endl;
}
