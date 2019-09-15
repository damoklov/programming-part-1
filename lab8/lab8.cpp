#include "lab8.h"
using namespace std;


Resistor::Resistor()
{
    this->type = "standard";
    this->nominal = 1.0;
    this->power = 1.0;
    this->precision = 1.0;
};

Resistor::Resistor(string iType, double iNominal, double iPower, double iPrecision)
{
    this->type = iType;
    this->nominal = iNominal;
    this->power = iPower;
    this->precision = iPrecision;
}

bool Resistor::operator==(const Resistor& other)
{
    return (type == other.type && nominal == other.nominal && power == other.power && precision == other.precision);
};
bool Resistor::operator!=(const Resistor& other)
{
    return !(type == other.type && nominal == other.nominal && power == other.power && precision == other.precision);
}


ostream& operator<<(ostream& stream, const Resistor& v)
{
    cout << "Type of resistor: " << v.type << endl;
    cout << "Nominal of resistor: " << v.nominal << endl;
    cout << "Power of resistor: " << v.power << endl;
    cout << "Precision of resistor: " << v.precision << endl;
    return stream;
};
istream& operator>>(istream& stream, Resistor& v)
{
    cout << "Enter type of resistor: "; cin >> v.type;
    cout << "Enter nominal of resistor: "; cin >> v.nominal;
    cout << "Enter power of resistor: "; cin >> v.power;
    cout << "Enter precision of resistor: "; cin >> v.precision;
    return stream;
}

void LinkedList::insert(const Resistor& value)
{
    /*Inserts a new node into the linked list*/
    if (this->start == nullptr)
    {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        this->start = new_node;
        return;
    }

    Node* last = this->start->prev; //find last node
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = this->start; //start will be next for new node
    this->start->prev = newNode; //make new node previous for starting one
    newNode->prev = last; //make the last one previous
    last->next = newNode; //make new node next for last
}
int LinkedList::search(const Resistor& key)
{
    /*Searches for element in the linked list */
    Node *temp = this->start;

    if (this->start == nullptr)
    {
        cout << "List is empty" << endl;
        return -1;
    }
    if (this->start->data == key)
    {
        cout << endl << "Element found at position #1" << endl;
        return 1;
    }
    int pos = 2; //ignoring first position
    while (temp->next != this->start)
    {
        if (temp->next->data == key)
        {
            cout << "Element found at position #" << pos << endl;
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    cout << endl << "Element not found!" << endl;
    return -1;
}
void LinkedList::deleteNode(const Resistor& key)
{
    /*Deletes node from the linked list */
    if (this->start == nullptr)
        return; //return if empty

    Node* current = this->start, *prevNode = nullptr;
    while (current->data != key)
    {
        if (current->next == this->start)
        {
            cout << "This object is not in the list!" << endl;
            return;
        }

        prevNode = current;
        current = current->next;
    }

    if (current->next == this->start && prevNode == nullptr) //if node is the only one
    {
        this->start = nullptr;
        free(current);
        return;
    }

    if (current == this->start)  //if is is on the beginning
    {
        prevNode = this->start->prev;
        this->start = this->start->next; //move 'start' forward
        prevNode->next = this->start;
        this->start->prev = prevNode;
        free(current);
    }

    else if (current->next == this->start) //if it is the last node
    {
        if (prevNode != nullptr)
        {
            prevNode->next = this->start;
            this->start->prev = prevNode;
            free(current);
        } else return;
    }
    else
    {
        Node* temp = current->next;
        if (prevNode != nullptr)
        {
            prevNode->next = temp;
            temp->prev = prevNode;
            free(current);
        } else return;
    }
}

void LinkedList::display()
{
    /*Shows all elements in the linked list */
    Node* temp = this->start;

    if (this->start == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (temp->next != this->start)
    {
        printf("|T:%s P:%.1lf N:%.1lf p:%.2lf|", temp->data.type.c_str(), temp->data.power, temp->data.nominal, temp->data.precision);
        temp = temp->next;
        cout << "<>";  // linker symbol
    }
    printf("|T:%s;P:%.1lf;N:%.1lf;p:%.2lf|\n", temp->data.type.c_str(), temp->data.power, temp->data.nominal, temp->data.precision);
}
void LinkedList::displayHigherPrecision(double prec)
{
    /*Displays all the resistors with higher or equal precision */
    Node* temp = this->start;

    if (this->start == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (temp->next != this->start)
    {
        if (temp->data.precision <= prec)
        {
            cout << temp->data << endl;
        }
        temp = temp->next;
    }
}
void LinkedList::insertInOrder(const Resistor& value)
{
    /*Inserts resistor in order of its nominal (form lowest to highest) */
    if (this->start == nullptr)
    {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        this->start = new_node;
        return;
    }
    Node* temp = this->start;
    while (temp->next != this->start)
    {
        if (temp->data.nominal > value.nominal)
        {
            Node* new_node = new Node;
            new_node->data = value;
            new_node->next = temp; //start will be next for new node
            new_node->prev = temp->prev; //make new node previous for starting one
            temp->prev = new_node;
            temp->prev->prev->next = new_node;
            return;
        }
        temp = temp->next;
    }
    this->insert(value);
}
void LinkedList::deleteAll()
{
    /*Clears entire linked list */
    Node *temp = this->start;
    while (temp->next != this->start)
    {
        this->deleteNode(temp->prev->data);
    }
    this->deleteNode(temp->data);
}
void LinkedList::displayElementInfo(int pos)
{
    /*Displays info about element regarding its position */
    Node* temp = this->start;

    if (this->start == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (pos == 1)
    {
        cout << temp->data;
        return;
    }
    int currentPos = 1;
    while (temp->next != this->start)
    {
        if (currentPos == pos)
        {
            cout << temp->data << endl;
            return;
        }
        currentPos++;
        temp = temp->next;
    }
    cout << "Wrong position value" << endl;
}
