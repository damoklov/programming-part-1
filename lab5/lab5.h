#include <iostream>
#include <iomanip>
#include <cmath>
#define ROWS 5
#define COLUMNS 5
#define SIZE 5
using namespace std;


class Vector
{
private:
    int sequenceContainer[ROWS]{};
public:
    int product = 1;
    friend void inputMatrix(Vector *);
    friend void outputMatrix(Vector *);
    static void mergeSortColumnsAscending(int *, int, int);
    static void merge(int *, int, int, int);
    void sortColumnsAscendingOrder();
    int getSumAboveDiagonal();
    double geometricAverage();
};
