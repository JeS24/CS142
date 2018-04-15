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
        void heapify(long i);
        void insert(long val);
        long delRoot(); // Or, getMax() -- Returns the Root Key, as well as deletes it.
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
    while (i && heap[i] < heap[parent(i)]) {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
    cout << "\n" << val << " entered into the Heap.\n";
}

long delRoot() {
    
    else
        swap(&heap[0], &heap[heap.size()-1]); // Swapping Root Key with the last element
    
    if (heap.size() == 1) {
        prevRoot = heap[0];
        heap.clear();
    }

    heapify(0);
    cout << "\n" << val << " entered into the Heap.\n";
}

void H::heapify(long i) {
    long l = 2*i + 1;
    long r = 2*i + 2;
    long biggest = i;
    if (l < heap.size() && heap[l] < heap[i])
        biggest = l;
    if (r < heap.size() && heap[r] < heap[biggest])
        biggest = r;
    if (biggest != i)
    {
        swap(&heap[i], &heap[biggest]);
        heapify(biggest);
    }
}


int main()
{
    H h;
    short choice;
    while (true) {
        cout << "\nBINARY HEAP DATA STRUCTURE\n";
        cout << "\n1. Insert an element\n2. Delete the Root Key (Element) from the heap\n\nYour selection: ";
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
                if (h.heap.empty())
                    cout << "\nHeap is empty. Nothing to delete.\n";
                else if (h.heap.size() == 1) {
                    cout << "\n"
                    h.heap.clear();
                }
                else {
                    long prevRoot = h.delRoot();
                    if (h.delRoot() > 0)
                        cout << 
                }
                break;
            }
            default: cout << "Wrong Input! Please try again!";
        }
    }
}