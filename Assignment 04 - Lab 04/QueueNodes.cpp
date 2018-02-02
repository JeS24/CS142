#include <iostream>
using namespace std;

// Using definition of "Node" from LinkedList.cpp
class Node{
    public:
        long data;
        Node *next; // Pointer to next node
};

class Queue{
	Node *front, *back;

    public:
        Queue() {
            front = NULL;
            back = NULL;
        }

        void enqueue(long data) {
            Node *temp = new Node;
            temp->data = data;
            temp->next = NULL;
            if (!isEmpty())
                back->next = temp; // Adding at the last position, like a real "Queue"
            else
                front = temp;
            back = temp;
            cout << "\n" << data << " enqueued.\n";
        }

        void dequeue(){
            if (isEmpty())
                cout << "\nQueue is already empty.\n";
            else {
                if (back == front) {// Case of single node/element
                    delete front;
                    front = NULL;
                }
                else {
                    Node *temp = front->next;
                    delete front; // Removing the node/element at the front
                    front = temp; // Setting the 'next' node/element as the node/element at front now
                    temp = NULL;
                    delete temp; // Deleting 'temp' to ****
                }
                cout << "\nDequeued an element.\n";
            }
        }

        void display() {
            cout << "\nDisplaying the Queue from front to back: \n\n";
            for (Node *i = front ; i ; i = i->next)
                cout  <<  i->data  <<  " <- " ;
            cout  <<  "xxENDxx"  << endl;
        }

        bool isEmpty() {
            return (!front); // if front == NULL, '1' or 'true' is returned and vice-versa
        }
};

int main(){
    Queue Q;
    while (true)
    {
        short choice = 0;
        cout << "\n-----------------------------------------------------------";
        cout << "\n\t\t    QUEUES USING NODES\n\n1: Enqueue\n2: Dequeue\n3: Display Queue\n4: Exit\n\nEnter your choice (1-4): ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                long data = 0;
            	cout << "\nEnter a number to push into the Queue: ";
            	cin >> data;
                Q.enqueue(data);
                break;
            }
            case 2: Q.dequeue(); break;
            case 3: Q.display(); break;
            case 4: return 0; // Exiting the program
            default: cout << "\nIncorrect choice entered! Please try again!"; break;
        }
    }
}
