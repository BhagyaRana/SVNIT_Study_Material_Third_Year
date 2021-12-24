#include <bits/stdc++.h>
using namespace std;

// F(x) to Print Vector
void print(vector<int> v);

// F(x) to Predict the Optimal Page that Would be Required in Future
int predictFuture(int pages[], vector<int> frames, int n, int index);

// F(x) to Calculate the No Of Page Faults using Optimal Algorithm
int OptimalPageReplacement(int pages[], int n, int noFrames);

int main()
{
    cout << "Optimal Page Replacement Algorithm\n\n";

    int n;
    cout << "Enter Number of Pages : ";
    cin >> n;

    int pages[n];
    cout << "Enter Space seperated Page Reference Number : \n";

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames : ";
    int noFrames;
    cin >> noFrames;

    int ans = OptimalPageReplacement(pages, n, noFrames);

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

// F(x) to Predict the Optimal Page that Would be Required in Future
int predictFuture(int pages[], vector<int> frames, int n, int index)
{
    int res = -1;
    int far = index;

    for (int i = 0; i < frames.size(); i++)
    {
        int j;
        for (j = index; j < n; j++)
        {
            if (frames[i] == pages[j])
            {
                if (j > far)
                {
                    far = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n)
        {
            return i;
        }
    }
    if (res == -1)
    {
        return 0;
    }
    return res;
}

// F(x) to Calculate the No Of Page Faults using Optimal Algorithm
int OptimalPageReplacement(int pages[], int n, int noFrames)
{
    vector<int> frames;
    int pageFaults = 0;

    for (int i = 0; i < n; i++)
    {
        // If the Page is Found
        if (find(frames.begin(), frames.end(), pages[i]) != frames.end())
        {
            print(frames);
            cout << "No Page Fault" << endl;
        }
        // If set holds less pages than capacity.
        else if (frames.size() < noFrames)
        {
            frames.push_back(pages[i]);
            pageFaults++;
            print(frames);

            cout << "Page Fault : " << pageFaults << endl;
        }
        // Find the Optimal Page to be Replaced
        else
        {
            int index = predictFuture(pages, frames, n, i + 1);
            frames[index] = pages[i];
            pageFaults++;
            print(frames);
            cout << "Page Fault : " << pageFaults << endl;
        }
    }

    return pageFaults;
}
