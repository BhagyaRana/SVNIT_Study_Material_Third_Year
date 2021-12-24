// Shortest Remaining Time First Algorithm - BHAGYA RANA [U19CS012]

#include <bits/stdc++.h>
using namespace std;

// "Process" Class
class Process
{
public:
    // Process ID
    int id;
    // Arrival Time: Time at which the process arrives in the ready queue.
    int arrivalTime;
    // Burst Time: Time required by a process for CPU execution.
    int burstTime;
    // Completion Time: Time at which process completes its execution.
    int completionTime;
    // Turn Around Time: Time Difference between completion time and arrival time.
    int turnaroundTime;
    // Waiting Time(W.T): Time Difference between turn around time and burst time.
    int waitingTime;
    int remainingTime;

    // Constructor for Intializing
    Process(int id, int arrivalTime, int burstTime)
    {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->remainingTime = burstTime;
    }
};

// Compare F(x) for Sorting p
bool compare(const Process &p1, const Process &p2);

// Function for Shortest Remaining Time First Scheduling
void shortestRemainingTimeFirst(vector<Process> &p);

// F(x) to Generate Random Input
vector<Process> randomInputGenerator(int n);

// F(x) to Print the Output in Well Structured Format
void printOutput(vector<Process> &p);

// F(x) to Call the Algorithm
void solve(vector<Process> &p);

int main()
{
    cout << "--------------------SHORTEST REMAINING TIME FIRST ALGORITHM--------------------\n";

    int n;
    cout << "Enter Number of Processes : ";
    cin >> n;

    char choice;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "1 -> Random Input\n2 -> User Input\n\n";
    cout << "Enter Your Choice : ";
    cin >> choice;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

    vector<Process> p;
    if (choice == '1')
    {
        p = randomInputGenerator(n);
        cout << "Randomly generated inputs are : " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Arrival time and Burst time of Process " << p[i].id << " : " << p[i].arrivalTime << " " << p[i].burstTime << endl;
        }
    }
    else if (choice == '2')
    {
        for (int i = 0; i < n; i++)
        {
            int arriveTime, burstTime;
            cout << "Enter Arrival time and Burst time of Process " << i + 1 << " : ";
            cin >> arriveTime >> burstTime;
            p.push_back(Process(i + 1, arriveTime, burstTime));
        }
    }
    else
    {
        cout << "Incorrect Input Entered\n";
        return 0;
    }

    solve(p);

    return 0;
}

// Customized function for sorting
bool compare(const Process &p1, const Process &p2)
{
    if (p1.arrivalTime == p2.arrivalTime)
        return p1.burstTime < p2.burstTime;
    return p1.arrivalTime < p2.arrivalTime;
}

// Function for Shortest Job First Scheduling
void shortestRemainingTimeFirst(vector<Process> &p)
{
    // Count No. of Context Switch
    int contextSwitch = 0, done = 0, currTime = 0, minRemainTime = INT_MAX, minProcess = 0;
    bool flag = false;

    // For Gantt Chart
    string time, processFlow;

    // Loop till all processes are completed.
    while (done != p.size())
    {
        time += to_string(currTime) + " ";
        if (currTime < 10)
            time += " ";

        bool flagTemp = false;

        //Checking every process to find process with minimum remaining time.
        for (int i = 0; i < p.size(); i++)
        {
            // Condition for minimum remaining time.
            if (p[i].arrivalTime <= currTime and p[i].remainingTime < minRemainTime and p[i].remainingTime > 0)
            {
                // a new process is executed i.e. no context switch
                if (minRemainTime == INT_MAX)
                    flagTemp = true;

                minRemainTime = p[i].remainingTime;
                minProcess = i;
                flag = true;

                if (flagTemp)
                    continue;

                // Increasing context switch count
                contextSwitch += 1;
            }
        }

        // No process in queue with minimum remaining time.
        if (!flag)
        {
            if (minRemainTime == INT_MAX)
                processFlow += "	";
            else
                processFlow += "P" + to_string(p[minProcess].id) + " ";

            currTime++;
            continue;
        }

        processFlow += "P" + to_string(p[minProcess].id) + " ";

        //Decrementing remaining time of the feasible process.
        p[minProcess].remainingTime -= 1;
        // Update minRemainTime
        minRemainTime = p[minProcess].remainingTime;

        if (minRemainTime == 0)
        {
            // Process is completed therefore resetting.
            minRemainTime = INT_MAX;
            // Increase completed process count
            done += 1;

            flag = false;
            // Updating Data for a process
            p[minProcess].completionTime = currTime + 1;

            p[minProcess].waitingTime = p[minProcess].completionTime - p[minProcess].burstTime - p[minProcess].arrivalTime;

            if (p[minProcess].waitingTime < 0)
                p[minProcess].waitingTime = 0;

            p[minProcess].turnaroundTime = p[minProcess].waitingTime + p[minProcess].burstTime;
        }
        currTime += 1;
    }

    cout << "\n------------------------------GANTT---CHART------------------------------\n";
    cout << "Time	: " + time + to_string(currTime) << endl;
    cout << "Process	: " + processFlow << endl;
    cout << "Total Number of Context Switching : " << contextSwitch << endl;
}

// Function to generate random input
vector<Process> randomInputGenerator(int n)
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> d1(0, ((10 * n) + 1) / 2);
    uniform_int_distribution<int> d2(1, 10);

    vector<Process> p;

    for (int i = 0; i < n; i++)
    {
        p.push_back(Process(i + 1, d1(generator), d2(generator)));
        d1.reset();
    }
    return p;
}

// Referrence : https://stackoverflow.com/questions/14765155/how-can-i-easily-format-my-data-table-in-c
template <typename T>
void printElement(T t)
{
    cout << left << setw(17) << setfill(' ') << t;
}

// Utility function to print Output
void printOutput(vector<Process> &p)
{
    int TotalWaiting = 0, TotalTurnAround = 0;
    cout << "\n----------------------------------SCHEDULED---PROCESS---DETAILS----------------------------------\n\n";

    printElement("Process ID");
    printElement("Arrival Time");
    printElement("Burst Time");
    printElement("Completion Time");
    printElement("Turn Around Time");
    printElement("Waiting Time");
    cout << endl;

    for (int i = 0; i < p.size(); i++)
    {
        cout << "     ";
        printElement(p[i].id);
        printElement(p[i].arrivalTime);
        printElement(p[i].burstTime);
        printElement(p[i].completionTime);
        printElement(p[i].turnaroundTime);
        printElement(p[i].waitingTime);

        cout << endl;

        TotalWaiting += p[i].waitingTime;
        TotalTurnAround += p[i].turnaroundTime;
    }

    cout << "\n----------------------------------SCHEDULED---PROCESS---SUMMARY----------------------------------\n\n";

    cout << "Average Waiting Time : " << (double)TotalWaiting / (double)p.size() << endl;
    cout << "Average Turn Around Time : " << (double)TotalTurnAround / (double)p.size() << endl;
}

// Function which will call other needed functions.
void solve(vector<Process> &p)
{
    sort(p.begin(), p.end(), compare);
    shortestRemainingTimeFirst(p);
    printOutput(p);
}