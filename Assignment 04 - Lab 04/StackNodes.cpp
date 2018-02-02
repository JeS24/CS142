#include<iostream>
using namespace std;

// Using definition of "Node" from LinkedList.cpp
class Node {
    public:
        long data;
        Node *next; // Pointer to next Node
};

class StackLL {
	Node *top = new Node;

    public:
        StackLL() {
            top = NULL;
        }

        void push(long data) {
            Node *temp = new Node;
            temp->data = data;
            temp->next = NULL;
            if (top)
                temp->next = top;
            top = temp;
            cout << "\n" << data << " pushed into the stack.\n";
        }

        void pop() {
            if (!top)
                cout << "\nThe Stack is empty. Nothing to print.\n";
            else {
                if (!(top->next)) {
                    delete top;
                    top = NULL; // To avoid leaving 'top' dangling
                }
                else { // if (top && top->next) ->> When both exist
                    Node *temp = top->next;
                    delete top; // Popping the last-inserted node/element
                    top = temp; // Setting the 'next' node/element as the new 'top-most' node/element
                    temp = NULL;
                    delete temp; // Deleting 'temp' to ****
                }
                cout << "\nPopped an element.\n";
            }
        }

        void display() {
            cout << "\nDisplaying the Stack from top to bottom: \n\n";
            for (Node *i = top ; i ; i = i->next)
                cout  <<  i->data  <<  " -> " ;
            cout  <<  "NULL"  << endl;
        }

        bool isEmpty() {
            return (!top);
        }

        /**
         * Empties the entire Stack 
         * void empty() {
            if (!top)
                cout << "\nThe Stack is already empty.\n";
            else {
                for (Node *i = top ; i ; ) {
                    top = i->next; // Shifting 'top' to the 'next' node/element in each iteration
                    delete i;
                    i = top;
                }
                cout << "\nStack Emptied!\n";
            }
        }
        */
};

int main()
{
    StackLL S;// = new StackLL;
    while (true)
    {
        short choice = 0;
        cout << "\n-----------------------------------------------------------";
        cout << "\n\t\t    STACKS USING NODES\n\n1: Push\n2: Pop\n3: Display Stack\n4: Check, if the Stack is empty (*Empty the **** Stack*)\n5: Exit\n\nEnter your choice (1-5): ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                long data = 0;
            	cout << "\nEnter a number to push into the Stack: ";
            	cin >> data;
                S.push(data);
                break;
            }
            case 2: S.pop(); break;
            case 3: S.display(); break;
            case 4: cout << "\nThe Stack is " << ((S.isEmpty())?"empty.\n":"not empty.\n"); break;
            case 5: return 0; // Exiting the program
            default: cout << "\nIncorrect choice entered! Please try again!"; break;
        }
    }
}
