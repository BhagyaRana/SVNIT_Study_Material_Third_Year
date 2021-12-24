// Shortest Job First Algorithm - BHAGYA RANA [U19CS012]

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

    // Constructor for Intializing
    Process(int id, int arrivalTime, int burstTime)
    {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
    }
};

// Compare F(x) for Sorting p
bool compare(const Process &p1, const Process &p2);

// Function for Shortest Job First Scheduling
void shortestJobFirst(vector<Process> &p);

// F(x) to Generate Random Input
vector<Process> randomInputGenerator(int n);

// F(x) to Print the Output in Well Structured Format
void printOutput(vector<Process> &p);

// F(x) to Call the Algorithm
void solve(vector<Process> &p);

int main()
{
    cout << "--------------------SHORTEST JOB FIRST ALGORITHM--------------------\n";

    int n;
    cout << "Enter Number of Processes : ";
    cin >> n;

    char choice;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "1 -> Random Input\n2 -> User Input\n\n";
    cout << "Enter Your Choice : ";
    cin >> choice;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

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
    {
        return p1.burstTime < p2.burstTime;
    }
    return p1.arrivalTime < p2.arrivalTime;
}

// Function for Shortest Job First Scheduling
void shortestJobFirst(vector<Process> &p)
{
    int temp, curr;

    // 1st process would complete 1st.
    p[0].completionTime = p[0].arrivalTime + p[0].burstTime;
    p[0].turnaroundTime = p[0].completionTime - p[0].arrivalTime;
    p[0].waitingTime = p[0].turnaroundTime - p[0].burstTime;

    // Now for other processes...
    for (int i = 1; i < p.size(); i++)
    {
        temp = p[i - 1].completionTime; // completion time

        // Burst Time: Time required by a process for CPU execution.
        int minBurst = p[i].burstTime;

        // Current index for swapping.
        curr = -1;

        while (curr == -1)
        {
            for (int j = i; j < p.size(); j++)
            {
                // If completion time >= arrive time =>[Implies] a process is in queue
                // if minBurst >= burstTime of curr process then, we need to swap.
                if (temp >= p[j].arrivalTime and minBurst >= p[j].burstTime)
                {
                    minBurst = p[j].burstTime;
                    curr = j;
                }
            }

            // If no such process found
            if (curr == -1)
                temp = p[i].arrivalTime;
        }

        // Time at which process completes its execution.= Completion Time
        p[curr].completionTime = temp + p[curr].burstTime;
        // Turn Around Time = Completion Time – Arrival Time
        p[curr].turnaroundTime = p[curr].completionTime - p[curr].arrivalTime;
        // Waiting Time = Turn Around Time – Burst Time
        p[curr].waitingTime = p[curr].turnaroundTime - p[curr].burstTime;

        // If process is found then swapping it with ith process.
        Process temp = p[i];
        p[i] = p[curr];
        p[curr] = temp;
    }
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
    cout << "Context Switch : 0\n\n";
}

// Function which will call other needed functions.
void solve(vector<Process> &p)
{
    sort(p.begin(), p.end(), compare);
    shortestJobFirst(p);
    printOutput(p);
}