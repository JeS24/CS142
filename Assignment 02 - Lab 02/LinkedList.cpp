#include <iostream>
using namespace std;

class Node {
    public:
        long data;
        Node *next;
};

class LinkedList {
    public:
        Node *head, *tail;

        LinkedList();
        void insert(int data);
        void insertAt(int pos, int data);
        void delet();
        void deleteAt(int pos);
        void countItems();
        void display();
};

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}

int main()
{
    LinkedList *obj = new LinkedList;
    short choice = 0;
    cout << "\nSelect an option:\n\n1. Insert an element at the end\n2. Insert an element at a particular position\n3. Delete the element at the end\n4. Delete the element at a particular position\n5. Query the number of items in the list\n6. Display the List\n\nYour selection: ";
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
        case 3: obj-> delet(); break;
        case 4: {
            int pos = 0;
            cout << "\nEnter the position, at which you want to delete the element: ";
            cin >> pos;
            obj->deleteAt(pos);
            break;
        }
        case 5: obj->countItems(); break;
        case 6: obj->display(); break;
        default: cout << "\nWrong input! Please run the program again!" << endl;
    }
}

//Function to insert data ("data") at the end of the LinkedList
void LinkedList::insert(int data) {
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    tail = node;
    cout << "\nInserted a node at the end." << endl;
    main();
    /**
    for (Node *i = head ; i ; i = i->next) {
        if (!(i->next)) //if i->next == NULL, then "! of that" should give 'true', else 'false'
            i->next = node;
            node->next = tail;
    }*/
}

//Function to insert data ("data") at a certain position ("pos") in the LinkedList
void LinkedList::insertAt(int pos, int data) {
    Node *node = new Node;
    node->data = data;

    long count = 1;
    for (Node *i = head ; i ; i = i->next) {
        if (count == (pos-1)) {
            node->next = i->next;
            i->next = node;
            break;
        }
        count++;
    }
    if (count > pos)
        cout << "No such position exists in the list. Aborting..." << endl;
    else
        cout << "\nInserted a node at position " << pos << "." << endl;
    main();
}

void LinkedList::delet() {
    Node *i = head;
    for ( ; i->next ; i = i->next);
    i->next = NULL;
    tail = i;
    cout << "\nDeleted the node at the end." << endl;
    main();
}

void LinkedList::deleteAt(int pos) {
    long count = 1;
    for (Node *i = head ; i ; i = i->next) {
        if (count == (pos-1)) {
            i->next = i->next->next;
            i->next->next = NULL ;
            break;
        }
        count++;
    }
    if (count > pos)
        cout << "No such position exists in the list. Aborting..." << endl;
    else
        cout << "\nDeleted a node at position " << pos << "." << endl;
    main();
}

void LinkedList::countItems() {
    long count = 0;
    for (Node *i = head ; i ; i = i->next)
        count++;
    cout << "\nNumber of items, in the list: " << count << "." << endl;
    main();
}

void LinkedList::display() {
    cout << "\nPrinting all the elements in the list: \n" << endl;
    for (Node *i = head ; i ; i = i->next) {
        if (i->next)
            cout << i->data << " -> ";
        else
            cout << "NULL" << endl;
    }
    main();
}
