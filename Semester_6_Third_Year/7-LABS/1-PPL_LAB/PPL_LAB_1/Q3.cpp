#include <iostream>
#include <string.h>
#include <string>
// [U19CS012 BHAGYA VINOD RANA]

// Miinimum Balance
#define minimum 500
// Service Charge in case if amount is less than minimum balance
#define service_charge 100
// Rate of Interest
#define r 0.10

using namespace std;

// Account Class
class account
{
protected:
    // Customer Name
    string name;
    // Account Number
    int ac_number;
    // Account Type
    string ac_type;

public:
    // Member Function to Create Account of type 't'
    void create_acc();
};

// Current Account Derived from Account Class
class cur_acct : public account
{
private:
    double balance;

public:
    void deposit(double d);
    void withdraw(double w);
    void display();
};

// Saving Account Derived from Account Class
class sav_acct : public account
{
    double balance;
    int d, m, y;

public:
    void deposit(double d);
    void withdraw(double w);
    void display();
    void set_date(int a, int b, int c)
    {
        d = a;
        m = b;
        y = c;
    }
    void interest();
};

// --------------------------------------------------------------------------------------------

// Main Function
int main()
{
    sav_acct raju;
    raju.create_acc();

    // Accept Deposits
    double d;
    cout << " Enter your Deposit Amount : ";
    cin >> d;

    raju.deposit(d);

    raju.display();

    int t;
    cout << "\n press 1 to see your Interest : \n"
         << " press 0 to skip : ";

    cin >> t;

    if (t == 1)
        raju.interest();

    // Permit Withdrawal and update balance
    cout << "\n Enter your Withdrawal Amount :";

    double w;
    cin >> w;
    raju.withdraw(w);

    raju.display();

    return 0;
}

// -------------------------------MEMBER F(X) OF ACCOUNT CLASS-----------------------------------

// Member Function to Create Account of type 't'
void account::create_acc()
{
    cout << " Enter Customer Name : ";
    cin >> name;

    cout << "Account Type" << endl;
    cout << " 1 -> Saving\n 2 -> Current\n ";
    cout << "Enter Account Type {1/2} : ";
    int ch;
    cin >> ch;

    if (ch == 1)
        ac_type = "savings";
    else
        ac_type = "current";

    string s;
    do
    {
        cout << " Enter Account Number [8-digits] : ";
        cin >> ac_number;
        s = to_string(ac_number);
        if (s.length() != 8)
            cout << "Please Enter Valid Account Number!\n";
    } while (s.length() != 8);

    cout << "\nAccount Successfully Made!\n\n";
}

// -----------------------------MEMBER F(X) OF CURR ACCOUNT CLASS--------------------------------

void cur_acct::deposit(double d)
{
    balance += d;
}

void cur_acct::withdraw(double w)
{
    if (balance < w)
        cout << " Sorry! Insufficient Balance!\n";
    else
    {
        balance -= w;

        if (balance < minimum)
        {
            cout << "\n Your current balance is :" << balance << " which is less than" << minimum << "\n your account is discharged by " << service_charge << "Rs \n"
                 << " You must store " << minimum << "Rs to avoid discharge\n "
                 << " Do you want to Withdraw ? Press 1 -> YES OR Press 0 -> NO \n"
                 << " What is your Choice ?";

            int opt;
            cin >> opt;
            if (opt == 0)
                balance += w;
        }
    }
}

void cur_acct::display()
{
    cout << "\n Account Balance = " << balance << "\n";
}

// -----------------------------MEMBER F(X) OF SAVING ACCOUNT CLASS------------------------------

void sav_acct::deposit(double d)
{
    int x, y, z;
    cout << " Enter Date of Deposit (i,e day,month,year) : ";
    cin >> x >> y >> z;
    set_date(x, y, z);
    balance = d;
}

void sav_acct::withdraw(double w)
{
    if (balance < w)
        cout << " Sorry! Insufficient Balance!\n";
    else
    {
        balance -= w;

        if (balance < minimum)
        {
            cout << "\n Your current balance is :" << balance << " which is less than" << minimum << "\n your account is discharged by " << service_charge << "Rs \n"
                 << " You must store " << minimum << "Rs to avoid discharge\n "
                 << " Do you want to Withdraw ? Press 1 -> YES OR Press 0 -> NO \n"
                 << " What is your Choice ?";

            int opt;
            cin >> opt;
            if (opt == 0)
                balance += w;
        }
    }
}

void sav_acct::display()
{
    cout << "\n Account Balance : " << balance << endl;
}

void sav_acct::interest()
{
    // No of Days in Different Month of Years
    int D[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int d1, y1, m1;
    cout << " Enter Today's Date (i,e day,month,year) : ";
    cin >> d1 >> m1 >> y1;

    int iday, fday;
    iday = d;
    fday = d1;

    for (int i = 0; i < m1; i++)
    {
        fday += D[i];
    }

    for (int i = 0; i < m; i++)
    {
        iday += D[i];
    }

    int tday;
    // Final - Initial Days = Total Interest Days
    tday = fday - iday;

    double ty;
    ty = double(tday) / 365 + (y1 - y);

    double intrst;
    // SI = (P*R*T)
    intrst = balance * r * ty;

    cout << " Interest is : " << intrst << "\n";

    // Add interest to Balance Amount
    balance += intrst;
}