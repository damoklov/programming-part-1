#include "lab5.h"
using namespace std;


double Vector::geometricAverage(Vector A[], int product)
{
    double result = pow(product, 1.0/(ROWS-1));
    return result;
}

int Vector::getSumAboveDiagonal(Vector A[])
{
    int sum = 0;

    for(int i=0; i<COLS-1; i++)
    {
        for(int j=0; j<ROWS; j++)
        {
            if (i < j)
            {
                sum += A[i].V[j];
            }
        }
        printf("Step %d | %d\n", i+1, sum);
        A->product *= sum;
        sum = 0;
    }
    return sum;
}

void InputMatrix(Vector A[])
{
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            cout << "[" << i << "][" << j << "] = ";
            cin >> A[i].V[j];
        }
    }
}

void OutputMatrix(Vector A[])
{
    for(int i = 0; i < COLS; i++)
    {
        for(int j = 0; j < ROWS; j++)
        {
            cout << setw(5) << A[i].V[j] << " ";
        }
        cout << endl;
    }
}

void Sort(Vector A[])
{
    int value;
    for (int k = 0; k < COLS; k++)
    {
        for (int i = 0; i < ROWS - 1; i++)
        {
            for (int j = ROWS - 1; j >= i + 1; j--)
            {
                if (A[j].V[k] < A[j - 1].V[k])
                {
                    value = A[j].V[k];
                    A[j].V[k] = A[j - 1].V[k];
                    A[j - 1].V[k] = value;
                }
            }
        }
    }
}
