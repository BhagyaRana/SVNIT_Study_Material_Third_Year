// This is General Header File that Contains the Barber Class
#include <unistd.h>
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>

using namespace std;

// Waiting Room of 'n' Seats
struct WaitingRoom
{
    int TotalSeats;
    queue<int> Customers;
};

// Defination of Barber Class
class Barber
{

private:
    // ID of Barber
    int id;

public:
    // Default Constructor
    Barber() {}

    // Constructor with ID
    Barber(int id)
    {
        this->id = id;
    }

    // Member Function for Hair Cutting Task {itrs -> Iterations}
    void doTask(WaitingRoom &room, mutex &mtx, mutex &stdOutMtx, int &itrs)
    {

        while (true)
        {
            mtx.lock();

            // If Number of Iterations are Zero and No Customer in Waiting Room
            if (itrs == -1 && room.Customers.empty())
            {
                mtx.unlock();
                break;
            }

            // If there is Customer in Waiting Room
            if (!room.Customers.empty())
            {
                // The Customer who Came First, Should be Served First
                int toBeServed = room.Customers.front();
                room.Customers.pop();

                mtx.unlock();
                sleep(1);

                // Mutex to Print the Output {Standarr Output}
                stdOutMtx.lock();
                cout << "Barber: " << this->id << " has done the task for the customer : " << toBeServed << endl;
                stdOutMtx.unlock();
            }
            else
            {
                mtx.unlock();
                sleep(1);
            }
        }
    }
};
