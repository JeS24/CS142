#include <iostream>
using namespace std;

class Node {
    public:
        long data;
        Node *next;
    
    Node() {
        data = 0;
        next = NULL;
    }
};

class LinkedList { // Generic Definition for LinkedList
    public:
        Node *head = new Node; // Should Call the Contructor to initialize 'head' ****

        /* LinkedListforStacks() { // SHOULDN'T WORK ****
            head = NULL;
        }*/

    long countItems() {
        long count = 0;
        for (Node* i = head ; i ; i = i->next)
            count++;
        return count;
    }

    short insert(long data, int pos) { // Declaring the function as 'short', because the return values aren't large
        if (pos < 0 && pos > countItems())
            return -1; // ERROR CODE -1 denotes that "pos" doesn't exist in the LinkedList
        else if (pos == 0) { // Inserting the first element
            Node *node = new Node;
            node->data = data;
            if (!head) {
                head = node;
                head->next = NULL;
                node = NULL; // Removing "node's" reference to "head"
            }
            else {
                node->next = head;
                head = node;
            }
            return 0; // Denotes insertion at pos == 0
        }
        else { // **** WON'T THAT BE THE ONLY CASE LEFT NOW??
            Node* node, i = head;
            node->data = data;
            for (long count = 0 ; count < pos ; count++, i = i->next); // To 1 element before the desired element
            node->next = i->next;
            i->next = node;
            return 1; // Denotes insertion at pos != 0
        }
    }

    short del(int pos) { // Declaring the function as 'short', because the return values aren't large
        if (pos < 0 && pos > countItems())
            return -1; // ERROR CODE -1 denotes that "pos" doesn't exist in the LinkedList
        else if (pos == 0) { // Deleting the first element
            Node *temp = head->next;
            delete head;
            head = temp;
            delete temp;
            temp = NULL; // **** TEST REMOVING THIS
            return 0; // Denotes deletion at pos == 0
        }
        else { // **** WON'T THAT BE THE ONLY CASE LEFT NOW??
            Node* i = head;
            for (long count = 0 ; count <= pos ; count++, i = i->next); // To the desired element
            i->prev = i->next;
            delete i;
            i = NULL; // **** TEST REMOVING THIS
            return 1; // Denotes deletion at pos != 0
        }
    }

    void display() {
        for (Node *i = head; i ; i = i->next)
            cout << i->data << " -> ";
        cout << " xENDx" << endl;
    }
};

class StackLL {
    public:
        LinkedList *S;

    StackLL() {
        S = NULL;
    }

    void push(long data) {
        cout << "\n" << data << ((S->insert(data, 0) == 0)?" pushed into the Stack.\n":" cannot be pushed. WARNING: Stack Underflow.");
    }

    void pop() {
            cout << ((S->del(0) == 0)?"\nElement popped out of the Stack.\n":"\nWARNING: STACK UNDERFLOW (Stack is empty)\n");
    }

    bool isEmpty() {
        return (!S->head);
    }

    void display() {
        cout << "\nDisplaying the Stack:\n\n";
        S->display();
    }
};

class QueueLL {
    public:
        LinkedList *S;

    QueueLL() {
        S = NULL;
    }

    void nQ(long data) {
        cout << "\n" << data << ((S->insert(data, 0) == 0)?" pushed into the Stack.\n":" cannot be pushed. WARNING: Stack Underflow.");
    }

    void dQ() {
            cout << ((S->del(0) == 0)?"\nElement dequeued.\n":"\nWARNING: STACK UNDERFLOW (Stack is empty)\n");
    }

    bool isEmpty() {
        return (!S->head);
    }

    void display() {
        cout << "\nDisplaying the Stack:\n\n";
        S->display();
    }
};

int main()
{
    
}
