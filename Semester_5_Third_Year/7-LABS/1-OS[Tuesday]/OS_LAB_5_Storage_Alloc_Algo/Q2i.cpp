#include <bits/stdc++.h>
using namespace std;

// F(x) to Print Vector
void print(vector<int> v);

// F(x) to Calculate the No Of Page Faults using LRU Algorithm
int LRU(int pages[], int n, int noFrames);

int main()
{
    cout << "L.R.U. {Least Recently Used} Algorithm\n\n";

    int n;
    cout << "Enter Number of Pages : ";
    cin >> n;

    int pages[n];
    cout << "Enter Space seperated Page Reference Number : \n";

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of Frames : ";
    int noFrames;
    cin >> noFrames;
    cout << endl;

    int ans = LRU(pages, n, noFrames);

    cout << "	" << endl;
    cout << "Total Page Faults : " << ans << endl;

    return 0;
}

// F(x) to Print Vector
void print(vector<int> v)
{
    cout << "~~~~~~~~~~~~~~~" << endl;
    cout << "CURRENT PAGE ALLOCATION" << endl;
    for (auto x : v)
        cout << x << endl;
};

// F(x) to Calculate the No Of Page Faults using LRU Algorithm
int LRU(int pages[], int n, int noFrames)
{
    vector<int> s;
    unordered_map<int, int> index;

    int pageFaults = 0;

    for (int i = 0; i < n; i++)
    {
        // If set holds less pages than capacity.
        if (s.size() < noFrames)
        {
            // If the Page is Not Found in Set
            if (find(s.begin(), s.end(), pages[i]) == s.end())
            {
                s.push_back(pages[i]);
                pageFaults++;
                print(s);
                cout << "Page Fault : " << pageFaults << endl;
            }
            // If [age is Found, No Page Fault Occurs
            else
            {
                print(s);
                cout << "No Page Fault" << endl;
            }
        }
        else
        {
            // Find the page in the set that was least recently used.

            // We find it using index array. We basically need to replace the page with minimum index.
            if (find(s.begin(), s.end(), pages[i]) == s.end())
            {
                int lru = INT_MAX, val;
                for (int j = 0; j < s.size(); j++)
                {
                    if (index[s[j]] < lru)
                    {
                        lru = index[s[j]];
                        val = j;
                    }
                }
                s[val] = pages[i];
                pageFaults++;
                print(s);
                cout << "Page Fault : " << pageFaults << endl;
            }
            else
            {
                print(s);
                cout << "No Page Fault" << endl;
            }
        }

        index[pages[i]] = i;
    }
    return pageFaults;
}