#include <iostream>
using namespace std;

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
    int partition (long arr[], int low, int high)
    {
        int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element
    
        for (int j = low; j <= high-1; j++)
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
     * arr[]: Array to be sorted,
     * low: Starting index,
     * high: Ending index
     **/
    long * sort(long arr[], int low, int high)
    {
        if (low < high)
        {
            // PI is the partitioning index, arr[PI] will now be at the correct place
            int PI = partition(arr, low, high);
    
            // Separately sort elements in the two partitions, created by the PI Index
            sort(arr, low, PI - 1);
            sort(arr, PI + 1, high);
        }
        else
            return arr;
    }

    LinkedList * sort()
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
