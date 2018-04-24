/**
 * WORKS - Check "mainForBH.cpp"
 */

#include <iostream>
#include "BHeapArr.h"
using namespace std;

long BHeapArr::parent(long i) {
    return (i-1)/2;
}

long BHeapArr::lChild(long i) {
    return (2*i+1);
}

long BHeapArr::rChild(long i) {
    return (2*i+2);
}

void BHeapArr::heapify(long arr[], long i, long size) {
    long l = lChild(i), r = rChild(i), largest = i;
    if (l < size && arr[l] > arr[i])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, largest, size);
    }
}

void BHeapArr::insert(long val) {
    if (SIZE == 0)
        hArr[0] = val;
    else if (SIZE < 1000) { // If the capacity hasn't been reached
        hArr[SIZE] = val;
        long n = SIZE;
        while (n > 0 && hArr[n] > hArr[parent(n)]) {
            swap(&hArr[n], &hArr[parent(n)]);
            n = parent(n);
        }
    }
    SIZE++;
}

void BHeapArr::delRoot() {
    if (SIZE == 0)
        cout << "\nHeap is empty. Nothing to delete.\n";
    else if (SIZE == 1) {
        cout << "\nRoot Key *0* " << hArr[0] << " was deleted from the heap.\n";
        SIZE = 0; // Resets the heap
    }
    else {
        long prevRoot = hArr[0];
        swap(&hArr[0], &hArr[SIZE-1]);
        heapify(hArr, 0, --SIZE); // The last element (which was previously, the ROOT) is lost now
        cout << "\nRoot Key *prev* " << prevRoot << " was deleted from the heap.\n";
    }
}

void BHeapArr::disp() {
    if (SIZE == 0)
        cout << "\nHeap is empty. Nothing to display.\n";
    else {
        cout << "\nDisplaying the Heap: \n";
        for (long i = 0 ; i < SIZE ; i++)
            cout << hArr[i] << "\n";
        cout << "\n";
    }
}
