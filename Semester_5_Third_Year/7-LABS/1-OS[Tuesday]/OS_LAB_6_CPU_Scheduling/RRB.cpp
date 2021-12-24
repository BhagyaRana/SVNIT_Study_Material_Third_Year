// Round Robin Algorithm - BHAGYA RANA [U19CS012]

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

// F(x) for Round Robin Scheduling
void roundRobin(vector<Process> &p, int interval);

// F(x) to Generate Random Input
vector<Process> randomInputGenerator(int n);

// F(x) to Print the Output in Well Structured Format
void printOutput(vector<Process> &p);

// F(x) to Call the Algorithm
void solve(vector<Process> &p, int interval);

int main()
{
    cout << "--------------------ROUND ROBIN ALGORITHM--------------------\n";

    int n;
    cout << "Enter Number of Processes : ";
    cin >> n;

    int interval;
    cout << "Enter Time Quantum for Round Robin : ";
    cin >> interval;

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

    solve(p, interval);

    return 0;
}

// Customized function for sorting
bool compare(const Process &p1, const Process &p2)
{
    return p1.arrivalTime < p2.arrivalTime;
}

// F(x) for Round Robin Scheduling
void roundRobin(vector<Process> &p, int interval)
{
    // Count Context Switch
    int contextSwitch = 0;
    int currTime = 0;
    int prev = -1;

    // Queue to maintain processes.
    queue<int> q;
    string time = "";
    string processFlow = "";

    // While all processes are not done.
    while (true)
    {
        bool flag = true;

        for (int i = 0; i < p.size(); i++)
        {
            if (p[i].remainingTime != 0)
            {
                flag = false;
                break;
            }
        }
        // If all processes are covered.
        if (flag)
            break;

        // If queue is empty, it means that there are no process currently in waiting.
        // Therefore, jumping to the next process by incrementing currTime.
        if (q.empty())
        {
            int prevTime = currTime;
            for (int i = 0; i < p.size(); i++)
            {
                if (p[i].remainingTime != 0)
                {
                    currTime = p[i].arrivalTime;
                    q.push(i);
                    int j = i + 1;
                    while (j < p.size() and p[j].arrivalTime == currTime and p[j].remainingTime > 0)
                    {
                        q.push(j);
                        j++;
                    }
                    break;
                }
            }
            for (int k = prevTime; k < currTime; k++)
                processFlow += " ";
        }

        // Popping the process from queue.
        int current = q.front();
        q.pop();

        // Incrementing context switch if the previous process is not completed
        // and also it's not the same as current process
        if (prev != -1 and prev != current)
            contextSwitch++;

        // If remaining time is greater than interval then we will minus interval time
        // and also add processes to queue which arrived in that interval.

        if (p[current].remainingTime > interval)
        {
            p[current].remainingTime -= interval;
            for (int j = current + 1; j < p.size(); j++)
            {
                if (p[j].arrivalTime > currTime and p[j].arrivalTime <= currTime + interval)
                    q.push(j);
            }

            q.push(current);
            currTime += interval;
            prev = current;

            for (int k = 0; k < interval; k++)
                processFlow += "P" + to_string(p[current].id) + " ";
        }
        // If remaining time is lesser than interval then we will make remaining time ZERO
        // and also add processes to queue which arrived in that time while the process was running.
        else
        {
            for (int j = current + 1; j < p.size(); j++)
            {
                if (p[j].arrivalTime > currTime and p[j].arrivalTime <= currTime + p[current].remainingTime)
                    q.push(j);
            }
            for (int k = 0; k < p[current].remainingTime; k++)
                processFlow += "P" + to_string(p[current].id) + " ";

            currTime += p[current].remainingTime;

            // Updating records for a process which is completed.
            p[current].remainingTime = 0;
            p[current].completionTime = currTime;
            p[current].turnaroundTime = currTime - p[current].arrivalTime;
            p[current].waitingTime = currTime - p[current].burstTime - p[current].arrivalTime;
            prev = -1;
        }
    }

    for (int k = 0; k < currTime; k++)
    {
        time += (to_string(k) + " ");
        if (k < 10)
            time += " ";
    }

    cout << "\n------------------------------GANTT---CHART------------------------------\n\n";
    cout << "Time : " + time << endl;
    cout << "Process : " + processFlow << endl;
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
void solve(vector<Process> &p, int interval)
{
    sort(p.begin(), p.end(), compare);
    roundRobin(p, interval);
    printOutput(p);
}