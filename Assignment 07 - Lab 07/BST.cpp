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
        long DEPTH;

    BST(): root(NULL), SIZE(0), DEPTH(0) {}
    void insert(long val);
    void del(long val);
    void disp(BST Tree); // Wrapper for several traversal methods
    void dispInOrder(TreeNode* i);
    void dispPreOrder(TreeNode* i);
    void dispPostOrder(TreeNode* i);

    long getMedian(TreeNode* i);
    // To be implemented later      
    void search(long val);
    long getDepth() {
        return DEPTH;
    }
    long getDepth(long val);
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
            else
                if (i->lChild)
                    i = i->lChild;
                else {
                    temp->parent = i;
                    i->lChild = temp;
                    break;
                }
    }
    SIZE++; // Increasing the size of the tree by one, after successful insertion
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
    BST Tree;

    while (true) {
        cout << "\n\n*************BINARY SEARCH TREE*************";
        cout << "\n1. Insert a value\n2. Display the Tree's elements\n3. Get the median value\n4. Exit\n\nYour selection: ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                long val;
                cout << "\nEnter a value, to be inserted: ";
                cin >> val;
                Tree.insert(val);
                cout << "\n" << val << " inserted into the Tree.\n";
                break;
            }
            case 2: Tree.disp(Tree); break;
            case 3: cout << "\nMedian: " << Tree.getMedian(Tree.root); break;
            case 4: return 0; // Exiting the program
            default: cout << "\nERROR: Wrong input! Please try again!";
        }
    }
}
