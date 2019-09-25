#include "lab5.h"
using namespace std;


int main()
{
    Vector b[5];
    InputMatrix(b);
    b->Sort();
    OutputMatrix(b);
    b->getSumAboveDiagonal();
    double geometricAverage = b->geometricAverage();
    cout <<  geometricAverage << endl;
    return 0;
}

