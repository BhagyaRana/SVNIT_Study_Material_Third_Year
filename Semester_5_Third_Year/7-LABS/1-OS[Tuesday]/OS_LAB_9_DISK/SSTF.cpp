#include <bits/stdc++.h>
using namespace std;

// For Proper Presentation
void dash(char ch, int freq);

// To Print the Answer [Disk Request] & Total Seek Time
void print(vector<int> &answer, int totalSeekTime);

// Shortest Seek Time First (SSTF) Disk Scheduling Algorithm Implementation
void SSTF(vector<int> requests, int n, int head);

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
    SSTF(requests, n, head);
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

// Shortest Seek Time First (SSTF) Disk Scheduling Algorithm Implementation
void SSTF(vector<int> requests, int n, int head)
{
    int totalSeekTime = 0;

    auto ite = requests.begin();
    vector<int> answer;
    answer.push_back(head);

    while (n)
    {
        int min_seek_time = INT_MAX;

        auto itr = requests.begin();
        auto ind = requests.begin();

        while (itr != requests.end())
        {
            int dis = abs(head - (*itr));
            if (dis < min_seek_time)
            {
                min_seek_time = dis;
                ind = itr;
            }
            itr++;
        }

        head = (*ind);
        answer.push_back(head);
        requests.erase(ind);

        totalSeekTime += min_seek_time;

        n--;
    }

    print(answer, totalSeekTime);
}