/**
 * WORKS IN CONJUGATION WITH "BHeapArr.h" and "BHeapArr.cpp"
 */

#include <iostream>
#include "BHeapArr.cpp"
using namespace std;

int main()
{
    BHeapArr b;
    short choice;
    while (true) {
        cout << "\nBINARY HEAP DATA STRUCTURE, USING ARRAYS\n";
        cout << "\n1. Insert an element\n2. Delete the Root Key (Element) from the Heap\n3. Display the Heap\n4. Exit\n\nYour selection: ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                long val;
                cout << "\nEnter a value to enter into the Heap: ";
                cin >> val;
                b.insert(val);
                break;
            }
            case 2: b.delRoot(); break;
            case 3: b.disp(); break;
            case 4: return 0;
            default: cout << "Wrong Input! Please try again!";
        }
    }
}
