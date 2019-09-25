#include <iostream>
#include "lab6.cpp"
using namespace std;


int main()
{
    Set exampleSet1;
    Set exampleSet2;
    cout << "Enter values for each set accordingly" << endl;
    cin >> exampleSet1;
    cin >> exampleSet2;
    cout << "Set #1: " << exampleSet1 << endl;
    cout << "Set #2: " << exampleSet2 << endl;
    Set unionSet = exampleSet1 + exampleSet2;
    Set differenceSet = exampleSet1 - exampleSet2;
    Set intersectionSet = exampleSet1 * exampleSet2;
    Set symmetricDifferenceSet = exampleSet1 / exampleSet2;
    cout << "Union: " << unionSet << endl;
    cout << "Difference: " << differenceSet << endl;
    cout << "Intersection: " << intersectionSet << endl;
    cout << "Symmetric Difference: " << symmetricDifferenceSet << endl;
    const char * areEqual = exampleSet1 == exampleSet2 ? "Yes":"No";
    cout << "Are these sets equal? " << areEqual << endl;
    return 0;
}
