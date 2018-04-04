/**
 * BINARY (SEARCH) TREE IMPLEMENTATION
 * Author: JS
 * 
 * Comments:
 * 1. Variables, which have been declared just above any function, correspond to that function only (even though, they enjoy global scope)
 */

#include <iostream>
using namespace std;

class TreeNode {
    public:
        long data;
        TreeNode *parent; // redundant
        TreeNode *lChild;
        TreeNode *rChild;

    TreeNode(long val): data(val), parent(NULL), lChild(NULL), rChild(NULL) {}
};

class BST {
    public:
        TreeNode* root = NULL;
        long SIZE;

    BST(): root(NULL), SIZE(0) {}
    void insert(long val);
    void del(long val);
    void disp(BST Tree); // Wrapper for several traversal methods
    void dispInOrder(TreeNode* i);
    void dispPreOrder(TreeNode* i);
    void dispPostOrder(TreeNode* i);

    long getMedian(TreeNode* i);   
    bool search(long val, TreeNode *i);

    long countNodes(TreeNode* i); // Counts the number of nodes in i's subtree (includes 'i')
    void rangePrint(long m, long n, TreeNode* i);

    // To be implemented later
    long getNodeDepth(long val); // Or, maybe "TreeNode* i" as parameter
};

void BST::insert(long val) {
    TreeNode *temp = new TreeNode(val);

    if (!root)
        root = temp;
    else {
        TreeNode *i = root; // 'i' is needed as an "iterator//index"
        while (i)
            if (val > i->data)
                if (i->rChild)
                    i = i->rChild;
                else {
                    temp->parent = i;
                    i->rChild = temp;
                    break;
                }
            else if (val < i->data)
                if (i->lChild)
                    i = i->lChild;
                else {
                    temp->parent = i;
                    i->lChild = temp;
                    break;
                }
            else {
                cout << "\nElement already present in the Tree.\n";
                return;
            }
    }
    SIZE++; // Increasing the size of the tree by one, after successful insertion
    cout << "\n" << val << " inserted into the Tree.\n";
}

bool search(long val, TreeNode* i) { // **** WOULD LIKE TO ANALYZE THIS
    if (!i) // Case of empty Tree (Recursively) -- When a leaf has been reached and the value is yet to be found -- return false.
        return false;
    
    if (val == i->data)
        return true;
    else if (val < i->data)
        search(val, i->lChild);
    else
        search(val, i->rChild);
}

void BST::del(long val) {

}


long counter = 0;
long BST::getMedian(TreeNode* i) {
    if (counter == SIZE/2) {
        return i->data;
    }

    if (i) {
        getMedian(i->lChild);
        counter++;
        getMedian(i->rChild);
    }
}


void BST::disp(BST Tree) {
    // In case, the tree is empty
    if (!Tree.root) {
        cout << "\nThe tree is empty. Nothing to display!\n";
        return;
    }
    // Otherwise...
    short choice;
    cout << "\nIn what order, do you wish to display the list?\n1. In-order\n2. Pre-order\n3. Post-order\n\nYour selection: ";
    cin >> choice;
    switch (choice)
    {
        case 1: cout << "Displaying the elements, in \"Inorder\": "; dispInOrder(Tree.root); break;
        case 2: cout << "Displaying the elements, in \"Pre-order\": "; dispPreOrder(Tree.root); break;
        case 3: cout << "Displaying the elements, in \"Post-order\": "; dispPostOrder(Tree.root); break;
        default: cout << "\nERROR: Wrong input! Please try again!";
    }
    cout << "\n";
}

void BST::dispInOrder(TreeNode* i) {
    if (i) {
        dispInOrder(i->lChild);
        cout << i->data << " ";
        dispInOrder(i->rChild);
    }
}

void BST::dispPreOrder(TreeNode* i) {
    if (i) {
        cout << i->data << " ";
        dispPreOrder(i->lChild);
        dispPreOrder(i->rChild);
    }
}

void BST::dispPostOrder(TreeNode* i) {
    if (i) {
        dispPostOrder(i->lChild);
        dispPostOrder(i->rChild);
        cout << i->data << " ";
    }
}

long size;
long BST::countNodes(TreeNode* i) {
    if (i) {
        countNodes(i->lChild);
        size++;
        countNodes(i->rChild);
    }
    return size;
}

void BST::rangePrint(long m, long n, TreeNode *i) { // Split the functions into 2 -- 
    if (!i)
        return;
    if (i->data <= m) {
        if (i->data == m)
            cout << "\n" << i->data;
        rangePrint(m, n, i->rChild);
    }
    else if (i->data >= n) {
        if (i->data == n)
            cout << "\n" << i->data;
        rangePrint(m, n, i->lChild);
    }
    else { // if (i->data > m && i->data < n) // For values, lying within the range -- (m, n)
        rangePrint(i->data, n, i);
        rangePrint(m, i->data, i);
    }
}

// To enable access to certain other functions
void ExpFeatures(BST Tree)
{
    short choice;
    while (true) {
        cout << "\n\n*************BINARY SEARCH TREE*************";
        cout << "\n---------------Other actions---------------";
        cout << "\n1. Actually count the nodes and print it out\n2. Range Search or Print (Needs 2 inputs -- a Range)\n3. Get the Median value\n4. Exit to Main Menu\n\nYour selection: ";
        cin >> choice;
        switch (choice)
        {
            case 1: cout << "\nThe Tree has " << Tree.countNodes(Tree.root) << " node(s)."; break;
            case 2: {
                long m, n;
                cout << "\nEnter the value, where the printing begins, 'm': ";
                cin >> m;
                cout << "Enter the value, where the printing ends, 'n': ";
                cin >> n;
                if (m > n) { // Check for 'm' and 'n'
                    cout << "\nWrong input! 'n' must be > 'm'!\n";
                    break;
                }
                cout << "\nPrinting values, in the given range... ";
                Tree.rangePrint(m, n, Tree.root);
                break;
            }
            case 3: cout << "\nMedian: " << Tree.getMedian(Tree.root); break;
            case 4: return;
            default: cout << "\nERROR: Wrong input! Please try again!";
        }
    }
}

int main()
{
    short choice;
    long val;
    BST Tree;

    while (true) {
        cout << "\n\n*************BINARY SEARCH TREE*************";
        cout << "\n1. Insert a value\n2. Display the Tree's elements\n3. Search for an element\n4. Get the size of the Tree\n5. Other actions (Opens another menu)\n6. Exit\n\nYour selection: ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                cout << "\nEnter a value, to be inserted: ";
                cin >> val;
                Tree.insert(val);
                break;
            }
            case 2: Tree.disp(Tree); break;
            case 3: {
                cout << "\nEnter the value, to be searched: ";
                cin >> val;
                cout << "\n" << val << " is " << ((search(val, Tree.root))?"present.\n":"absent.\n");
                break;
            }
            case 4: cout << "\nSize of the Tree: " << Tree.SIZE << "\n"; break;
            case 5: ExpFeatures(Tree); break;
            case 6: return 0; // Exiting the program
            default: cout << "\nERROR: Wrong input! Please try again!";
        }
    }
}
