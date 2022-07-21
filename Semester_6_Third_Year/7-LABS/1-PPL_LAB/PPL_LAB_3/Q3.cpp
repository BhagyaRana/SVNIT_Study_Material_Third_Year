#include <iostream>
// for sin(), cos(), tan(), sqrt()
#include <cmath>

// [U19CS012] BHAGYA VINOD RANA

using namespace std;

const double pi = 3.14159265358979323846;

// Polar Class with '+' Operator Overloaded
class polar
{
private:
    double radius;
    // theeta in degrees
    double angle;

public:
    // Default Constructor
    polar() : radius(0.0), angle(0.0) {}

    // Parameterized Constructor
    polar(double r, double t)
    {
        radius = r;
        angle = t;
    }

    // For Displaying the Output in Polar Form (r,0)
    void display_polar_form()
    {
        cout << "Radius (R) = " << radius << " , Theeta (0) = " << angle << " Degree(s)\n";
    }

    // Overload the '+' Operator
    polar operator+(polar a)
    {
        // Final r' and theta 0°
        double r, t;
        double x1, x2, y1, y2, x3, y3;

        // Trigonometry F(x) -> single mandatory argument in radians.

        // x = r*cos(a);
        x1 = radius * cos(pi * angle / 180);
        x2 = a.radius * cos(pi * a.angle / 180);

        // y = r*sin(a);
        y1 = radius * sin(pi * angle / 180);
        y2 = a.radius * sin(pi * a.angle / 180);

        // Add them
        x3 = x1 + x2;
        y3 = y1 + y2;

        // Radius of Final r' = sqrt((x')*(x') + (y')*(y'));
        r = sqrt((x3 * x3) + (y3 * y3));

        // 0 = tan inverse of (y'/x')
        t = atan(y3 / x3);
        // convert Back to degrees
        t = t * 180 / pi;

        return polar(r, t);
    }
};

int main()
{
    // Number of Points
    int n;

    cout << "Enter the Number of Polar Points : ";
    cin >> n;

    double rad[n], angle[n];
    polar P[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Polar Co-Ordinates of Point " << i + 1 << " [ Radius, Angle(in degree) ] : \n";
        cin >> rad[i] >> angle[i];
        P[i] = polar(rad[i], angle[i]);
    }

    polar resultant(0, 0);

    for (int i = 0; i < n; i++)
    {
        P[i].display_polar_form();
        resultant = resultant + P[i];
    }

    cout << "Resultant [Summation] Point in Polar Form : ";
    resultant.display_polar_form();

    return 0;
}
