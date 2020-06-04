#include <iostream>

using namespace std;

class Coordinate
{
public:
    Coordinate(int x, int y): x{x}, y{y} { }
    Coordinate(): Coordinate(0, 0) { }
    friend ostream& operator<<(ostream& out, const Coordinate& c);
private:
    int x;
    int y;
};

ostream& operator<<(ostream& out, const Coordinate& c)
{
    out << "(" << c.x << ", " << c.y << ")";

    return out;
}

int main()
{
    Coordinate c1(1, 1);
    Coordinate origin;

    cout << c1 << endl;
    cout << origin << endl;
}