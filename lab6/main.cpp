#include <iostream>
#include "lab6.cpp"
using namespace std;


int main()
{
    RationalFraction a, b;
    cin >> a;
    cin >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a == b = " << (a == b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    return 0;
}
