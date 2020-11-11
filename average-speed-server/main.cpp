// C++ program to demonstrate insert operation
// in binary search tree
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long ul;

// BST node
struct Node {
    pair<string, ul> data;
    struct Node *left, *right;
};

// Utitlity function to create a new node
Node* newNode(pair<string, ul> newData)
{
    Node* temp = new Node;

    temp->data.first = newData.first;
    temp->data.second = newData.second;


    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// A utility function to insert a new
// Node with given key in BST
Node* insert(Node* root, pair<string, ul> newData)
{
    // Create a new Node containing
    // the new element
    Node* newnode = newNode(newData);

    // Pointer to start traversing from root and
    // traverses downward path to search
    // where the new node to be inserted
    Node* x = root;

    // Pointer y maintains the trailing
    // pointer of x
    Node* y = NULL;

    while (x != NULL) {
        y = x;
        if (newData.second < x->data.second)
            x = x->left;
        else
            x = x->right;
    }

    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (y == NULL)
        y = newnode;

    // If the new key is less then the leaf node key
    // Assign the new node to be its left child
    else if (newData.second < y->data.second)
        y->left = newnode;

    // else assign the new node its right child
    else
        y->right = newnode;

    // Returns the pointer where the
    // new node is inserted
    return y;
}

// A utility function to do inorder
// traversal of BST
void Inorder(Node* root)
{
    if (root == NULL)
        return;
    else {
        Inorder(root->left);
        cout << root->data.first << " " << root->data.second << "\n";
        Inorder(root->right);
    }
}

// Driver code
int main()
{
    /* Let us create following BST
         50
        / \
      30  70
        / \ / \
    20 40 60 80 */

    Node* root = NULL;
    pair<string, ul> p1, p2, p3, p4, p5;

    p1.first = "1";
    p1.second = 111;

    p2.first = "2";
    p2.second = 222;

    p3.first = "3";
    p3.second = 333;

    p4.first = "4";
    p4.second = 444;

    p5.first = "5";
    p5.second = 555;

    root = insert(root, p1);
    insert(root, p2);
    insert(root, p3);
    insert(root, p4);
    insert(root, p5);

    // Print inoder traversal of the BST
    Inorder(root);

//    pair<string, ul> PAIR1;

//    PAIR1.first = "48";
//    PAIR1.second = 932812782;

//    cout << PAIR1.first << " ";
//    cout << PAIR1.second << endl;

    return 0;
}
