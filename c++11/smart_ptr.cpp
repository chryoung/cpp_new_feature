#include <memory>
#include <iostream>

using namespace std;

struct Resource
{
    Resource() = default;
    ~Resource() = default;
    bool Consume()
    {
        if (quantity > 0)
        {
            --quantity;
            return true;
        }

        return false;
    }

    int quantity = 10;
};

struct Manager
{
    shared_ptr<Resource> resource;
};

int main()
{
    unique_ptr<Manager> man1{new Manager};
    unique_ptr<Manager> man2{new Manager};
    shared_ptr<Resource> resource_a{make_shared<Resource>()};
    man1->resource = resource_a;
    man2->resource = resource_a;

    man1->resource->Consume();
    man2->resource->Consume();
    cout << resource_a->quantity << "\n";
}