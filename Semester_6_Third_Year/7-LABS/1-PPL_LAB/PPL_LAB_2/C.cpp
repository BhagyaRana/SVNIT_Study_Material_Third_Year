#include <iostream>
#include <iomanip>
#include <assert.h>
// U19CS012 [BHAGYA VINOD RANA]

using namespace std;

// Using Generic Class Programming, So it can be Used for Any Data Type {LL,Stack,Queue,..}
template <class T>
class vector
{
    T *p;
    int size;

public:
    // To create the vector
    void create_vector(T a);
    void set_vector_element(int i, T val);

    // To modify the value of a given element.
    void modify_vector(void);

    // To multiply by a scalar value.
    void multiply_vector(T b);

    // To display the vector in the form (10, 20, 30,…)
    void display(void);
};

template <class T>
void vector<T>::create_vector(T a)
{
    size = a;
    p = new float[size];
}

template <class T>
void vector<T>::set_vector_element(int i, T val)
{
    p[i] = val;
}

template <class T>
void vector<T>::multiply_vector(T b)
{
    for (int i = 0; i < size; i++)
        p[i] = b * p[i];
}

template <class T>
void vector<T>::display(void)
{
    cout << "p[" << size << "] = ( ";
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
            cout << p[i];
        else
            cout << p[i] << " , ";
    }
    cout << ")" << endl;
}

template <class T>
void vector<T>::modify_vector(void)
{

    cout << "~~~~> Task 2.1 - Modification by Insertion\n\n";

    int i;
    cout << "Enter Position of Element to be Deleted : ";
    cin >> i;

    assert(i >= 1 && i <= size);

    cout << "Enter the New Value of " << i << "th  element : ";
    T v;
    cin >> v;

    // 0 Based Indexing
    i--;
    p[i] = v;

    cout << "New Vector Contents : " << endl;
    display();

    cout << "\n~~~~> Task 2.2 - Modification by Deletion\n\n";

    cout << "Enter Position of Element to be Deleted : ";
    cin >> i;

    assert(i >= 1 && i <= size);

    i--;
    for (int j = i; j < size; j++)
    {
        p[j] = p[j + 1];
    }
    size--;

    cout << "New Vector Contents : " << endl;
    display();
}

int main()
{
    vector<float> v;

    cout << "\n~~~> Task 1 - Create Vector\n\n";

    int sz;
    cout << "Enter size of vector : ";
    cin >> sz;

    v.create_vector(sz);

    cout << "Enter " << sz << " Elements {e1 e2 e3 .. en} :" << endl;

    float tmp;
    for (int i = 0; i < sz; i++)
    {
        cin >> tmp;
        v.set_vector_element(i, tmp);
    }

    cout << "\n~~~> Task 4 - Display Vector\n\n";

    cout << "Vector Contents : " << endl;
    v.display();

    cout << "\n~~~> Task 3 - Multiply Vector with Scaler\n\n";

    cout << "Enter Scalar Float Number for Multiplication : ";
    cin >> tmp;
    v.multiply_vector(tmp);

    cout << "Vector Contents : " << endl;
    v.display();

    cout << "\n~~~> Task 2 - Modify Vector\n\n";
    v.modify_vector();

    return 0;
}