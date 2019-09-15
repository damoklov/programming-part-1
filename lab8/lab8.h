#include <iostream>
#include <string>
using namespace std;



class Resistor
{
public:
    Resistor();
    Resistor(string, double, double, double);
    string type;
    double nominal;
    double power;
    double precision;
    bool operator==(const Resistor&);
    bool operator!=(const Resistor&);
    friend ostream& operator<<(ostream&, const Resistor&);
    friend istream& operator>>(istream&, Resistor&);
};


class LinkedList
{
    struct Node
    {
        Resistor data;
        Node* next;
        Node* prev;
    };
public:
    void insert(const Resistor&);
    void deleteNode(const Resistor&);
    int search(const Resistor&);
    void display();
    void displayElementInfo(int);
    void deleteAll();
    void displayHigherPrecision(double);
    void insertInOrder(const Resistor&);
    Node* start = nullptr;
};

