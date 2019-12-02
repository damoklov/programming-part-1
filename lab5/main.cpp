#include "lab5.h"
using namespace std;


int main()
{
    Vector b[5];
    inputMatrix(b);
    b->sortColumnsAscendingOrder();
    outputMatrix(b);
    b->getSumAboveDiagonal();
    double geometricAverage = b->geometricAverage();
    cout <<  geometricAverage << endl;
    return 0;
}

