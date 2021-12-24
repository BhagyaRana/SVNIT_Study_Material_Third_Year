// [U19CS012] BHAGYA VINOD RANA

#include <iostream>
using namespace std;

// This Function return the Remainder after Binary Division
string binary_division(string encoded, string crc);

// This Function Check if the Message/CRC is Valid
bool is_valid(string s);

int main()
{
    string data, key, encoded;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~ Sender Side ~~~~~~~~~~~~~~~~~~~~~\n\n";

    // Data Bits that needs to be transmitted
    cout << "Enter Data Bits [0/1]: \n";

    do
    {
        cin >> data;
    } while (!is_valid(data));

    // 1.) Key used N bit generator polynomial which works as Divisor ( Agreed by Both Sender & Reciever)
    cout << "Enter Key [Generator] [In Binary Form, Eg. x^2 + 1 -> 101 ]: \n";

    do
    {
        cin >> key;
    } while (!is_valid(key));

    int key_len = key.length();

    // Encoded bits are initialized to Data bits
    encoded += data;

    // 2.) Appending "(length of Generator Polynomial) - 1" number of zeros to encoded bits to the Data word.
    for (int i = 1; i <= (key_len - 1); i++)
        encoded += '0';

    // 3. Divide the appended data word by the generator by using Binary Division.
    string CRC = binary_division(encoded, key);

    // 4. The remainder obtained after division is N-1 bit CRC code.
    cout << "\nCRC Bits Generated is: " << CRC << endl;

    // Data bits + CRC bit is What going to be sent to reciever
    cout << "Message to be Transmitted over Network: " << data + CRC << endl;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~ Receiver Side ~~~~~~~~~~~~~~~~~~~~~\n\n";

    cout << "Enter the Message Recieved: " << endl;

    string msg;
    cin >> msg;

    // Remainder After Binary Division
    string rem = binary_division(msg, key);

    for (char i : rem)
    {
        if (i != '0')
        {
            cout << "\nError Detected!\n";
            return 0;
        }
    }

    cout << "\nError Not Detected!\n";
    return 0;
}

// This Function Check if the Message/CRC is Valid
bool is_valid(string s)
{
    for (auto ch : s)
    {
        if (ch != '0' && ch != '1')
        {
            cout << "Enter a Binary String!\n";
            return false;
        }
    }
    return true;
}

// This Function return the Remainder after Binary Division
string binary_division(string encoded, string key)
{
    int key_len = key.length();

    for (int i = 0; i <= (encoded.length() - key_len);)
    {
        for (int j = 0; j < key_len; j++)
        {
            // if Encoded bit and CRC bit are same, then replace it with zero
            // "0 xor 0 = 0"     "1 xor 1 = 0"
            // "0 xor 1 = 1 "    "1 xor 0 = 1"
            encoded[i + j] = encoded[i + j] == key[j] ? '0' : '1';
        }

        // If Prefix are '0' we increment the Window
        for (; i < encoded.length() && encoded[i] != '1'; i++)
            ;
    }

    // Remainder Last Bits
    string rem = encoded.substr(encoded.length() - key_len + 1);
    return rem;
}