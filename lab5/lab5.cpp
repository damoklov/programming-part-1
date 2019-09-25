#include "lab5.h"
using namespace std;


double Vector::geometricAverage()
{
    double result = pow(this->product, 1.0/(ROWS-1));
    return result;
}

int Vector::getSumAboveDiagonal()
{
    int sum = 0;

    for(int i=0; i<COLS-1; i++)
    {
        for(int j=0; j<ROWS; j++)
        {
            if (i < j)
            {
                sum += this[i].V[j];
            }
        }
        printf("Step %d | %d\n", i+1, sum);
        this->product *= sum;
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

void Vector::Sort()
{
    int arr[5];
    for (int j = 0; j < COLS; j++)
    {
        for (int i = 0; i < ROWS; i++)
        {
            arr[i] = this[i].V[j];
        }

        mergeSort(arr, 0, ROWS-1);

        for (int i = 0; i < ROWS; i++)
        {
            this[i].V[j] = arr[i];
        }

    }
}

void Vector::merge(int arr[], int l, int m, int r)
{
    int i, j;
    int size1 = m - l + 1;
    int size2 = r - m;
    int left[size1], right[size2];

    for (i = 0; i < size1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < size2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;

    int k = l;

    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void Vector::mergeSort(int arr[5], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        mergeSort(arr, leftIndex, middleIndex);
        mergeSort(arr, middleIndex + 1, rightIndex);

        merge(arr, leftIndex, middleIndex, rightIndex);
    }
}