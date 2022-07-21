#include <bits/stdc++.h>
using namespace std;

class base
{
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; cout << "Base" << endl;}

private:
    string basename;
};

class derived : public base
{
public:
    // void print(ostream &os)
    // {
    //     print(os);
    //     os << " " << i;
    // }
    // call itself within function body causes infinite recursion.
    void print(ostream &os) override
    {
        cout << "Hi";
        base::print(os);
        os << " " << i;
    }

private:
    int i;
};

int main()
{
    base bobj;
    derived dobj;
    base *bp1 = &bobj;
    base *bp2 = &dobj;
    base &br1 = bobj;
    base &br2 = dobj;

    // bobj.print(cout); // base::print
    // dobj.print(cout); // derived::print
    // bp1->name();      // base::name
    // bp2->name();      // base::name
    // br1.print(cout);  // base::print
    br2.print(cout);  // derived::print

    return 0;
}
