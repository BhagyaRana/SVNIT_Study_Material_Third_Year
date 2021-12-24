// [U19CS012] BHAGYA VINOD RANA

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// Function to Convert the Number to Binary Form
vi get_binary(int n);

// 1's Complement Addition [Given there Binary Forms]
vi add_binary(vi num1, vi num2);

int main()
{
    cout << "\n~~~~~~~~~~~~~~~~~~~~~ Sender Side ~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "Enter Message to be Encoded (string) : ";

    string s;
    cin >> s;

    int n = s.length();
    vi v[n];

    // Step 1 : Convert all the Charecter [ASCII] to Binary & Store it
    for (int i = 0; i < n; i++)
        v[i] = get_binary((int)s[i]);

    // [Display to User]
    cout << "\nINPUT STRING\n \n[Character | ASCII | Binary Representation ]\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << s[i] << " -> " << (int)s[i] << " -> \t";
        for (int j = 0; j < 16; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }

    vi sum(16, 0);
    vi check_sum(16, 0);

    // Step 2 : Add all the Data Bits
    for (int i = 0; i < n; i++)
        sum = add_binary(sum, v[i]);

    // [ Display Sum to User]
    cout << "\nSUM : \t \t";
    for (int i = 0; i < 16; i++)
    {
        cout << sum[i] << " ";
        // Since CheckSum is One's Complement of Sum
        if (sum[i] == 0)
            check_sum[i] = 1;
    }
    cout << endl;

    // Step 3 : Display CheckSum to User
    cout << "CHECKSUM : \t";
    for (int i = 0; i < 16; i++)
        cout << check_sum[i] << " ";

    return 0;
}

// Function to Convert the Number to Binary Form
vi get_binary(int n)
{
    vi bin(16, 0);
    int pos = 15;
    while (n)
    {
        bin[pos--] = n % 2;
        n /= 2;
    }
    return bin;
}

// 1's Complement Addition [Given there Binary Forms]
vi add_binary(vi num1, vi num2)
{
    int carry = 0, S;
    vi complement(16, 0);

    for (int i = 15; i >= 0; i--)
    {
        S = carry + num1[i] + num2[i];
        // CASE 1 : {0, 0, 0}
        if (S == 0)
            complement[i] = 0, carry = 0;
        // CASE 2 : {1, 0, 0}, {0, 1, 0}, {0, 0, 1}
        else if (S == 1)
            complement[i] = 1, carry = 0;
        // CASE 3 : {1, 1, 0}, {1, 0, 1}, {0, 1, 1}
        else if (S == 2)
            complement[i] = 0, carry = 1;
        // CASE 4 : {1, 1, 1}
        else
            complement[i] = 1, carry = 1;
    }

    //  If Carry is Set {Need to Add 1 to Complement}
    if (carry)
    {
        vi one(16, 0);
        one[15] = 1;
        complement = add_binary(complement, one);
    }

    return complement;
}