#include <bits/stdc++.h>
using namespace std;
// [U19CS012] BHAGYA VINOD RANA

struct fast
{
    fast()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
};

fast f;

/*Write the class AddElements here*/
template <class T>
class AddElements
{
private:
    T a;

public:
    // Constructor
    AddElements(T val)
    {
        a = val;
    }

    // Add for int and float
    T add(T &n)
    {
        return a + n;
    }

    // String Concatanation
    T concatenate(T b)
    {
        return a + b;
    }
};

int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        string type;
        cin >> type;
        if (type == "float")
        {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int")
        {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string")
        {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
