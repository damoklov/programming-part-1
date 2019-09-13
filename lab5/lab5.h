#include <iostream>
#include <iomanip>
#include <cmath>
#define ROWS 5
#define COLS 5
using namespace std;


class Vector
{
private:
    int V[ROWS]{};
public:
    int product = 1;
    friend void InputMatrix(Vector A[]);
    friend void OutputMatrix(Vector A[]);
    friend void Sort(Vector A[]);
    static int getSumAboveDiagonal(Vector A[]);
    static double geometricAverage(Vector A[], int product);
};
