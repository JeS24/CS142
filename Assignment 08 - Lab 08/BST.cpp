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
        long DEPTH;

    BST(): root(NULL), DEPTH(0) {}
    void insert(long val);
    void del(long val);
    void disp(TreeNode* i); // Should present the user with choices - InOrder, PostOrder, PreOrder <- REMARK : [[MAYBE]] NOT REALLY, 
                 // as the insertion takes a different path, each time

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

}

void BST::del(long val) {

}

void BST::disp(TreeNode* i) {
    // Use Recursion here
    if (i && (i->lChild || i->rChild)) {
        disp(i->lChild);
        disp(i->rChild);
    }
    else
        cout << i->data << " " << "\n";
}

int main()
{
    short choice;
    BST Tree;

    while (true) {
        cout << "\n\n*************BINARY SEARCH TREE*************";
        cout << "\n1. Insert a value.\n2. Display the Tree (InOrder probably)\n\nYour selection: ";
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
            case 2: {
                cout << "\nDisplaying the tree...\n";
                Tree.disp(Tree.root);
                break;
            }
            default: cout << "\nERROR: Wrong input! Please try again!";
        }
    }
}
