#include "lab6.h"
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


/* Class 'RationalFraction' functions definitions start here*/
RationalFraction::RationalFraction(int m, int n)
{
    numerator = n < 0 ? -m : m;
    denominator = n < 0 ? -n : n;
    simplify();
};
RationalFraction::RationalFraction()
{
    numerator = 1;
    denominator = 1;
};
int RationalFraction::getNumerator() const
{
    return this->numerator;
}
int RationalFraction::getDenominator() const
{
    return this->denominator;
}
void RationalFraction::simplify()
{
    int n = numerator < 0 ? -numerator : numerator;
    int d = denominator;
    int largestDivisor = n > d ? n : d;

    int greatestCommonDivisor = 0;

    for (int i=largestDivisor; i>=2; i--)
        if (numerator % i == 0 && denominator % i == 0)
        {
            greatestCommonDivisor = i;
            break;
        }

    if (greatestCommonDivisor != 0)
    {
        numerator /= greatestCommonDivisor;
        denominator /= greatestCommonDivisor;
    }
}
RationalFraction RationalFraction::operator+(const RationalFraction& other)
{
    RationalFraction result;
    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    if (denominator != 0) result.simplify();
    return result;
};
bool RationalFraction::operator<(const RationalFraction& r) const
{
    return (this->getNumerator() * r.getDenominator() - this->getDenominator() * r.getNumerator()) > 0;
}
RationalFraction RationalFraction::operator-(const RationalFraction& other)
{
    RationalFraction result;
    result.numerator = numerator * other.denominator - other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    if (denominator != 0) result.simplify();
    return result;
};
RationalFraction RationalFraction::operator*(const RationalFraction& other)
{
    RationalFraction result;
    result.numerator = other.numerator * numerator;
    result.denominator = other.denominator * denominator;
    if (denominator != 0) result.simplify();
    return result;
};
RationalFraction RationalFraction::operator/(const RationalFraction& other)
{
    RationalFraction result;
    result.numerator = numerator * other.denominator;
    result.denominator = denominator * other.numerator;
    if (denominator != 0) result.simplify();
    return result;
};
bool RationalFraction::operator==(RationalFraction other)
{
    simplify();
    other.simplify();
    return (numerator == other.numerator && denominator == other.denominator);
};
ostream& operator<<(ostream& stream, const RationalFraction& result)
{
    if (result.denominator == 0)
        stream << endl << "Division by zero!" << endl;
    else
        stream << result.numerator << "/" << result.denominator;
    return stream;
};
istream& operator>>(istream& stream, RationalFraction& result)
{
    cout << "Enter numerator and denominator:" << endl;
    stream >> result.numerator >> result.denominator;
    result.numerator = result.denominator < 0 ? -result.numerator : result.numerator;
    result.denominator = result.denominator < 0 ? -result.denominator : result.denominator;
    return stream;
}


/* Class 'Set' functions definitions start here*/
Set::Set()
= default;;

Set Set::operator+(Set other)
{
    Set unionSet;
    this->sortVector();
    other.sortVector();
    set_union(this->s.begin(), this->s.end(),
               other.s.begin(), other.s.end(),
               back_inserter(unionSet.s));
    return unionSet;
};
Set Set::operator-(Set other)
{
    Set differenceSet;
    this->sortVector();
    other.sortVector();
    set_difference(this->s.begin(), this->s.end(), other.s.begin(), other.s.end(),
                   back_inserter(differenceSet.s));
    return differenceSet;
};
Set Set::operator*(Set other)
{
    Set intersectionSet;
    this->sortVector();
    other.sortVector();
    set_intersection(this->s.begin(), this->s.end(),
                     other.s.begin(), other.s.end(),
                     back_inserter(intersectionSet.s));
    return intersectionSet;
};
Set Set::operator/(Set other)
{
    Set symmetricDifferenceSet;
    this->sortVector();
    other.sortVector();
    set_symmetric_difference(
            this->s.begin(), this->s.end(),
            other.s.begin(), other.s.end(),
            back_inserter(symmetricDifferenceSet.s));
    return symmetricDifferenceSet;
};
bool Set::operator==(const Set& other)
{
    return equal(this->s.begin(), this->s.end(), other.s.begin());
};

ostream& operator<<(ostream& stream, const Set& result)
{
    for(auto i : result.s)
        stream << i << ' ';
    return stream;
};
istream& operator>>(istream& stream, Set& result)
{
    RationalFraction a;
    int count = 0;
    cout << "How much items do you want to insert: ";
    cin >> count;
    for(int i=0; i<count; i++)
    {
        stream >> a;
        result.s.insert(result.s.begin(), a);
    }
    return stream;
}
void Set::sortVector()
{
    int p;

    for (int i = 0; i < this->s.size(); i++)
    {
        p = i;
        for (int j = i + 1; j < this->s.size(); j++)
        {
            if (this->s[j] < this->s[p]) //Change was here!
            {
                p = j;
            }
        }

        RationalFraction temp = this->s[p];
        this->s[p] = this->s[i];
        this->s[i] = temp;
    }
}