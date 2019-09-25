#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;


class RationalFraction
{
public:
    int numerator;
    int denominator;
    void simplify();
    int getNumerator() const;
    int getDenominator() const;
    RationalFraction();
    RationalFraction(int, int);
    RationalFraction operator+(const RationalFraction&);
    RationalFraction operator-(const RationalFraction&);
    RationalFraction operator*(const RationalFraction&);
    RationalFraction operator/(const RationalFraction&);
    bool operator<(const RationalFraction&) const;
    bool operator==(RationalFraction);
    friend ostream& operator<<(ostream&, const RationalFraction&);
    friend istream& operator>>(istream&, RationalFraction&);
};

class Set
{
public:
    Set();
    vector <RationalFraction> s;
    void sortVector();
    Set operator+(Set);
    Set operator-(Set);
    Set operator*(Set);
    Set operator/(Set);
    bool operator==(const Set&);
    friend ostream& operator<<(ostream&, const Set&);
    friend istream& operator>>(istream&, Set&);
};