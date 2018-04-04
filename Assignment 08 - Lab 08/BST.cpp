
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
                break;
            }
    }
    SIZE++; // Increasing the size of the tree by one, after successful insertion
}

bool search(long val, TreeNode* i) { // **** WOULD LIKE TO ANALYZE THIS
    if (!i) // Case of empty Tree
        return false;
    
    if (val == i->data)
        return true;
    else if (val < i->data)
        search(val, i->lChild);
    else if (i->data > i->data)
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

int main()
{
    short choice;
    long val;
    BST Tree;

    while (true) {
        cout << "\n\n*************BINARY SEARCH TREE*************";
        cout << "\n1. Insert a value\n2. Display the Tree's elements\n3. Search for an element\n4. Get the size of the Tree\n5. Get the median value\n6. Exit\n\nYour selection: ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                cout << "\nEnter a value, to be inserted: ";
                cin >> val;
                Tree.insert(val);
                cout << "\n" << val << " inserted into the Tree.\n";
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
            case 5: cout << "\nMedian: " << Tree.getMedian(Tree.root); break;
            case 6: return 0; // Exiting the program
            default: cout << "\nERROR: Wrong input! Please try again!";
        }
    }
}
