#include <iostream>
using namespace std;

#define username_lower_limit 8
#define username_upper_limit 30

string reason;

bool valid_username(string username)
{
    int special = 0;
    int n = username.length();

    // Length of Username Constraint
    if (n < username_lower_limit || n > username_upper_limit || n <= 0)
    {
        if (n < username_lower_limit)
        {
            string t("Username length < " + to_string(username_lower_limit) + "characters\n");
            reason = t;
        }

        if (n > username_upper_limit)
        {
            string t("Username length > " + to_string(username_upper_limit) + "characters\n");
            reason = t;
        }

        return false;
    }

    // Starting Character Constraint
    char start_ch = username[0];
    // If first character is not {[A-Z]/[a-z]}, then username is invalid
    if (!((start_ch >= 'a' && start_ch <= 'z') || (start_ch >= 'A' && start_ch <= 'Z')))
    {
        string t("First character is not {[A-Z]/[a-z]}\n");
        reason = t;
        return false;
    }

    // All remaining Characters is not {_/[A-Z]/[a-z]/[0-9]}, then username is invalid
    for (int i = 1; i < n; i++)
    {
        char ch = username[i];
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_'))
        {
            string t("Characters is Not from {_/[A-Z]/[a-z]/[0-9]}, i.e. Special Character Used!\n");
            reason = t;
            return false;
        }
    }

    // If all the 3 Constraints are Satisfied, then Username is Valid
    return true;
}

int main()
{
    // Number of Usernames to be Checked
    int n;
    cout << "Enter the Number of Usernames to Check for Validity : ";
    cin >> n;

    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (valid_username(s[i]))
        {
            cout << s[i] << " -> Valid Username\n\n";
        }
        else
        {
            cout << s[i] << " -> Invalid Username\n";
            cout << "Reason : " << reason << endl;
        }
    }

    return 0;
}
