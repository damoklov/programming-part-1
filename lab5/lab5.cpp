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

    for(int i=0; i < COLUMNS - 1; i++)
    {
        for(int j=0; j<ROWS; j++)
        {
            if (i < j)
            {
                sum += this[i].sequenceContainer[j];
            }
        }
        printf("Step %d | %d\n", i+1, sum);
        this->product *= sum;
        sum = 0;
    }
    return sum;
}

void inputMatrix(Vector vector[])
{
    for (int i = 0; i < COLUMNS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            cout << "[" << i << "][" << j << "] = ";
            cin >> vector[i].sequenceContainer[j];
        }
    }
}

void outputMatrix(Vector vector[])
{
    for(int i = 0; i < COLUMNS; i++)
    {
        for(int j = 0; j < ROWS; j++)
        {
            cout << setw(5) << vector[i].sequenceContainer[j] << " ";
        }
        cout << endl;
    }
}

void Vector::sortColumnsAscendingOrder()
{
    int array[SIZE];
    for (int j = 0; j < COLUMNS; j++)
    {
        for (int i = 0; i < ROWS; i++)
        {
            array[i] = this[i].sequenceContainer[j];
        }

        mergeSortColumnsAscending(array, 0, ROWS - 1);

        for (int i = 0; i < ROWS; i++)
        {
            this[i].sequenceContainer[j] = array[i];
        }
    }
}

void Vector::merge(int array[], int left, int middle, int right)
{
    int i, j;
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int* leftSide = new int[leftSize];
    int* rightSide = new int[rightSize];

    for (i = 0; i < leftSize; i++)
        leftSide[i] = array[left + i];
    for (j = 0; j < rightSize; j++)
        rightSide[j] = array[middle + 1 + j];

    i = 0;
    j = 0;

    int k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftSide[i] <= rightSide[j])
        {
            array[k] = leftSide[i];
            i++;
        }
        else
        {
            array[k] = rightSide[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        array[k] = leftSide[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        array[k] = rightSide[j];
        j++;
        k++;
    }
}

void Vector::mergeSortColumnsAscending(int arr[SIZE], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        mergeSortColumnsAscending(arr, leftIndex, middleIndex);
        mergeSortColumnsAscending(arr, middleIndex + 1, rightIndex);
        merge(arr, leftIndex, middleIndex, rightIndex);
    }
}
