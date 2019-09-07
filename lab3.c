#include <stdio.h>
#define ROW 5
#define COL 5


void bubblesort(int arr[COL][ROW]);
void printMatrix(int arr[COL][ROW]);
void readMatrix(int arr[COL][ROW]);
double processMatrix(int arr[COL][ROW]);

int main()
{
    int arr[COL][ROW];
    readMatrix(arr);
    printf("--------------\n");
    printMatrix(arr);
    bubblesort(arr);
    printf("--------------\n");
    printMatrix(arr);
    printf("--------------\n");
    processMatrix(arr);
    return 0;
}

void printMatrix(int arr[COL][ROW])
{
    for (int i=0; i<COL; i++)
    {
        for (int j=0; j<ROW; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

void readMatrix(int arr[COL][ROW])
{
    for (int i=0; i<COL; i++)
    {
        for (int j=0; j<ROW; j++)
        {
            printf("Input [%d][%d]: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
}

void bubblesort(int arr[COL][ROW])
{
    int swap;

    for (int k = 0; k < ROW; k++)
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = i + 1; j < COL; j++)
            {
                if (arr[k][i] < arr[k][j])
                {
                    swap = arr[k][i];
                    arr[k][i] = arr[k][j];
                    arr[k][j] = swap;
                }
            }
        }
    }
}

double processMatrix(int arr[COL][ROW])
{
    double average, prod = 1.0, counter = 0.0;

    for (int i=0; i<COL; i++)
    {
        for (int j=0; j<ROW; j++)
        {
            if (i > j)
            {
                prod *= arr[i][j];
                printf("Matrix[%d][%d] is %d\n", i, j, arr[i][j]);
                counter++;
            }
            else continue;
        }
    }
    average = prod/counter;
    printf("Average value is: %lf\n", average);
    printf("Counter: %lf, Prod: %lf\n", counter, prod);
    return 0;
}