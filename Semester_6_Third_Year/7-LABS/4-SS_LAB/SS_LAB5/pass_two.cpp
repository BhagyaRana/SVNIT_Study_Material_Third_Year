// PASS 2 Of Two-Pass Assembler

#include <bits/stdc++.h>
using namespace std;

// [U19CS012] BHAGYA VINOD RANA

// Function to fetch symbol/literal address from symbol_table or literal_table
string table(ifstream &fin, string n)
{
    string no, name, addr;
    while (fin >> no >> name >> addr)
    {
        if (no == n)
        {
            fin.seekg(0, ios::beg);
            return addr;
        }
    }
    fin.seekg(0, ios::beg);
    return "NAN";
}

int main()
{

    ifstream ic, st, lt;
    // pass1 output files as input to pass2
    ic.open("ic.txt");
    st.open("symtable.txt");
    lt.open("littable.txt");
    // generate file output of machine code
    ofstream mc;
    mc.open("machine_code.txt");

    string lc, ic1, ic2, ic3;
    cout << "\n -- ASSEMBLER PASS-2 OUTPUT --" << endl;
    cout << "\n LC\t <INTERMEDIATE CODE>\t\t\tLC\t <MACHINE CODE>" << endl;

    // reading input file line by line
    while (ic >> lc >> ic1 >> ic2 >> ic3)
    {
        // machine code
        string MC;

        // no machine code for AD and DL,02 i.e. DS opcodes
        if (ic1.substr(1, 2) == "AD" || (ic1.substr(1, 2) == "DL" && ic1.substr(4, 2) == "02"))
        {

            MC = " -No Machine Code-";
        }
        // if opcode is DL i.e. DL,01 then display constant value at the place of memory operand
        else if (ic1.substr(1, 2) == "DL" && ic1.substr(4, 2) == "01")
        {
            MC = "00\t0\t00" + ic2.substr(3, 1);
        }
        else
        {
            // IS opcode
            if (ic1 == "(IS,00)")
            { // specifically for STOP
                MC = ic1.substr(4, 2) + "\t0\t000";
            }
            else if (ic2.substr(1, 1) == "S")
            { // if opcode in pass1 was ORIGIN
                MC = ic1.substr(4, 2) + "\t0\t" + table(st, ic2.substr(4, 1));
            }
            else
            {
                if (ic3.substr(1, 1) == "S")
                    // for symbols
                    MC = ic1.substr(4, 2) + "\t" + ic2.substr(1, 1) + "\t" + table(st, ic3.substr(4, 1));
                else
                    // for literals
                    MC = ic1.substr(4, 2) + "\t" + ic2.substr(1, 1) + "\t" + table(lt, ic3.substr(4, 1));
            }
        }

        if (ic1 == "(AD,03)")
        {
            // just for console output display format
            cout << " " << lc << "\t" << ic1 << "\t" << ic2 << " " << ic3 << "\t\t\t" << lc << "\t" << MC << endl;
            mc << lc << "\t" << MC << endl;
            continue;
        }
        // console output
        cout << " " << lc << "\t" << ic1 << "\t" << ic2 << "\t " << ic3 << "\t\t\t" << lc
             << "\t" << MC << endl;
        mc << lc << "\t" << MC << endl;
    }

    return 0;
}
