// Importing standard Input/Output Libraries
#include <iostream>
using namespace std;

class Node {
    public:
    // Declaring member variables
        long data;
        Node *next; // This is what, makes the class "linkable" - A pointer to an object of same type

    // Default Constructor
    Node() {
        // Putting some default values in the member variables
        data = RAND_MAX; // CODER'S NOTE: Need to replace this, using LONG_MAX or something
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

        // Description of the function is present, just before the function definition
        LinkedList();
        // Declaring function prototypes
        void insert(int data);
        void insertAt(int pos, int data);
        void Delete();
        void deleteAt(int pos);
        long countItems();
        void rev();
        void display();
};

// Default Constructor
LinkedList::LinkedList() {
    // Initializing the nodes to NULL
    head = NULL;
    tail = NULL;
}

// Declaring 'main()' function - Acts as a central hub for the program - Presents the Interface and calls related functions
int main()
{
    LinkedList *obj = new LinkedList; // Creating a new LinkedList Object to allow the access and modification of data from the list
    short choice = 0; // Stores the 'choice' of the user
    while (true) { // The interface is displayed, until the user selects 'Exit'
        // Displaying options to the user
        cout << "\nSelect an option:\n\n1. Insert an element at the end\n2. Insert an element at a particular position (*Subject to existence of the list)\n3. Delete the element at the end\n4. Delete the element at a particular position\n5. Query the number of items in the list\n6. Reverse the List\n7. Display the List\n8. Exit\n\nYour selection: ";
        cin >> choice; // Taking input
        switch (choice)
        {
            // Element-insertion, at the end
            case 1: {
                int data = 0;
                cout << "\nEnter the element (integer) to insert at the end of the List: ";
                cin >> data;
                obj->insert(data); // Calling relevant function, alongside supplying relevant data
                break;
            }
            // Element-insertion, at any desired position (as long as, the position exists in the list)
            case 2: {
                int data = 0, pos = 0;
                cout << "\nEnter the element (integer) to insert in the List: ";
                cin >> data;
                cout << "\nEnter the position, at which you want to insert the data: ";
                cin >> pos;
                obj->insertAt(pos, data); // Calling relevant function, alongside supplying relevant data
                break;
            }
            // Element-deletion, from any desired position (as long as, the position exists in the list)
            case 3: obj-> Delete(); break;
            case 4: {
                int pos = 0;
                cout << "\nEnter the position, at which you want to delete the element: ";
                cin >> pos;
                obj->deleteAt(pos); // Calling relevant function, alongside supplying relevant data
                break;
            }
            // To output the number of nodes/items, present in the list
            case 5: cout << "\nNumber of items, in the list: " << obj->countItems() << "." << endl; break;
            case 6: cout << "\nReversing the list..." << endl; obj->rev(); break;
            // Displays the entire list
            case 7: obj->display(); break;
            // Normal Program Termination
            case 8: cout << "\nExiting the program...\n" << endl; return 1;
            // In case, the input doesn't lie between 1 to 7 (Case of wrong input)
            default: cout << "\nWrong input! Please enter your choice again!" << endl;
        }
    }
} // End of main()

// Function to insert data ("data") at the end of the LinkedList
void LinkedList::insert(int data) {
    Node *node = new Node; // Creating a temporary node
    node->data = data; // Inserting the supplied data into the node

    // In case, the list is empty
    if (!head) { // if head == NULL; !head != NULL or !head == true
        head = node; // Actual insertion takes place here
        head->next = NULL;
        tail = head; // Setting 'tail' to 'head', as there's only one node in the list
    }
    // In case, the list contains at least 1 element
    else {
        tail->next = node; // Actual insertion takes place here
        tail = node; // Shifting 'tail' to the newly inserted node
    }
    cout << "\nInserted an element at the end." << endl; // Signifies successful completion of the required operation
}

// Function to insert data ("data") at a certain position ("pos") in the **ALREADY EXISITING** LinkedList
void LinkedList::insertAt(int pos, int data) {
    // if pos == 0, !pos returns 'true, else it returns false
    if (!pos || countItems() < pos) {
        cout << "\nLinked List does not have that many elements. Aborting..." << endl; // Displaying error-message
        return; // Leaving the function - Returning to main()
    }
    else {
        Node *node = new Node; // Creating a temporary node
        node->data = data; // Inserting the supplied data into the node

        // Insertion at position == 1
        if (pos == 1) { // CODER'S NOTE: Originally intended as < if (pos == 1) >. But not really needed, as 1 <=> true <=> !0.
            node->next = head; // Actual insertion takes place here
            head = node; // Setting 'head' to 'node', as the newly inserted node is the first node now
        }
        // Insertion at position > 1
        else {
            Node *i = head; // Local variable, to traverse the list
            // 'count' starts at 2, as position == 1 has already been accounted for
            for (long count = 2 ; count < pos ; i = i->next, count++); // Loop, to move 'i' to exactly 1 position behind the desired node (where insertion is to take place)
            node->next = i->next; // Actual insertion takes place here (and the next line)
            i->next = node; // Linking the newly inserted node with the beginning portion of the list
        }
        cout << "\nInserted an element at position " << pos << "." << endl; // Signifies successful completion of the required operation
    }
}

// Function, to delete the last element/node in the list
void LinkedList::Delete() {
    // If the list is empty
    if (head == NULL) { // CODER'S NOTE: Or, use < !countItems() > : countItems() must return 0 (i.e. The list is empty) for < !countItems() > to return 'true'
        cout << "\nThe list is empty. Nothing to delete! Aborting..." << endl; // Displaying error-message
        return; // Leaving the function - Returning to main()
    }
    // If the list has exactly 1 node
    else if (head->next == NULL) {
        delete head; // Deleting the first node itself
        head = NULL; // Setting 'head' to NULL resets the list, thereby removing all the nodes
    }
    // If the list has >= 2 nodes
    else {
        Node *i = head; // Local variable, to traverse the list
        for ( ; i->next->next ; i = i->next); // Loop, to move 'i' to exactly 1 position behind the last node (which is to be deleted)
        delete i->next; // Deletes the last node from the list
        i->next = NULL; // Setting 'i->next' to NULL to avoid leaving it "dangling"
        tail = i; // The new 'tail' (last node) of the list
    }
    cout << "\nDeleted the element at the end." << endl; // Signifies successful completion of the required operation
}

// Function, to delete any particular node, existing at a position in the list
void LinkedList::deleteAt(int pos) {
    // if pos == 0, < !pos > returns 1 or true | Also, if countItems() < pos, then the list doesn't have any such position ("yet")
    if (!pos || countItems() < pos) {
        cout << "\nLinked List does not have that many elements. Aborting..." << endl; // Displaying error-message
        return; // Leaving the function - Returning to main()
    }
    // If the element/node is at position == 1
    else if (pos == 1) {
        delete head; // Deleting 'head' deletes the first element (Or, element at position == 1)
        head = head->next; // Shifting 'head' to the 'next' node in the list -> The first element's link with the list is broken now.
    }
    // If the element/node is at a position > 1
    else {
        Node *i = head; // Local pointer variable to store address temporarily
        long count = 1; // Stores the "index" of the current element/node (denoted by 'i')
        for ( ; count < pos-1 ; i = i->next, count++); // Loop, to move 'i' to exactly 1 position behind the desired node (which is to be deleted)
        delete i->next; // Deleting 'i->next' - the element, required to be deleted
        i->next = i->next->next; // Setting 'i->next' to 'i->next->next' to avoid leaving it "dangling" as well as, to keep the list together (intact)
    }
    cout << "\nDeleted an element at position " << pos << "." << endl; // Signifies successful completion of the required operation
}
 
//Function, to count the total number of nodes present in the list
long LinkedList::countItems() {
    long count = 0; // Variable, to store the number of elements/nodes in the list
    for (Node *i = head ; i ; i = i->next) // Standard list-traversal loop
        count++;
    return count; // Returning the required 'count' of items present
}

/**
 * Function to Reverse the Linked List || DATE ADDED: 13-03-2018
 * */
void LinkedList::rev() {
    Node *cur = head->next, *nxt; // Declaring variables for temporary storage of Nodes
    // Setting 'tail' to 'head'
    head->next = NULL;
    tail = head;
    // Actual reversal takes place here
    while (cur) {
        nxt = cur->next;
        cur->next = head;
        head = cur; // Shifting 'head' by 1 node, in each iteration
        cur = nxt;
    }
    // Freeing up space, used by temporary variables
    delete cur;
    delete nxt;
    cur = NULL;
    nxt = NULL;
    cout << "\nReversal completed!" << endl;
}

// Function, to print out the elements, present inside the nodes of the list
void LinkedList::display() {
    cout << "\nPrinting all the elements in the list ('NULL' represents the ending of the list): \n" << endl;
    for (Node *i = head ; i ; i = i->next) // Standard list-traversal loop
        cout << i->data << " -> "; // Printing out the elements
    cout << "NULL" << endl; // Appends a "NULL" at the end to signify the ending of the list
}
//End of program-file
