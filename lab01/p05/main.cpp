#include <iostream>

using namespace std;

template <class T>
void auSwap(T &a, T &b)
{
    T t = move(a); // steal adress
    a = move(b);   // steal adress
    b = move(t);   //  steal adress
}
// pass by value
void badSwap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}
// pass by reference
void goodSwap01(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
// pass a pointer by value
void goodSwap02(int *pA, int *pB)
{
    int t = *pA;
    *pA = *pB;
    *pB = t;
}
int main()
{
    cout << "1st int: ";
    int a = 0;
    cin >> a;
    cout << "2nd int: ";
    int b = 0;
    cin >> b;
    cout << "std::swap:" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap a = " << a << ", b =  " << b << endl;

    cout << "badSwap" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    badSwap(a, b);
    cout << "After swap a = " << a << ", b =  " << b << endl;

    cout << "goodSwap01" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap01(a, b);
    cout << "After swap a = " << a << ", b =  " << b << endl;

    cout << "goodSwap02" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap02(&a, &b);
    cout << "After swap a = " << a << ", b =  " << b << endl;

    double d1 = 1.6;
    double d2 = 3.14;
    cout << "general swap for doubles: " << endl;
    cout << "Before swap a = " << d1 << ", b = " << d2 << endl;
    auSwap(d1, d2);
    cout << "After swap a = " << d1 << ", b =  " << d2 << endl;

    string s1 = "hello";
    string s2 = "world";
    cout << "general swap for strings:" << endl;
    cout << "Before swap s1 = " << s1 << ", s2 = " << s2 << endl;
    auSwap(s1, s2);
    cout << "After swap s1 = " << s1 << ", s2 = " << s2 << endl;
}