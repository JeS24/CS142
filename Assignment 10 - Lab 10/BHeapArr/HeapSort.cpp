/**
 * WORKS IN CONJUGATION WITH "BHeapArr.cpp" -- Makes use of heapify(), from BHeapArr
 */

#include <iostream>
#include "BHeapArr.cpp"
using namespace std;

void HeapSort(long arr[], long size) {
    BHeapArr b;

    // Building the heap
    for (int i = (size - 2)/2 ; i >= 0 ; i--) // Setting 'i' to (size/2 -1) covers the entire heap, as the maximum reach of any 'i' is (2*i + 2)
        b.heapify(arr, i, size); // So, for a particular 'i', 2*i + 2 = size => i = (size-2)/2 => i = size/2 - 1
    
    while (size > 0) {
        swap(&arr[0], &arr[size-1]);
        b.heapify(arr, 0, --size);
    }
}

int main() {
    long arr[] = {2, 21, 34, 53, 0, 3, 1, 4, 645, 56}; // Just a check
    HeapSort(arr, 10);
    cout << "\nSorted Array: \n";
    for (int t = 0 ; t < 10 ; t++)
        cout << arr[t] << "\n";
    cout << "\n";
}
