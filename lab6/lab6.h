#include <iostream>
using namespace std;


class RationalFraction
{
public:
    int numerator;
    int denominator;
    void simplify();
    RationalFraction();
    RationalFraction(int, int);
    RationalFraction operator+(const RationalFraction&);
    RationalFraction operator-(const RationalFraction&);
    RationalFraction operator*(const RationalFraction&);
    RationalFraction operator/(const RationalFraction&);
    bool operator==(RationalFraction);
    friend ostream& operator<<(ostream&, const RationalFraction&);
    friend istream& operator>>(istream&, RationalFraction&);
};
