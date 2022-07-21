// For Basic IO
#include <iostream>
// For setprecision
#include <iomanip>
// For Time Calculation
#include <chrono>

using namespace std;
using namespace std::chrono;

// [U19CS012] BHAGYA VINOD RANA

// Maximum Number of Calls
const int MAX_CALLS = 1000000;

// Complex Calculation
void complex_calc()
{
    long long int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        sum += i;
    }
}

// Base Class
class base
{
public:
    // Statically Bound
    void fun_1() { complex_calc(); }
    // Dynamically Bound
    virtual void fun_2() { complex_calc(); }
};

// Derived Class
class derived : public base
{
public:
    // This was Just to Confuse
    void fun_1() { cout << "derived-1\n"; }
    void fun_2() { complex_calc(); }
};

void menu()
{
    cout << "------------------------------------------------------------\n";
    cout << "1 -> Statically Bound Method\n";
    cout << "2 -> Dynamically Bound Method\n";
    cout << "3 -> Exit\n";
    cout << "------------------------------------------------------------\n";
}

int main()
{
    base *p;
    base t;
    derived obj1;
    p = &obj1;

    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    double time_taken = duration_cast<nanoseconds>(end - start).count();

    int choice = 1;
    while (true)
    {
        menu();
        cout << "Enter you Choice [1/2/3] : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // Static Bind
            start = high_resolution_clock::now();

            for (int i = 0; i < MAX_CALLS; i++)
                p->fun_1();

            end = high_resolution_clock::now();

            // Calculating total time taken by the Static Bind.
            time_taken = duration_cast<nanoseconds>(end - start).count();
            time_taken *= 1e-9;
            cout << "Time taken by Statically Bound Method is : " << fixed << time_taken << setprecision(9);
            cout << " sec" << endl;

            break;

        case 2:
            // Dynamic Bind
            start = high_resolution_clock::now();

            for (int i = 0; i < MAX_CALLS; i++)
            {
                p->fun_2();

                // if (i & 1)
                // {
                //     // fun_2 inside of derived class
                //     p->fun_2();
                // }
                // else
                // {
                //     // fun_2 inside of base class
                //     p = &t;
                //     p->fun_2();
                // }
            }

            end = high_resolution_clock::now();

            // Calculating total time taken by the Static Bind.
            time_taken = duration_cast<nanoseconds>(end - start).count();
            time_taken *= 1e-9;
            cout << "Time taken by Dynamically Bound Method is : " << fixed << time_taken << setprecision(9);
            cout << " sec" << endl;
            break;
        case 3:
            cout << "\nStatic Vs Dynamic Bind Comparision Done Successfully!\n";
            return 0;
            break;
        default:
            cout << "Enter Valid Input! Please Try Again!\n";
        }
    }

    return 0;
}