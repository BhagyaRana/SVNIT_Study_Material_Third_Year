#include <iostream>
#include <vector>
// exception is for the user to inherit and define their own exceptions.
#include <exception>
// stdexcept is for catching and handling the standard exceptions
#include <stdexcept>

// [U19CS012] BHAGYA VINOD RANA

using namespace std;
typedef long long int ll;

ll complex_function(ll a, ll b)
{
    if (b < 0)
        throw invalid_argument("B is Negative\n");

    // Allocated a Vector of Size 'b' -> for bad_alloc Exception
    vector<ll> vec(b, 1);

    // For other Exception Code
    if (!(a ^ b))
    {
        throw int(a ^ b);
    }

    // Any Random Computation
    cout << "Output of Complex computation : ";
    return (vec[b - 1]) ^ a | b;
}

int main()
{
    ll a, b;
    cout << "Enter Two Numbers for Complex Computation : ";
    cin >> a >> b;

    // Try Catch Block for Exception Handling
    try
    {
        cout << complex_function(a, b) << "\n";
    }
    catch (bad_alloc &ba)
    {
        // Exception thrown on failure allocating memory
        cerr << "bad_alloc Exception caught : " << ba.what() << endl;
        cerr << "Not Enough Memory\n";
    }
    catch (exception &e)
    {
        cerr << "Exception : " << e.what() << endl;
    }
    catch (int e)
    {
        cerr << "Other Exceptions Code : " << e << endl;
    }

    return 0;
}