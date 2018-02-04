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
        long temp = 0; // Assuming 'long' type data stored in each node
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

/*class QuickSort {
    public:

    // A utility function to swap two elements
    void swap(long* a, long* b) // INGENIOUS WAY, USING POINTERS
    {
        long temp = *a;
        *a = *b;
        *b = temp;
    }
    
    /** This function takes last element as pivot, places the pivot element at its correct position in sorted
     * array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right
     * of pivot
     **/
    /*int partition (long arr[], int low, int high) HERE
    {
        int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element
    
        for (int j = low; j <= high- 1; j++)
        {
            // If current element <= pivot
            if (arr[j] <= pivot)
            {
                i++;    // Incrementing index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    
    /** The actual function that implements QuickSort
     * arr[] --> Array to be sorted,
     * low  --> Starting index,
     * high  --> Ending index
     **/
    /*long * sort(long arr[], int low, int high) HERE
    {
        if (low < high)
        {
            // PI is the partitioning index, arr[p] is now at right place
            int PI = partition(arr, low, high);
    
            // Separately sort elements before and after partition
            sort(arr, low, PI - 1);
            sort(arr, PI + 1, high);
        }
        else
            return arr;
    }
};*/

int main()
{
    clock_t start, end;
    double msecs;

    start = clock();

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
    LinkedList *l_b, *l_q, *l = new LinkedList;
    for (int i = 0 ; i < 10 ; i++)
        l->insert(rand() % 10); // Inserting random integers (0 to 10000) in the list
    l_b = b_obj.sort(l);

    cout << "\nPrinting the bubble-sorted list:\n\n";
    for (Node *i = l_b->head ; i ; i = i->next)
        cout << i->data << " -> ";
    cout << "[NULL]" << "\n";

    /*******BubbleSort - END******** HERE

    /*******QuickSort******** HERE
    QuickSort q_obj;

    long *q_ptr = q_obj.sort(arr, 10);
    cout << "\nPrinting the quick-sorted array:\n\n";
    for (int i = 0 ; i < 10000 ; i++)
        cout << *(q_ptr+i) << " < ";

    /*l_q = q_obj.sort(l);  **** -> Implement "quick-"sorting lists first

    cout << "\nPrinting the quick-sorted list:\n\n";
    for (Node *i = l_q->head ; i ; i = i->next)
        cout << i->data << " -> ";
    cout << "[NULL]" << "\n";*/

    /*******QuickSort - END********/
    
    end = clock();
    msecs = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nEXECUTION TIME: " << msecs << " seconds." << endl;  
}
