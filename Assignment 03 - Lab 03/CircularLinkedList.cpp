// Importing standard Input/Output Libraries
#include <iostream>
using namespace std;

class Node {
    public:
    // Declaring member variables
        long data;
        Node *prev, *next; // This is what, makes the class "linkable" - Pointer to an object of same type

    // Default Constructor
    Node() {
        // Putting some default values in the member variables
        data = RAND_MAX; // CODER'S NOTE: Need to replace this, using LONG_MAX or something
        prev = NULL;
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
        void insert(long data);
        void insertAt(int pos, long data);
        void Delete();
        void deleteAt(int pos);
        long countItems();
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
        cout << "\nSelect an option:\n\n1. Insert an element at the end\n2. Insert an element at a particular position (*Subject to existence of the list)\n3. Delete the element at the end\n4. Delete the element at a particular position (*Subject to existence of the list)\n5. Query the number of items in the list\n6. Display the List\n7. Exit\n\nYour selection: ";
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
            // Displays the entire list
            case 6: obj->display(); break;
            // Normal Program Termination
            case 7: cout << "\nExiting the program...\n" << endl; return 1;
            // In case, the input doesn't lie between 1 to 7 (Case of wrong input)
            default: cout << "\nWrong input! Please enter your choice again!" << endl;
        }
    }
} // End of main()

// Function to insert data ("data") at the end of the LinkedList
void LinkedList::insert(long data) {
    Node *node = new Node; // Creating a temporary node
    node->data = data; // Inserting the supplied data into the node

    // In case, the list is empty
    if (!head) { // if head == NULL; !head != NULL or !head == true
        head = node; // Actual insertion takes place here
        // Linking 'head' & 'tail' (They both refer to the same node though)
        head->next = tail;
        head->prev = tail;
        tail = head; // Setting 'tail' to 'head', as there's only one node in the list
        // CODER'S NOTE: Explicit mention is necessary, as another node (which (might) have had another node as 'next') has been labelled 'tail' now.
        tail->prev = head;
        tail->next = head;
    }
    // In case, the list contains at least 1 element
    else {
        // Actual insertion takes place in the following lines
        tail->next = node;
        node->prev = tail;
        tail = node; // Shifting 'tail' to the newly inserted node
        tail->next = head; // CODER'S NOTE: Explicit mention is necessary, as another node (which (might) have had another node as 'next') has been labelled 'tail' now.
    }
    cout << "\nInserted an element at the end." << endl; // Signifies successful completion of the required operation
}

// Function to insert data ("data") at a certain position ("pos") in the **ALREADY EXISITING** LinkedList
void LinkedList::insertAt(int pos, long data) {
    // if pos == 0, !pos returns 'true', else it returns 'false'
    if (!pos || countItems() < pos) {
        cout << "\nLinked List does not have that many elements. Aborting..." << endl; // Displaying error-message
        return; // Leaving the function - Returning to main()
    }
    else {
        Node *node = new Node; // Creating a temporary node
        node->data = data; // Inserting the supplied data into the node

        // Insertion at position == 1
        if (pos == 1) {
            node->next = head; // Actual insertion takes place here
            head->prev = node;
            head = node; // Setting 'head' to 'node', as the newly inserted node is the first node now
            head->prev = tail; // Linking 'head' with 'tail' to make the list "circular"
            tail->next = head; // Setting 'tail->next' to "newly-created" 'head'
        }
        // Insertion at position > 1
        else {
            Node *i = head; // Local variable, to traverse the list
            // 'count' starts at 2, as position == 1 has already been accounted for
            for (long count = 2 ; count < pos ; i = i->next, count++); // Loop, to move 'i' to exactly 1 position behind the desired node (where insertion is to take place)
            // Actual insertion takes place in the following lines
            node->next = i->next;
            node->prev = i;
            // Linking the newly inserted node with the rest of the list
            i->next->prev = node;
            i->next = node;
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
    else if (head == tail) {
        delete head; // Deleting the first node itself
        head = NULL; // Setting 'head' to NULL resets the list, thereby removing all the nodes (Also to not leave it "dangling")
        tail = NULL; // Needed to ensure reverse-traversal functions properly
    }
    // If the list has >= 2 nodes
    else {
        Node *i = head; // Local variable, to traverse the list
        for ( ; i->next != head ; i = i->next); // Loop, to move 'i' to the last node (which is to be deleted)
        tail = i->prev; // The new 'tail' (last node) of the list
        tail->next = head;
        delete i; // Deletes the last node (as required) from the list
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
        Node *temp = head->next; // Creating a variable to store the address of 'head->next' temporarilys
        if (head == tail) {
            delete head; // Deleting the first node itself
            // Resetting the list
            head = NULL;
            tail = NULL;
        }
        else {
            temp->prev = tail; // Pointing "second" node's 'prev' to 'tail'
            tail->next = temp; // Pointing 'tail' to the "new" 'head'
            delete head; // Deleting 'head' deletes the first element (Or, element at position == 1)
            head = temp; // Setting up the new 'head'
        }
        // Freeing the memory-space allocated to the temporary variable
        temp = NULL;
        delete temp;
    }
    // If the element/node is at a position > 1
    else {
        Node *i = head; // Local pointer variable to store address temporarily
        long count = 1; // Stores the "index" of the current element/node (denoted by 'i')
        for ( ; count < pos ; i = i->next, count++); // Loop, to move 'i' to the desired node (which is to be deleted)
        if (i->next == head) { // i.e. if 'i' corresponds to 'tail'
            i->prev->next = head; // Pointing the second-last node to 'head'
            head->prev = i->prev; // Linking the new 'tail' with 'head
            tail = i->prev; // Designating 'i->prev' as the new 'tail'
        }
        else {
            // Setting up links between the 'prev' and 'next' elements(s) to 'i' (the current element)
            i->prev->next = i->next;
            i->next->prev = i->prev;
        }
        delete i; // Deleting the required node/element
        i = NULL; // Setting 'i' to 'NULL' to avoid leaving it "dangling"
    }
    cout << "\nDeleted an element at position " << pos << "." << endl; // Signifies successful completion of the required operation
}

//Function, to count the total number of nodes present in the list
long LinkedList::countItems() {
    long count = 1; // Variable, to store the number of elements/nodes in the list
    Node *i = head; // Local pointer variable, used to store address temporarily (For List Traversal)
    if (!i) // If head == NULL, !i (same as '!head') returns 1
        return 0; // When head == NULL, the list has no elements
    for ( ; i->next != head ; i = i->next) // Standard list-traversal loop (Stops, when 'head' is encountered again)
        count++;
    return count; // Returning the required 'count' of items present
}

// Function, to print out the elements, present inside the nodes of the list
void LinkedList::display() {
    cout << "\nPrinting all the elements in the circular list ('NULL' represents the ending of the list): \n" << endl;
    Node *i = head; // Local pointer variable, used to store address temporarily (For List Traversal)
    if (!i) // If head == NULL, !i (same as '!head') returns 1
        cout << "The list is empty." << endl; // When head == NULL, the list has no elements
    else // Case, when the list isn't empty
        for ( ; i->next != head ; i = i->next) // Standard list-traversal loop (Stops, when 'head' is encountered again)
            cout << i->data << " <-> "; // Printing out the elements
    // Appends 'tail' and then head' (again), at the end (if they are != NULL), to highlight the circular nature of the list
    if (tail && head) // If both 'head' and 'tail' are NOT NULL...
        cout << tail->data << " <-END-> " << head->data << " <-> ..." << endl;
}
//End of program-file
