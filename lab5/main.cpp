#include "lab5.h"
using namespace std;


int main()
{
    Vector b[5];
    InputMatrix(b);
    Sort(b);
    OutputMatrix(b);
    Vector::getSumAboveDiagonal(b);
    cout << Vector::geometricAverage(b, b->product) << endl;
    return 0;
}

