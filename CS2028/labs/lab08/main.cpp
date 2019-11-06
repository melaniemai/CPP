#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Class for tree nodes
class Node{
public:
    int data;
    Node *left, *right;

    // Constructor. Allocates a new node w/ the given data and NULL left and right pointers
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


void outputTree(Node *root, int totalSpaces){
    if(root == NULL){
        return;
    }
    else{
        totalSpaces += 5;

        // recursively calls outputTree with the right subtree
        outputTree(root->right, totalSpaces);

        cout << endl;
        for(int i = 1; i < totalSpaces; i++){
            cout << " ";
        }
        // outputs value in current node
        cout << root->data << endl;

        // recursively calls outputTree with the left subtree
        outputTree(root->left, totalSpaces);
    }
}

void outputTreeHelper(Node *root){
    // sets the value to be outputted to 0 so
    // the root node is output at the left of the screen
    outputTree(root, 0);
}

int main()
{
    Node *root = new Node(49);
    root->left = new Node(28);
    root->right = new Node(83);

    root->left->left = new Node(18);
    root->left->right = new Node(40);
    root->right->left = new Node(71);
    root->right->right = new Node(97);

    root->left->left->left = new Node(11);
    root->left->left->right = new Node(19);
    root->left->right->left = new Node(32);
    root->left->right->right = new Node(44);
    root->right->left->left = new Node(69);
    root->right->left->right = new Node(72);
    root->right->right->left = new Node(92);
    root->right->right->right = new Node(99);

    outputTreeHelper(root);



    return 0;
}
