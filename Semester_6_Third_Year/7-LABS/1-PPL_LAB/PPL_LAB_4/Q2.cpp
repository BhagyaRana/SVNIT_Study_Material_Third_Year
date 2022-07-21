#include <iostream>
using namespace std;

class A
{
public:
    virtual void method()
    {
        cout << "Method From -> class A\n";
    }

    // Constructor
    A()
    {
        method();
    }
};

// B class is derived from base class A.
class B : public A
{
public:
    void method()
    {
        cout << "Method From -> class B\n";
    }
};

// C class is derived from base class B.
class C : public B
{
public:
    void method()
    {
        cout << "Method From -> class C\n";
    }
};

int main()
{
    A *a;

    cout << "\nCall that is Statically Bound to A's Method\n";
    A tmp;
    a = &tmp;

    cout << "\nCall Dynamically Bound to B's Method\n";
    B b;
    a = &b;
    a->method();

    cout << "\nCall Dynamically Bound to C's Method\n";
    C c;
    a = &c;
    a->method();

    return 0;
}