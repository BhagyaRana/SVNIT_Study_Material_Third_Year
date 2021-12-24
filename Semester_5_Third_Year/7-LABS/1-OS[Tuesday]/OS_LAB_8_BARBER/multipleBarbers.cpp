// Include the Class Defined in "barberheader" Header File
#include "barberheader.hpp"
#include <thread>

// Maximum Number of Iterations
#define ITR 15
// Maximum Number of Random Customers
#define MAX_RAND_CUSTOMERS 7

// Same Code from Single Barber is Modified for Multiple Barbers

int main()
{
    int size, barberCount;

    cout << "Enter the size for Waiting Room : ";
    cin >> size;

    cout << "Enter the number of Barbers     : ";
    cin >> barberCount;

    cout << "~~~~~~~~~~~~~~~~~Initializing~~~~~~~~~~~~~~~~~" << endl;

    // Mutex for Handling Mutual Exclusion Problem in Sleeping Barber
    mutex mtx;
    // Mutex of Std Output {Print on Screen}
    mutex stdOutMtx;

    WaitingRoom room({size, queue<int>()});

    int itr = ITR;

    Barber barbers[barberCount];

    // Create 1 Thread for Each Barber
    thread barberThreads[barberCount];

    for (int i = 0; i < barberCount; i++)
    {
        barbers[i] = Barber(i);
        barberThreads[i] = thread(&Barber::doTask, ref(barbers[i]), ref(room), ref(mtx), ref(stdOutMtx), ref(itr));
    }

    int customer = 0;
    int temp = 0;
    int newCustomers;

    // Randomly Customers will be Coming for itr iterations
    while (itr--)
    {
        newCustomers = rand() % MAX_RAND_CUSTOMERS;
        newCustomers = max(0, newCustomers);

        if (newCustomers > 0)
        {
            temp = 0;

            mtx.lock();
            while (newCustomers-- && room.Customers.size() < room.TotalSeats)
            {
                room.Customers.push(customer++);
                temp++;
            }
            mtx.unlock();
        }

        // Print the Output on Screen
        stdOutMtx.lock();
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Iteration Number is : " << itr << endl;
        cout << "Customers Added are : " << temp << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        stdOutMtx.unlock();

        sleep(1);
    }

    for (int i = 0; i < barberCount; i++)
        barberThreads[i].join();

    cout << "~~~~~~~~~~~~~~~~~Task Completed~~~~~~~~~~~~~~~~~" << endl;

    return 0;
}