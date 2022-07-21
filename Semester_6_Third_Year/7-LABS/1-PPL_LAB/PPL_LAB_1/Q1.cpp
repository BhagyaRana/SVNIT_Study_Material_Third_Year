#include <iostream>
using namespace std;
// [U19CS012 - BHAGYA VINOD RANA]

// DB Class {Stores the Distance in Feet and Inches}
class DB;
// DM Class {Stores the Distance in Metres and Centimeters}
class DM;

// DM Class {Stores the Distance in Metres and Centimeters}
class DM
{
    double meter, centi;

public:
    void getdata()
    {
        cout << "\nEnter the Distance in (Meter-Centimeter) : ";
        cin >> meter >> centi;
    }
    void display()
    {
        cout << "\nThe Distance is : ";
        cout << meter << " Meters and " << centi << " Centimeter.";
    }
    friend void add(DM &, DB &);
};

// DB Class {Stores the Distance in Feet and Inches}
class DB
{
    double inch, feet;

public:
    void getdata()
    {
        cout << "\nEnter the Distance in (Feet-Inch) : ";
        cin >> feet >> inch;
    }
    void display()
    {
        cout << "\nThe Distance is : ";
        cout << feet << " Feet and " << inch << " Inch.";
    }
    friend void add(DM &, DB &);
};

// Friend Functoin to Carry Out Addition Operation
void add(DM &a, DB &b);

int main()
{
    DM a;
    DB b;
    // Read Values from Class Objects
    a.getdata();
    b.getdata();
    // Call the Friend Function to Add Both the Objects in Different Units
    add(a, b);
}

// Friend Functoin to Carry Out Addition Operation
void add(DM &a, DB &b)
{
    int ch;
    cout << "\nEnter 1 -> Meter-Centi Output : ";
    cout << "\nEnter 2 -> Feet-Inch Output : ";
    cout << "\nEnter your choice : ";
    cin >> ch;

    if (ch == 1)
    {
        DM d;

        // Convert all to Common 'cm' Denominator
        // 1 Meter = 100 cm, 1 cm = 1 cm, 1 Feet = 30.48 cm, & Round Off to Nearest cm
        int c = ((a.meter * 100) + (a.centi) + (b.feet * 30.48) + (b.inch * 2.54));

        if (c >= 100)
        {
            d.meter = c / 100;
            d.centi = c % 100;
        }
        else
        {
            d.meter = 0;
            d.centi = c;
        }
        d.display();
    }
    else
    {
        DB d;
        // Convert all to Common 'inches' Denominator
        // 1 Meter = 39.3701 inch, 1 cm = 0.3937 inch, 1 Feet = 12 inch, & Round Off to Nearest inch
        int i = ((a.meter * 39.3701) + (a.centi * 0.393701) + (b.feet * 12) + (b.inch));
        if (i >= 12)
        {
            d.feet = i / 12;
            d.inch = i % 12;
        }
        else
        {
            d.feet = 0;
            d.inch = i;
        }
        d.display();
    }
}
