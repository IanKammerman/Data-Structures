//Program 3, BST and methods
#include <iostream>
using namespace std;

//Node
struct Node {
    string name;
    int weight;
    Node* left;
    Node* right;

    Node(string name, int weight) : name(name), weight(weight), left(nullptr), right(nullptr) {}
};

//Binary Search Tree Class
class BST {
//Private functions of BST class 
private:
    Node* root;

    Node* insert(Node* node, string name, int weight) {
        if (node == nullptr) {
            return new Node(name, weight);
        }
        if (name < node->name) {
            node->left = insert(node->left, name, weight);
        } else if (name > node->name) {
            node->right = insert(node->right, name, weight);
        }
        return node;
    }

    void preorder(Node* node) {
        if (node == nullptr)
        return;
        cout << node->name << " " << node->weight << ". ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (node == nullptr)
        return;
        inorder(node->left);
        cout << node->name << " " << node->weight << ". ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) 
        return;
        postorder(node->left);
        postorder(node->right);
        cout << node->name << " " << node->weight << ". ";
    }

    int height(Node* node) {
        if (node == nullptr) 
        return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    int countLeaves(Node* node) {
        if (node == nullptr) 
        return 0;
        if (node->left == nullptr && node->right == nullptr) 
        return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }

    bool search(Node* node, string name, int& weight) {
        if (node == nullptr) 
        return false;
        if (node->name == name) {
            weight = node->weight;
            return true;
        } else if (name < node->name) {
            return search(node->left, name, weight);
        } else {
            return search(node->right, name, weight);
        }
    }

    int findLowestWeight(Node* node) {
        if (node == nullptr) 
        return 10000;
        int leftMin = findLowestWeight(node->left);
        int rightMin = findLowestWeight(node->right);
        return min(node->weight, min(leftMin, rightMin));
    }

    string findFirstAlphabeticalName(Node* node) {
        if (node == nullptr) 
        return "";
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->name;
    }
//Public Functions of BST class. Mainly Getter functions
public:
    BST() : root(nullptr) {}

    void insert(string name, int weight) {
        root = insert(root, name, weight);
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    int height() {
        return height(root);
    }

    int countLeaves() {
        return countLeaves(root);
    }

    void search(string name) {
        int weight = 0;
        if (search(root, name, weight)) {
            cout << name << ": " << weight << endl;
        } else {
            cout << name << " Not in list " << endl;
        }
    }

    int findLowestWeight() {
        return findLowestWeight(root);
    }

    string findFirstAlphabeticalName() {
        return findFirstAlphabeticalName(root);
    }
};

int main() {
    //Create BST
    BST BST;
    //Insert data for BST
    BST.insert("Tony", 175);
    BST.insert("John", 125);
    BST.insert("Daniel", 65);
    BST.insert("Cindy", 120);
    BST.insert("Mai", 135);
    BST.insert("Wesley", 250);
    BST.insert("Brooke", 125);
    BST.insert("Bryan", 195);
    BST.insert("Elias", 210);
    BST.insert("Ryan", 200);
    BST.insert("Ben", 195);
    BST.insert("Keenan", 235);
    BST.insert("Noah", 137);
    BST.insert("Andy", 92);
    //Call traversal functions
    BST.preorder();
    BST.inorder();
    BST.postorder();
    //Call functions for data of the tree
    cout << "Height of tree: " << BST.height() << endl;
    cout << "Number of leaves: " << BST.countLeaves() << endl;
    cout << "Minimum weight: " << BST.findLowestWeight() << endl;
    //Call search functions
    BST.search("Tony");
    BST.search("Aiden");
    cout << "First name alphabetically: " << BST.findFirstAlphabeticalName() << endl;
}

/*Sample Output
Tony 175. John 125. Daniel 65. Cindy 120. Brooke 125. Ben 195. Andy 92. Bryan 195. Elias 210. Mai 135. Keenan 235. Ryan 200. Noah 137. Wesley 250. 
Andy 92. Ben 195. Brooke 125. Bryan 195. Cindy 120. Daniel 65. Elias 210. John 125. Keenan 235. Mai 135. Noah 137. Ryan 200. Tony 175. Wesley 250. 
Andy 92. Ben 195. Bryan 195. Brooke 125. Cindy 120. Elias 210. Daniel 65. Keenan 235. Noah 137. Ryan 200. Mai 135. John 125. Wesley 250. Tony 175. 
Height of tree: 7
Number of leaves: 6
Minimum weight: 65
Tony: 175
Aiden Not in list 
First name alphabetically: Andy
*/
