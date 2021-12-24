// [U19CS012] BHAGYA VINOD RANA

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi pow2(16, 0);

// Function to Precompute the Power's of 2
void pre();

// Function to Convert Binary to Decimal
int to_decimal(vi bin);

// 1's Complement Addition [Given there Binary Forms]
vi add_binary(vi num1, vi num2);

int main()
{
    // Power's of 2
    pre();

    cout << "\n~~~~~~~~~~~~~~~~~~~~~ Receiver Side ~~~~~~~~~~~~~~~~~~~~~\n\n";

    cout << "Enter the Number of Data Segments : ";
    int k, bit;
    cin >> k;

    // ds + checksum
    vi v[k + 1];

    for (int i = 0; i < k; i++)
    {
        cout << "Data Segment " << i + 1 << " : ";
        for (int j = 0; j < 16; j++)
        {
            cin >> bit;
            v[i].push_back(bit);
        }
    }

    cout << "Enter CHECKSUM : ";
    for (int j = 0; j < 16; j++)
    {
        cin >> bit;
        v[k].push_back(bit);
    }

    vi sum(16, 0);
    vi complement(16, 0);

    // Step 2 : Add all the Data Bits [Data Bits + Check Sum]
    for (int i = 0; i <= k; i++)
        sum = add_binary(sum, v[i]);

    bool error = false;

    // [Display the Final Sum]
    // Step 3 : If the Result is all 1's, ACCEPT; ELSE REJECT
    cout << "\nSUM : \t \t";
    for (int i = 0; i < 16; i++)
    {
        cout << sum[i] << " ";
        if (sum[i] == 0)
            complement[i] = 1, error = true;
        else
            complement[i] = 0;
    }

    cout << "\n\nCOMPLEMENT : \t";
    for (int i = 0; i < 16; i++)
    {
        cout << complement[i] << " ";
    }

    string msg;
    if (error)
    {
        cout << "\n\nError Detected!";
    }
    else
    {
        for (int i = 0; i < k; i++)
            msg += (char)(to_decimal(v[i]));

        cout << "\n\nError Not Detected!\n";
        cout << "Original Message Transmitted : " << msg << endl;
    }

    return 0;
}

// Function to Precompute the Power's of 2
void pre()
{
    pow2[0] = 1;
    for (int i = 1; i < 16; i++)
        pow2[i] = pow2[i - 1] * 2;
}

// Function to Convert Binary to Decimal
int to_decimal(vi bin)
{
    int num = 0;
    for (int i = 15; i >= 0; i--)
        num += bin[i] * pow2[15 - i];
    return num;
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