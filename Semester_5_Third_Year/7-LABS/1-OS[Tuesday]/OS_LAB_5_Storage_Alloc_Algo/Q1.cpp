#include <bits/stdc++.h>
using namespace std;

// Structure of Process Node
class Node
{
public:
    int start;
    int end;
    int size;
    int id;
    Node *next;
    Node(int start, int end)
    {
        this->start = start;
        this->end = end;
        this->size = end - start + 1;
        this->id = -1;
        this->next = NULL;
    }
};

Node *memory = NULL;

// F(x) to Print all the Choice to User [In Particular Algorithm]
void printSubChoice();

// F(x) to Check if Process Exist or Not
bool checkProcess(int processId);

// F(x) to Deallocate the Memory
void DeallocateMemory();

// F(x) to Allocate Memory Using First Fit Algorithm
void firstFit();

// F(x) to Allocate Memory Using Best Fit Algorithm
void bestFit();

// F(x) to Allocate Memory Using Worst Fit Algorithm
void worstFit();

// F(x) to Print Memory Segment Details
void printMemorySegment(Node *node);

// F(x) to Display Final Summary
void displayAll();

// F(x) to Display Allocated Memory
void displayAllocated();

// Utility Function for First Fit Algorithm
void firstFitUtil();

// Utility Function for Best Fit Algorithm
void bestFitUtil();

// Utility Function for Worst Fit Algorithm
void worstFitUtil();

// F(x) to Print Menu of Various Algorithm
void printMainChoice();

// F(x) to Select Algorithm Based on Used Input
void selectAlgorithm();

int main()
{
    int noPartitions;
    cout << "Enter No. of Partitions in Memory : ";
    cin >> noPartitions;

    Node *curr;

    for (int i = 0; i < noPartitions; i++)
    {
        int start, end;
        cout << "Starting and Ending Address of partition " << i + 1 << " : ";
        cin >> start >> end;

        Node *newNode = new Node(start, end);

        if (memory == NULL)
        {
            memory = newNode;
            curr = memory;
        }
        else
        {
            curr->next = newNode;
            curr = curr->next;
        }
    }

    selectAlgorithm();
    return 0;
}

// F(x) to Print all the Choice to User [In Particular Algorithm]
void printSubChoice()
{
    cout << "	" << endl;
    cout << "1 -> Entry / Allocate" << endl;
    cout << "2 -> Exit / Deallocate" << endl;
    cout << "3 -> Display Whole Memory" << endl;
    cout << "4 -> Display Allocated Memory" << endl;
    cout << "5 -> Back to Algorithm" << endl;
    cout << "	" << endl;
}

// F(x) to Check if Process Exist or Not
bool checkProcess(int processId)
{
    Node *tmp = memory;
    bool flag = false;
    while (tmp != NULL)
    {
        if (tmp->id == processId)
        {
            flag = true;
            break;
        }
        tmp = tmp->next;
    }
    return flag;
}

// F(x) to Allocate Memory Using First Fit Algorithm
void firstFit()
{
    int processId;
    int sizeNeeded;
    cout << "Enter the Process Id : ";

    cin >> processId;

    // Validation of Input from User
    if (checkProcess(processId))
    {
        cout << "Invalid Process Id" << endl;
        return;
    }

    cout << "Enter Size required by Process : ";
    cin >> sizeNeeded;

    Node *tmp = memory;
    bool flag = false;

    while (tmp != NULL)
    {
        // If Size of Block is >= than Requirement and Not Visited
        if (tmp->size >= sizeNeeded and tmp->id == -1)
        {
            // Mark it Visited
            tmp->id = processId;

            int startP = tmp->start;
            int endP = startP + sizeNeeded - 1;
            int newStart = endP + 1;

            // There is Some Remaining Space in Block
            if (newStart <= tmp->end)
            {
                Node *newNode = new Node(newStart, tmp->end);
                tmp->end = endP;
                tmp->size = sizeNeeded;
                newNode->next = tmp->next;
                tmp->next = newNode;
            }

            cout << "Memory Allocated Succesfully!" << endl;
            flag = true;
            break;
        }

        tmp = tmp->next;
    }

    if (!flag)
    {
        cout << "Can't Allocate the memory for this process!" << endl;
    }
}

// F(x) to Allocate Memory Using Best Fit Algorithm
void bestFit()
{
    int processId;
    int sizeNeeded;
    cout << "Enter the process Id : ";
    cin >> processId;
    if (checkProcess(processId))
    {
        cout << "Invalid Process Id" << endl;
        return;
    }
    cout << "Enter required size by process : ";
    cin >> sizeNeeded;

    Node *tmp = memory;
    bool flag = false;
    Node *ans;

    int maxSize = INT_MAX;

    while (tmp != NULL)
    {
        if (tmp->size >= sizeNeeded and tmp->id == -1 and tmp->size < maxSize)
        {

            flag = true;
            ans = tmp;
            maxSize = tmp->size;
        }
        tmp = tmp->next;
    }
    if (!flag)
    {
        cout << "Can't allocate the memory for this process!" << endl;
        return;
    }

    ans->id = processId;
    int startP = ans->start;
    int endP = startP + sizeNeeded - 1;
    int newStart = endP + 1;

    if (newStart <= ans->end)
    {
        Node *newNode = new Node(newStart, ans->end);
        ans->end = endP;
        ans->size = sizeNeeded;
        newNode->next = ans->next;
        ans->next = newNode;
    }
    cout << "Memory allocated succesfully!" << endl;
}

// F(x) to Allocate Memory Using Worst Fit Algorithm
void worstFit()
{
    int processId;
    int sizeNeeded;
    cout << "Enter the process Id : ";
    cin >> processId;
    if (checkProcess(processId))
    {
        cout << "Invalid Process Id" << endl;
        return;
    }
    cout << "Enter required size by process : ";
    cin >> sizeNeeded;

    Node *tmp = memory;
    bool flag = false;
    Node *ans;
    int maxSize = -1;

    while (tmp != NULL)
    {
        if (tmp->size >= sizeNeeded and tmp->id == -1 and tmp->size > maxSize)
        {

            flag = true;
            ans = tmp;
            maxSize = tmp->size;
        }
        tmp = tmp->next;
    }
    if (!flag)
    {
        cout << "Can't allocate the memory for this process!" << endl;
        return;
    }

    ans->id = processId;
    int startP = ans->start;
    int endP = startP + sizeNeeded - 1;
    int newStart = endP + 1;

    if (newStart <= ans->end)
    {
        Node *newNode = new Node(newStart, ans->end);
        ans->end = endP;
        ans->size = sizeNeeded;
        newNode->next = ans->next;
        ans->next = newNode;
    }
    cout << "Memory allocated succesfully!" << endl;
}

// F(x) to Deallocate the Memory
void DeallocateMemory()
{
    int processId;
    cout << "Enter the Process ID to be Deallocated : ";
    cin >> processId;

    bool flag = false;
    Node *tmp = memory;

    int offset = 0;

    // Traverse the Linked List to Find the Process to be Deallocated
    while (tmp != NULL)
    {
        if (tmp->id == processId)
        {
            flag = true;
            tmp->id = -1;
            break;
        }
        tmp = tmp->next;
        offset++;
    }

    // If Not Found
    if (!flag)
    {
        cout << "No Such process is running ! " << endl;
        return;
    }

    tmp = memory;

    while (tmp != NULL and tmp->next != NULL)
    {
        if (tmp->end + 1 == tmp->next->start and tmp->id == -1 and tmp->next->id == -1)
        {
            tmp->end = tmp->next->end;
            tmp->size = tmp->end - tmp->start + 1;

            Node *toDelete = tmp->next;
            tmp->next = tmp->next->next;
            delete toDelete;
        }
        else
        {
            tmp = tmp->next;
        }
    }

    cout << "Process Exited Successfully, Memory Freed!" << endl;
}

// F(x) to Print Memory Segment Details
void printMemorySegment(Node *node)
{
    cout << "	" << endl;
    cout << "Start : " << node->start << endl;
    cout << "End : " << node->end << endl;
    cout << "Size : " << node->size << endl;
    if (node->id != -1)
    {
        cout << "Process Id : " << node->id << endl;
    }
    else
    {
        cout << "No process Allocated" << endl;
    }
}

// F(x) to Display Final Summary
void displayAll()
{
    Node *tmp = memory;

    int totalMemory = 0;
    int freeMemory = 0;

    while (tmp != NULL)
    {
        if (tmp->id == -1)
        {
            freeMemory += tmp->size;
        }
        totalMemory += tmp->size;
        printMemorySegment(tmp);
        tmp = tmp->next;
    }

    cout << "	" << endl;
    cout << "Total memory : " << totalMemory << endl;
    cout << "Free memory : " << freeMemory << endl;
    cout << "Allocated memory : " << totalMemory - freeMemory << endl;
    cout << "	" << endl;
}

// F(x) to Display Allocated Memory
void displayAllocated()
{
    Node *tmp = memory;
    int allocatedMemory = 0;
    while (tmp != NULL)
    {
        if (tmp->id != -1)
        {
            allocatedMemory += tmp->size;
            printMemorySegment(tmp);
        }

        tmp = tmp->next;
    }
    cout << "	" << endl;
    cout << "Allocated memory : " << allocatedMemory << endl;
    cout << "	" << endl;
}

// Utility Function for First Fit Algorithm
void firstFitUtil()
{
    int subChoice = -1;
    while (subChoice != 5)
    {
        printSubChoice();
        cout << "Choice : ";
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
        {
            firstFit();
            break;
        }
        case 2:
        {
            DeallocateMemory();
            break;
        }
        case 3:
        {
            displayAll();
            break;
        }
        case 4:
        {
            displayAllocated();
            break;
        }
        case 5:
        {
            cout << "Back to Main Menu (<-)" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Input! " << endl;
            break;
        }
        }
    }
}

// Utility Function for Best Fit Algorithm
void bestFitUtil()
{
    int subChoice = -1;
    while (subChoice != 5)
    {
        printSubChoice();
        cout << "Choice : ";
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
        {
            bestFit();

            break;
        }
        case 2:
        {
            DeallocateMemory();
            break;
        }
        case 3:
        {
            displayAll();
            break;
        }
        case 4:
        {
            displayAllocated();
            break;
        }
        case 5:
        {
            cout << "Back to Main Menu (<-)" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Input\n";
            break;
        }
        }
    }
}

// Utility Function for Worst Fit Algorithm
void worstFitUtil()
{
    int subChoice = -1;
    while (subChoice != 5)
    {
        printSubChoice();
        cout << "Choice : ";
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
        {
            worstFit();
            break;
        }
        case 2:
        {
            DeallocateMemory();
            break;
        }
        case 3:
        {
            displayAll();
            break;
        }
        case 4:
        {
            displayAllocated();
            break;
        }
        case 5:
        {
            cout << "Back to Main Menu (<-)" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Input\n";
            break;
        }
        }
    }
}

// F(x) to Print Menu of Various Algorithm
void printMainChoice()
{
    cout << "	" << endl;
    cout << "Select the Algorithm" << endl;
    cout << "1 -> First Fit Algorithm" << endl;
    cout << "2 -> Best Fit Algorithm" << endl;
    cout << "3 -> Worst Fit Algorithm" << endl;
    cout << "4 -> Exit the App" << endl;
    cout << "	" << endl;
}

// F(x) to Select Algorithm Based on Used Input
void selectAlgorithm()
{
    int mainChoice = -1;
    while (mainChoice != 4)
    {
        printMainChoice();
        cout << "Choice : ";
        cin >> mainChoice;
        switch (mainChoice)
        {
        case 1:
        {
            firstFitUtil();
            break;
        }
        case 2:
        {
            bestFitUtil();
            break;
        }
        case 3:
        {
            worstFitUtil();
            break;
        }
        case 4:
        {
            cout << "Thank you for using our Application!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Input\n";
            break;
        }
        }
    }
}
