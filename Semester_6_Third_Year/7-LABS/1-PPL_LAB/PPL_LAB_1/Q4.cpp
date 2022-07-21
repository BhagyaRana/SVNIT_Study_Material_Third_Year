#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

// Staff Class
class staff
{
protected:
    // Staff Code & Name
    int code;
    string name;

public:
    void set_info(string n, int c)
    {
        name = n;
        code = c;
    }
};

// Education added for Staff
class education : public staff
{
protected:
    string quali;

public:
    void set_qualification(string q) { quali = q; }
};

// Teacher Class
class teacher : public education
{
protected:
    // Subject and Publication
    string sub, publication;

public:
    // To Intialize the Teacher's Details
    void set_details(string s, string p)
    {
        sub = s;
        publication = p;
    }

    // To Display the Teachers Information
    void show()
    {
        cout << " Name " << setw(8) << " Code " << setw(15)
             << " Subject " << setw(22) << " Publication "
             << setw(25) << " Qualification " << endl
             << name << setw(8) << code << setw(25)
             << sub << setw(18) << publication << setw(25) << quali << endl;
    }
};

// Officer's Class
class officer : public education
{
    // Officer Grade
    string grade;

public:
    void set_details(string g)
    {
        grade = g;
    }

    // To Display the Officers Information
    void show()
    {
        cout << " Name " << setw(15) << " Code " << setw(15) << " Category "
             << setw(22) << " Qualification " << endl
             << name << setw(10)
             << code << setw(15) << grade << setw(25) << quali << endl
             << endl;
    }
};

// Typist Class
class typist : public staff
{
protected:
    float speed;

public:
    void set_speed(float s)
    {
        speed = s;
    }
};

// Regular Typist which inherits Publicly from Typist Class
class regular : public typist
{
protected:
    float wage;

public:
    void set_wage(float w) { wage = w; }
    void show()
    {
        cout << " Name " << setw(10) << " Code " << setw(10) << " Speed "
             << setw(10) << " Wage " << endl
             << name << setw(10) << code
             << setw(15) << speed << setw(15) << wage << endl
             << endl;
    }
};

// Casual Typist which inherits Publicly from Typist Class
class causal : public typist
{
    float wage;

public:
    void set_wage(float w) { wage = w; }
    void show()
    {
        cout << " Name " << setw(16) << " Code " << setw(15) << " Speed "
             << setw(15) << " Wage " << endl
             << name << setw(10) << code
             << setw(15) << speed << setw(15) << wage << endl
             << endl;
    }
};

int main()
{
    // Teacher
    teacher t;
    t.set_info("Akbar", 710);
    t.set_details("Programming with c++", "Tata McGraw Hill");
    t.set_qualification("PHD from Standford");

    // Officer
    officer o;
    o.set_info("Ramesh", 155);
    o.set_details("First class");
    o.set_qualification("2 years experienced");

    // Regular Typist
    regular rt;
    rt.set_info("Rohan", 310);
    rt.set_speed(85);
    rt.set_wage(25000);

    // Casual Typist
    causal ct;
    ct.set_info("Jethalal", 205);
    ct.set_speed(60);
    ct.set_wage(20000);

    cout << "\nTeacher Info : " << endl;
    t.show();

    cout << "\nOfficer Info : " << endl;
    o.show();

    cout << "\nRegular Typist Info : " << endl;
    rt.show();

    cout << "\nCasual Typist Info : " << endl;
    ct.show();

    return 0;
}