#include <iostream>
#include <string>
using namespace std;
// U19CS012 [BHAGYA VINOD RANA]

// This Checks if the Given String is Valid Identifier or Not
bool is_valid_identfier(string s);

int main()
{
    string s;
    cout << "Enter String to Check for Type of Identifier : ";
    cin >> s;

    if (is_valid_identfier(s))
        cout << s << " is Valid Identifier!\n";
    else
        cout << s << " is Not a Valid Identifier!\n";

    return 0;
}

// This Checks if the Given String is Valid Identifier or Not
bool is_valid_identfier(string s)
{
    int n = s.length();

    // If first character is not {_/[A-Z]/[a-z]}, then identifier is invalid
    if (!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_'))
        return false;

    // All remaining Characters is not {_/[A-Z]/[a-z]/[0-9]}, then identifier is invalid
    for (int i = 1; i < s.length(); i++)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
            return false;
    }

    // String is a valid identifier
    return true;
}