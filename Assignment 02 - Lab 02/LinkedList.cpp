#include <iostream>
using namespace std;

class Node {
    public:
        long data;
        Node *next;

    Node() {
        data = RAND_MAX; // Need to replace this, using LONG_MAX or something
        next = NULL;
    }
};

class LinkedList {
    // Declaring member variables and member functions
    public:
    /* head = First Node in the list
     * tail = Last Node in the list
     */
        Node *head, *tail;

        LinkedList();
        void insert(int data);
        void insertAt(int pos, int data);
        void Delete();
        void deleteAt(int pos);
        long countItems();
        void display();
};

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}

// Declaring 'main()' function - Acts as a central hub for the program - Presents the Interface as well as calls related functions
int main()
{
    LinkedList *obj = new LinkedList; // Creating a new List Object to access data from the list
    short choice = 0;
    while (true) {
        cout << "\nSelect an option:\n\n1. Insert an element at the end\n2. Insert an element at a particular position (*Subject to existence of the list)\n3. Delete the element at the end\n4. Delete the element at a particular position\n5. Query the number of items in the list\n6. Display the List\n7. Exit\n\nYour selection: ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                int data = 0;
                cout << "Enter the data (integer) to insert at the end of the List: ";
                cin >> data;
                obj->insert(data);
                break;
            }
            case 2: {
                int data = 0, pos = 0;
                cout << "Enter the data (integer) to insert in the List: ";
                cin >> data;
                cout << "\nEnter the position, at which you want to insert the data: ";
                cin >> pos;
                obj->insertAt(pos, data);
                break;
            }
            case 3: obj-> Delete(); break;
            case 4: {
                int pos = 0;
                cout << "\nEnter the position, at which you want to delete the element: ";
                cin >> pos;
                obj->deleteAt(pos);
                break;
            }
            case 5: cout << "\nNumber of items, in the list: " << obj->countItems() << "." << endl; break;
            case 6: obj->display(); break;
            case 7: cout << "\nExiting the program..." << endl; return 1; //Normal program termination
            default: cout << "\nWrong input! Please enter your choice again!" << endl;
        }
    }
}

// Function to insert data ("data") at the end of the LinkedList
void LinkedList::insert(int data) {
    Node *node = new Node;
    node->data = data;
    if (!head) { // if head == NULL; !head != NULL or !head == true
        head = node;
        head->next = NULL;
        tail = head;
    }
    else {
        tail->next = node;
        tail = node;
    }
    cout << "\nInserted a node at the end." << endl;
}

// Function to insert data ("data") at a certain position ("pos") in the **ALREADY EXISITING** LinkedList
void LinkedList::insertAt(int pos, int data) {
    if (!pos || countItems() < pos) { // if pos == 0, !pos returns 'true, else it returns false.
        cout << "\nNo such position exists in the list. Aborting..." << endl;
        return;
    }
    else {
        Node *node = new Node;
        node->data = data;

        if (pos) { // Originally intended as < if (pos == 1) >. But not really needed, as 1 <=> true <=> !0.
            node->next = head;
            head = node;
        }
        else {
            Node *i = head;
            for (long count = 1 ; count < pos ; i = i->next, count++);
            node->next = i->next;
            i->next = node;
        }
        cout << "\nInserted a node at position " << pos << "." << endl;
    }
}

void LinkedList::Delete() {
    if (head == NULL) { // Or, use < !countItems() > : countItems() must return 0 (i.e. The list is empty) for < !countItems() > to return 'true'
        cout << "\nThe list is empty. Nothing to delete! Aborting...\n";
        return;
    }
    else if (head->next == NULL) { // If the List has exactly 1 node
        head = NULL;
        goto JUMP_HERE; // Not a very elegant solution, but works fine and doesn't increase the logical complexity by much (Negligible, in fact)
    }
    else { // If the list has > 2 nodes
        Node *i = head;
        for ( ; i->next->next ; i = i->next);
        i->next = NULL;
        tail = i;
        goto JUMP_HERE;
    }
    JUMP_HERE: cout << "\nDeleted the node at the end." << endl;
}

void LinkedList::deleteAt(int pos) {
    if (!pos || countItems() < pos) {
        cout << "No such position exists in the list. Aborting..." << endl;
        return;
    }
    else if (pos == 1)
        head = head->next;
    else {
        Node *i = head;
        long count = 1;
        for ( ; count < pos-1 ; i = i->next, count++);
        i->next = i->next->next;
        cout << "\nDeleted a node at position " << pos << "." << endl;
    }
}

long LinkedList::countItems() {
    long count = 0;
    for (Node *i = head ; i ; i = i->next)
        count++;
    return count;
}

void LinkedList::display() {
    cout << "\nPrinting all the elements in the list: \n" << endl;
    for (Node *i = head ; i ; i = i->next)
        cout << i->data << " -> ";
    cout << "NULL" << endl;
}
