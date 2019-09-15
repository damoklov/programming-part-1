#include "lab8.cpp"
using namespace std;


int main()
{
    LinkedList ll;
    ll.insertInOrder(Resistor("CCR", 1.0, 6.0, 0.01));
    ll.insertInOrder(Resistor("WWR", 8.0, 3.0, 0.05));
    ll.insertInOrder(Resistor("TFR", 10.0, 4.5, 0.01));
    ll.insertInOrder(Resistor("CFR", 5.0, 6.0, 0.08));
    ll.insertInOrder(Resistor("MFR", 12.0, 9.2, 0.5));
    cout << "T = type, P = power, N = nominal, p = precision" << endl;
    cout << "--------------------------" << endl;
    cout << "Linked list in order of nominal:" << endl;
    ll.display();
    cout << "--------------------------" << endl;
    cout << "Inserting Resistor |T:CFR N: 7.7.0 P:4.6 p:0.03|:" << endl;
    Resistor exampleResistor("CFR", 7.5, 4.6, 0.03);
    ll.insertInOrder(exampleResistor);
    ll.display();
    cout << "--------------------------" << endl;
    cout << "Searching for it in the linked list:" << endl;
    ll.search(exampleResistor);
    cout << "--------------------------" << endl;
    cout << "Info about it:" << endl;
    ll.displayElementInfo(3);
    cout << "--------------------------" << endl;
    cout << "Deleting it:" << endl;
    ll.deleteNode(exampleResistor);
    ll.display();
    ll.search(exampleResistor);
    cout << "--------------------------" << endl;
    cout << "Displaying all the resistors with greater or equal precision:" << endl;
    ll.displayHigherPrecision(0.05);
    cout << "--------------------------" << endl;
    cout << "Deleting whole linked list:" << endl;
    ll.deleteAll();
    ll.display();
    cout << "--------------------------" << endl;
    return 0;
}