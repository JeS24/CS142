#include <iostream>
#include <vector>
using namespace std;

// Implementation of MaxHeap
class BinaryHeap {
    public:
        vector <long> heap;
        // NOTE: It's not necessary to keep a SIZE/CAPACITY var, as it can be queried using heap.size() or heap.capacity().

        BinaryHeap(): heap(0) {}
        long parent(long i);
        // long lChild(long i);
        // long rChild(long i);
        void heapify(vector <long> h, long i, long SIZE);
        void insert(long val);
        long delRoot(); // Or, getMax() -- Returns the Root Key, as well as deletes it.
        void heapSort(vector <long> h); // Implements HeapSort
        void disp(vector <long> h);
};

typedef BinaryHeap H;

long H::parent(long i) {
    return (i-1)/2;
}
/* FOR LATER USE
long H::lChild(long i) {
    return (2*i + 1);
}

long H::rChild(long i) {
    return (2*i + 2);
}
*/

// UTILITY FUNCTION
long swap(long *i, long *j) {
    long temp = *i;
    *i = *j;
    *j = temp;
}

void H::insert(long val) {
    heap.push_back(val); // Inserting at the back of the vector

    long i = heap.size()-1;
    while (i != 0 && heap[i] > heap[parent(i)]) {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
    cout << "\n" << val << " entered into the Heap.\n";
}

long H::delRoot() { // Called only if heap.size() > 1 || Should make "this" function handle all cases, though
    long prevRoot = heap[0];
    swap(&heap[0], &heap[heap.size()-1]); // Swapping Root Key with the last element
    heap.pop_back(); // Deleting the previous Root Key
    heapify(heap, 0, heap.size());
    return prevRoot;
}

void H::heapify(vector <long> h, long i, long SIZE) {
    long l = 2*i + 1;
    long r = 2*i + 2;
    long biggest = i;
    if (l < SIZE && h[l] > h[i])
        biggest = l;
    if (r < SIZE && h[r] > h[biggest])
        biggest = r;
    if (biggest != i)
    {
        swap(&h[i], &h[biggest]);
        heapify(h, biggest, SIZE);
    }
}

void H::heapSort(vector <long> h) {
    for (long j = h.size() ; j > 1 ; j--) {
        swap(&h[0], &h[j-1]);
        heapify(h, 0, j-1);
    }
}

void H::disp(vector <long> h) {
    cout << "\nDisplaying the heap: \n";
        for (auto i : h)
            cout << i << "\n";
        cout << "\n";
}


int main()
{
    H h;
    short choice;
    while (true) {
        cout << "\nBINARY HEAP DATA STRUCTURE\n";
        cout << "\n1. Insert an element\n2. Delete the Root Key (Element) from the Heap\n3. Display the Heap\n4. HeapSort the elements in the Heap\n5. Exit\n\nYour selection: ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                long val;
                cout << "\nEnter a value to enter into the Heap: ";
                cin >> val;
                h.insert(val);
                break;
            }
            case 2: {
                if (h.heap.empty()) // Transfer these checks/conditions to delRoot()
                    cout << "\nHeap is empty. Nothing to delete.\n";
                else if (h.heap.size() == 1) {
                    cout << "Root Key " << h.heap[0] << " was deleted from the heap.\n";
                    h.heap.clear();
                }
                else
                    cout << "\nRoot Key " << h.delRoot() << " was deleted from the heap.\n";
                break;
            }
            case 3: h.disp(h.heap); break;
            case 4: {
                cout << "\nEnter the elements of the heap [Vector] (Enter '0' to finish): \n";
                vector <long> h1;
                long val;
                while (cin >> val && val != 0)
                    h1.push_back(val);
                cout << "SIZE = " << h1.size() << endl;
                cout << "\nHeapSorting the elements, in the Heap...\n";
                h.heapSort(h1); // Invoking h1's heapSort function to sort the entered values
                h.disp(h1); // REALLY STUPID WAY OF HANDLING STUFF, RELATED TO HEAPSORT - ALL THESE vector ARGUMENTS
                break;
            }
            case 5: return 0;
            default: cout << "Wrong Input! Please try again!";
        }
    }
}
