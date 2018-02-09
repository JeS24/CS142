#include <iostream>
using namespace std;

class StackArr {
    public:
        // Defining member variables
        // arr[0] : Denotes the bottom of the Stack
        // index : Denotes the position just after the last filled position (i.e. just after "head" or "top")
        long arr[1000];
        long index = -1;

        StackArr() {
            for (int i = 0 ; i < 1000 ; i++)
                arr[i] = INT8_MAX;
        }

        void push(long data) {
            // 'index' has to be < 999, as 999 is the last array index
            if (index < 999) {
                arr[++index] = data;
                // inde`x++; // **** TEST PUTTING THIS IN THE PREV LINE ITSELF
                cout << "\nPushed " << data << " into the Stack.\n";
            }
            else
                cout << "\nCannot push data into the Stack. WARNING: Stack Overflow.\n";
        }

        void pop() {
            if (!index) // "if (index == 0)" eq to "if (!index)"
                cout << "\nCannot pop from the Stack. WARNING: Stack Underflow.\n";
            else {
                for (long i = 0 ; i < index ; i++)
                    arr[i] = arr[i+1];
                index--;
            }
        }

        void display() {
            cout << "\nDisplaying the elements of the Stack, from top to bottom:\n\n";
            for (long i = index ; i >= 0 ; i--)
                    cout << arr[i] << "\n";
        }

        bool isEmpty() {
            return (!index); // if "EMPTY" -> !index would return 1, as index would be 0 and vice-versa
        }
};

int main()
{
    StackArr obj;
    obj.push(1);
    obj.push(2);

    obj.display();

    obj.pop();
    obj.pop();

    cout << obj.index << endl;

    obj.display();
}


/*
arr 
0 1 2 3 4 5 

push(data)

arr[i] = data;

pop()

arr[i] = default

display 

bool isEmpty() {
    return ((stack[0] == def)?true:false);
}


arr[0] == default
*/



