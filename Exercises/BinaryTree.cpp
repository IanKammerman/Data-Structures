//Binary Tree Lab
#include <iostream>
using namespace std;

class BinaryTree {
    private:
    int* data;
    int count, capacity;

    void TreeSize(){
        if (count == capacity){
            capacity *= 2;
            int* newData = new int[capacity];
            for(int i = 0; i < count; i++){
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
    }

    public:
    BinaryTree() : count(0), capacity(1) {
        data = new int[capacity];
    }

    void add(int value){
        TreeSize();
        data[count++] = value;
    }
    
    void print(int index = 0){
        if (index < count){
            cout << data[index] << " ";
            print(2 * index + 1);
            print(2 * index + 2);
        }
    }
};

int main(){
    BinaryTree tree;

    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);

    cout << "Traversal: ";
    tree.print();
    return 0;
}