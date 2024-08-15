//Program 2, doubly linked list to track data
#include <iostream>
using namespace std;

//Node 
struct Node {
    string name;
    int weight;
    Node *PrevName, *NextName;
    Node *PrevWeight, *NextWeight;

    Node(string name, int weight) : name(name), weight(weight), PrevName(nullptr), NextName(nullptr), PrevWeight(nullptr), NextWeight(nullptr) {}
};

//Doubly Linked List class
class People {
private:
    Node *NameHead, *WeightHead;

    void SortName(Node* node) {
        if (!NameHead || node->name < NameHead->name) {
            node->NextName = NameHead;
            if (NameHead) NameHead->PrevName = node;
            NameHead = node;
        } else {
            Node *current = NameHead;
            while (current->NextName && current->NextName->name < node->name) {
                current = current->NextName;
            }
            node->NextName = current->NextName;
            if (current->NextName) current->NextName->PrevName = node;
            current->NextName = node;
            node->PrevName = current;
        }
    }

    void SortWeight(Node* node) {
        if (!WeightHead || node->weight < WeightHead->weight) {
            node->NextWeight = WeightHead;
            if (WeightHead) WeightHead->PrevWeight = node;
            WeightHead = node;
        } else {
            Node *current = WeightHead;
            while (current->NextWeight && current->NextWeight->weight < node->weight) {
                current = current->NextWeight;
            }
            node->NextWeight = current->NextWeight;
            if (current->NextWeight) current->NextWeight->PrevWeight = node;
            current->NextWeight = node;
            node->PrevWeight = current;
        }
    }

public:
    People() : NameHead(nullptr), WeightHead(nullptr) {}

    void insert(string name, int weight) {
        Node *node = new Node(name, weight);
        SortName(node);
        SortWeight(node);
    }

    void PrintName() {
        cout << "Names & weights sorted(ascending) by name: ";
        Node *current = NameHead;
        while (current) {
            cout << current->name << ": " << current->weight;
            if (current->NextName) cout << ", ";
            current = current->NextName;
        }
        cout << endl;
    }

    void PrintWeight() {
        cout << "Names & weights sorted(ascending) by weight: ";
        Node *current = WeightHead;
        while (current) {
            cout << current->name << ": " << current->weight;
            if (current->NextWeight) cout << ", ";
            current = current->NextWeight;
        }
        cout << endl;
    }
};

int main() {
    People list;
    //Loop for input of names and weights
    for (int i = 0; i < 15; ++i) {
        string name;
        int weight;
        getline(cin, name);
        cin >> weight;
        cin.ignore();
        list.insert(name, weight);
    }
    //Call output functions
    list.PrintName();
    list.PrintWeight();
    return 0;
}

/* Output with IO
Mark
150
Tina
115
Zach
55
Amy
140
Steve
220
Brian
250
Liz
125
Brian
220
Laura
115
Alex
175
Jason
210
Eric
175
Aaron
195
Kim
135
Brandon
78
Names & weights sorted(ascending) by name: Aaron: 195, Alex: 175, Amy: 140, Brandon: 78, Brian: 220, Brian: 250, Eric: 175, Jason: 210, Kim: 135, Laura: 115, Liz: 125, Mark: 150, Steve: 220, Tina: 115, Zach: 55
Names & weights sorted(ascending) by weight: Zach: 55, Brandon: 78, Laura: 115, Tina: 115, Liz: 125, Kim: 135, Amy: 140, Mark: 150, Eric: 175, Alex: 175, Aaron: 195, Jason: 210, Brian: 220, Steve: 220, Brian: 250
*/