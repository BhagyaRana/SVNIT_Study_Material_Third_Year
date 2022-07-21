#include <iostream>
// For setw()
#include <iomanip>
// For String
#include <string>
// For File Reading
#include <fstream>

// U19CS012 [BHAGYA VINOD RANA]

using namespace std;

int main()
{
    string file_name;
    cout << "Enter the Name of the File to be Formatted [Name No] : ";
    cin >> file_name;

    // ifstream: Stream class to read from files
    ifstream ifstream_obj;

    ifstream_obj.open(file_name);

    string name;
    long long int telephone_no;

    if (ifstream_obj)
    {
        while (ifstream_obj >> name >> telephone_no)
        {
            // Adjust output to the left
            cout << left << setw(15) << name;
            // Adjust output to the right
            cout << right << setw(15) << telephone_no;
            cout << endl;
        }

        ifstream_obj.close();
    }
    else
    {
        cout << file_name << " named File Does Not Exist!\n";
    }

    return 0;
}
