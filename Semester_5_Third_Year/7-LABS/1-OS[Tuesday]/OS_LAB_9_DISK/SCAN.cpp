#include <bits/stdc++.h>
using namespace std;

// For Proper Presentation
void dash(char ch, int freq);

// To Print the Answer [Disk Request] & Total Seek Time
void print(vector<int> &answer, int totalSeekTime);

// SCAN Algorithm for Disk Scheduling Algorithm Implementation
void SCAN(vector<int> requests, int n, int head);

int main()
{
    int n;
    cout << "Enter the number of Disk Access request : ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the index of Tracks : ";
    for (int i = 0; i < n; i++)
        cin >> requests[i];

    int head;
    cout << "Enter Disk head position : ";
    cin >> head;

    SCAN(requests, n, head);

    return 0;
}

// For Proper Presentation
void dash(char ch, int freq)
{
    for (int i = 0; i < freq; i++)
        cout << ch;
}

// To Print the Answer [Disk Request] & Total Seek Time
void print(vector<int> &answer, int totalSeekTime)
{
    cout << endl;
    dash('-', 100);
    cout << endl;

    cout << "Disk request will be served as : ";

    for (auto &x : answer)
        cout << x << " ";

    cout << "\nTotal Seek Time : " << totalSeekTime;

    cout << endl;
    dash('-', 100);
    cout << endl;
}

// SCAN Algorithm for Disk Scheduling Algorithm Implementation
void SCAN(vector<int> requests, int n, int head)
{
    int totalSeekTime = 0;

    sort(requests.begin(), requests.end());

    vector<int> answer;
    int ind = -1;
    if (head <= requests[0])
    {
        ind = 0;
    }

    for (int i = 0; i < n - 1 and ind == -1; i++)
    {
        if (requests[i] <= head and head < requests[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        ind = n - 1;
    }

    for (int i = ind; i >= 0; i--)
    {
        answer.push_back(requests[i]);
        totalSeekTime += abs(head - requests[i]);
        head = requests[i];
    }

    totalSeekTime += head;
    head = 0;
    answer.push_back(head);
    for (int i = ind + 1; i < n; i++)
    {
        answer.push_back(requests[i]);
        totalSeekTime += abs(head - requests[i]);
        head = requests[i];
    }

    print(answer, totalSeekTime);
}