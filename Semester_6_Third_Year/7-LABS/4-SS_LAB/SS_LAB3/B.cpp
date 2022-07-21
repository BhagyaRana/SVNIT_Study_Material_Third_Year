#include <bits/stdc++.h>
using namespace std;
// U19CS012 [BHAGYA VINOD RANA]

// This Checks if the Given String is Valid Comment or Not
void is_valid_comment(string line);

int main()
{
    string line;
    cout << "Enter a String to Check if it is Comment or Not : ";
    cin >> line;

    is_valid_comment(line);

    return 0;
}

// This Checks if the Given String is Valid Comment or Not
void is_valid_comment(string line)
{
    if (line.length() < 2)
    {
        cout << "It is Not a Comment!\n";
        return;
    }
    else if (line.length() == 2)
    {
        if (line[0] == '/' && line[1] == '/')
        {
            cout << "It is a Single-line Comment!\n";
            return;
        }
        else
        {
            cout << "It is Not a Comment!\n";
            return;
        }
    }
    else
    {
        // Single Line Comment Format
        if (line[0] == '/' && line[1] == '/' && line[2] != '/')
        {
            cout << "It is a Single-line Comment!\n";
            return;
        }

        // /* abcd */ Multi-Line Comment Format
        if ((line[0] == '/' && line[1] == '*') && (line[line.size() - 2] == '*' && line[line.size() - 1] == '/'))
        {
            cout << "It is a Multi-line Comment!\n";
            return;
        }

        cout << "It is Not a Comment!\n";
    }
}