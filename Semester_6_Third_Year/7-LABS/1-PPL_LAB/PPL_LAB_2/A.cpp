#include <iostream>
#include <iostream>
using namespace std;

// Modifies the Values in a,b to a+b, absolute(a-b)
void modify(int *a, int *b);

int main()
{
    int a, b;

    // addr_a - stores the memory address of variable 'a'
    int *addr_a = &a;
    // addr_b - stores the memory address of variable 'b'
    int *addr_b = &b;

    cout << "Enter Values of 'a' and 'b' : ";
    cin >> a >> b;

    // Function call to Modify the Values
    modify(addr_a, addr_b);

    cout << "Modified Values [ a+b, |a-b|] : ";
    cout << a << " " << b << endl;

    return 0;
}

// Modifies the Values in a,b to a+b, absolute(a-b)
void modify(int *a, int *b)
{
    // Method 1

    // Store the Value of a in tmp variable
    int tmp = *a;
    // Modify a -> a + b
    *a = *a + *b;

    // b -> abs(a-b) [Note: We have stores the Intial Value of a in tmp]
    *b = tmp - *b;

    // If val of b is negative, Multiply it by -1 to make it Positive
    if (*b < 0)
        *b = (*b) * (-1);

    // Short Method 2
    // *a = (*a) + (*b);
    // Effective (a+b)-(2*b) => a-b
    // *b = (*a) - (2 * (*b));

    // If val of b is negative, Multiply it by -1 to make it Positive
    // if (*b < 0)
    //     *b = (*b) * (-1);

    return;
}
