#include "lab6.h"
using namespace std;


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
void RationalFraction::simplify()
{
    int n = numerator < 0 ? -numerator : numerator;
    int d = denominator;
    int largestDivisor = n > d ? n : d;

    int greatesrCommonDivisor = 0;

    for (int i=largestDivisor; i>=2; i--)
        if (numerator % i == 0 && denominator % i == 0)
        {
            greatesrCommonDivisor = i;
            break;
        }

    if (greatesrCommonDivisor != 0)
    {
        numerator /= greatesrCommonDivisor;
        denominator /= greatesrCommonDivisor;
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

