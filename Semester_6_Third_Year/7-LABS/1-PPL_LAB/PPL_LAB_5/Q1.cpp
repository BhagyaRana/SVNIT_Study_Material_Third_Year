struct Base
{
    void bar(int); // public by default
protected:
    int ival;
};

struct Derived1 : virtual public Base
{
    void bar(char); // public by default
    void foo(char);

protected:
    char cval;
};

struct Derived2 : virtual public Base
{
    void foo(int); // public by default
protected:
    int ival;
    char cval;
};

class VMI : public Derived1, public Derived2
{
};
