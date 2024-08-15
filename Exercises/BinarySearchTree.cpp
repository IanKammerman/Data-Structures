//Binary Search Tree Lab
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
    private:
    Node* root;

    Node* addRecurisve(Node* node, int value){
        if(node == nullptr){
            return new Node(value);
        }
        if (value < node->data)
            node->left = addRecurisve(node->left, value);
        else if (value > node->data)
            node->right = addRecurisve(node->right, value);
        return node;
    }

    void printOrder(Node* node){
        if (node != nullptr){
            printOrder(node->left);
            cout << node->data << " ";
            printOrder(node->right);
        }
    }

    public:
    BST() : root(nullptr) {}

    void add(int value){
        root = addRecurisve(root, value);
    }

    void print(){
        printOrder(root);
        cout << endl;
    }
};

int main(){
    BST tree;
    tree.add(5);
    tree.add(3);
    tree.add(8);
    tree.add(2);
    tree.add(4);
    tree.add(6);
    tree.add(9);

    cout << "Traversal: ";
    tree.print();
    return 0;
}