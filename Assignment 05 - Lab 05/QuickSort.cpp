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

    //Function, to count the total number of nodes present in the list
    long countItems() {
        long count = 0; // Variable, to store the number of elements/nodes in the list
        for (Node *i = head ; i ; i = i->next) // Standard list-traversal loop
            count++;
        return count; // Returning the required 'count' of items present
    }
};

class QuickSort {
    public:

    // Function, to swap two elements
    void swap(long* a, long* b) //
    {
        long temp = *a;
        *a = *b;
        *b = temp;
    }
    
    /** This function takes last the element as a "pivot"; places the pivot element at its correct position in the sorted
     * array, and places all smaller values (smaller than pivot) to the left of pivot and all greater elements to the right
     * of pivot.
     **/
    int partition(long arr[], int low, int high)
    {
        int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element
    
        for (int j = low ; j <= high-1 ; j++)
            if (arr[j] <= pivot) { // if current element <= pivot
                i++;    // Incrementing index of smaller element
                swap(&arr[i], &arr[j]);
            }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    
    /** The actual function that implements QuickSort
     * arr[]: Array, to be sorted
     * low: Starting index
     * high: Ending index
     **/
    long * sort(long arr[], int low, int high)
    {
        if (low < high)
        {
            // PI: Partitioning Index
            int PI = partition(arr, low, high); // arr[PI] will now be at the correct place
    
            // Separately sorting elements in the two partitions, created by the PI Index
            sort(arr, low, PI - 1);
            sort(arr, PI + 1, high);
        }
        else
            return arr;
    }

    LinkedList * q_sort(LinkedList *list) {
        long arr[list->countItems()], index = 0;
        for (Node *i = list->head ; i ; i = i->next)
            arr[index++] = i->data;
        sort(arr, 0, index-1);
        index = 0;
        for (Node *i = list->head ; i ; i = i->next)
            i->data = arr[index++] ;
        return list;
    }
};

int main()
{
    clock_t start, end;
    double msecs;

    start = clock();

    //******QuickSort********

    // Sorting an array
    long arr[10000]; // = {5, 44, 301, 2, 1};
    for (int i = 0 ; i < 10000 ; i++)
        arr[i] = rand() % 10000; // Inserting random integers (0 to 10000) in the array

    QuickSort q_obj;

    long *q_ptr = q_obj.sort(arr, 0, 9999);
    cout << "\nPrinting the quick-sorted array:\n\n";
    for (int i = 0 ; i < 10000 ; i++)
        cout << *(q_ptr+i) << " < ";

    // Sorting a Singly-LinkedList
    LinkedList *l_q, *l = new LinkedList;
    for (int i = 0 ; i < 10000 ; i++)
        l->insert(rand() % 10000); // Inserting random integers (0 to 10000) in the list
    l_q = q_obj.q_sort(l);

    cout << "\nPrinting the quick-sorted list:\n\n";
    for (Node *i = l_q->head ; i ; i = i->next)
        cout << i->data << " -> ";
    cout << "[NULL]" << "\n";

    /*******QuickSort - END********/
    
    end = clock();
    msecs = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nEXECUTION TIME: " << msecs << " seconds." << endl;  
}
