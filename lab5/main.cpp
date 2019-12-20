#include "lab5.h"
#define SIZE 5
using namespace std;


int main()
{
    Vector exampleVector[SIZE];
    inputMatrix(exampleVector);
    exampleVector->sortColumnsAscendingOrder();
    outputMatrix(exampleVector);
    exampleVector->getSumAboveDiagonal();
    double geometricAverage = exampleVector->geometricAverage();
    cout <<  geometricAverage << endl;
    return 0;
}

