#include <iostream>
#include <utility>


class Foo final
{
public:
    // Constructor
    Foo() = default;
    // Deconstructor
    ~Foo() = default;
    // Copy constructor
    Foo(const Foo& other) = default;
    // Move constructor
    Foo(Foo&& other) = default;

    void Show();
private:
    int value = 0;
};

void Foo::Show()
{
    std::cout << value << "\n";
}

class Bar
{
public:
    Bar() = default;
    ~Bar() = default;
    // Delete copy constructor
    Bar(const Bar& other) = delete;
private:
    double value = 3.14159;
};

int main()
{
    Foo foo;
    Foo foo2(foo);
    foo.Show();
    foo2.Show();

    Foo foo3(std::move(foo2));
    foo3.Show();

    Bar bar;
    // Below is not allowed
    // Bar bar2(bar);
}