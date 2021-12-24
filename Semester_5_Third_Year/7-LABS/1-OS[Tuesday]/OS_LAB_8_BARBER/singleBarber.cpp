// Include the Class Defined in "barberheader" Header File
#include "barberheader.hpp"
#include <thread>

// Maximum Number of Iterations
#define ITR 15
// Maximum Number of Random Customers
#define MAX_RAND_CUSTOMERS 7

int main()
{
    int size;
    cout << "Enter the size for the Waiting Room : ";
    cin >> size;

    cout << "~~~~~~~~~~~~~~~~~Initializing~~~~~~~~~~~~~~~~~" << endl;

    // Mutex for Handling Mutual Exclusion Problem in Sleeping Barber
    mutex mtx;
    // Mutex of Std Output {Print on Screen}
    mutex stdOutMtx;

    Barber barber(0);
    WaitingRoom room({size, queue<int>()});

    int itr = ITR;

    // Create a Thread
    thread barberThread(&Barber::doTask, ref(barber), ref(room), ref(mtx), ref(stdOutMtx), ref(itr));

    // Intially, there are no Customer in Shop
    int customer = 0;

    int temp = 0, newCustomers;

    // Randomly Customers will be Coming for itr iterations
    while (itr--)
    {
        newCustomers = rand() % MAX_RAND_CUSTOMERS;
        newCustomers = max(0, newCustomers);

        if (newCustomers > 0)
        {
            temp = 0;

            mtx.lock();
            // Add the Customer to Waiting Queue {If Possible}
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

    barberThread.join();

    cout << "~~~~~~~~~~~~~~~~~Task Completed~~~~~~~~~~~~~~~~~" << endl;

    return 0;
}
