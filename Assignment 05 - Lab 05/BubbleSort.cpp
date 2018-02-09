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
    public:
    Node *head, *tail;
    // Default Constructor
    LinkedList() {
        // Initializing the nodes to NULL
        head = NULL;
        tail = NULL;
    }
    // Function to insert data ("data") at the end of the LinkedList
    void insert(int data) {
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
        // cout << "\nInserted an element at the end." << endl; // Signifies successful completion of the required operation
    }

};

class BubbleSort {
    public:

    long * sort(long arr[], int size) {
        long temp = 0;
        for (int i = 0 ; i < size ; i++)
            for (int j = 0 ; j < size-1-i ; j++) // That '-i' gives an improvement of 0.4s to 0.8s in program execution/running time
                if (arr[j] > arr[j+1]) { // Sorting in ascending order
                    temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
        return arr;
    }

    LinkedList * sort(LinkedList *list) { // IS IT OVERLOADED -> YEAH! Because return_type doesn't matter -Just the param and param_types
        long temp = 0; // Assuming 'long-int' type data stored in each node
        for (Node *i = list->head ; i ; i = i->next)
            for (Node *j = list->head ; j->next ; j = j->next)
                if (j->data > j->next->data) { // Sorting in ascending order
                    temp = j->next->data;
                    j->next->data = j->data;
                    j->data = temp;
                }
        return list;
    }
};



int main()
{
    clock_t start, end;
    double msecs;

    start = clock(); // Stores the current "time" - Analogous to "Starting a Timer" here

    /**
     * Difference of ~1s in execution time, between randomized and non-randmoized input
     * */
    /*******BubbleSort********/

    BubbleSort b_obj;

    // Sorting an array
    long arr[10]; // = {5, 44, 301, 2, 1};
    for (int i = 0 ; i < 10 ; i++)
        arr[i] = rand() % 10; // Inserting random integers (0 to 10000) in the array
    long *b_ptr = b_obj.sort(arr, 10);

    cout << "\nPrinting the bubble-sorted array:\n\n";
    for (int i = 0 ; i < 10 ; i++)
        cout << *(b_ptr+i) << " < "; // '\n' -> UNSUITABLE - INCREASES EXEC TIME BY ~1s
    cout << "\b\b\u0020"; // Removing the last "< "
    
    // Sorting a Singly-LinkedList -> IS FASTER THAN SORTING THE ARRAY????? HOW??????????? -> BECAUSE '\n'
    LinkedList *l_b, *l = new LinkedList;
    for (int i = 0 ; i < 10 ; i++)
        l->insert(rand() % 10); // Inserting random integers (0 to 10000) in the list
    l_b = b_obj.sort(l);

    cout << "\nPrinting the bubble-sorted list:\n\n";
    for (Node *i = l_b->head ; i ; i = i->next)
        cout << i->data << " -> ";
    cout << "[NULL]" << "\n";

    
    end = clock(); // Stores the current "time" - Analogous to "Ending the Timer" here
    msecs = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nEXECUTION TIME: " << msecs << " seconds." << endl;
}
