//Hash Table Exercise
#include <iostream>
using namespace std;

class HashTable {
//Private members of class Hashtable
private:
    static const int size = 27;
    int table[size];
    int hash(int key) {
        return key % size;
    }
//Public Members of class Hashtable
public:
    HashTable() {
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
    }

    void add(int value) {
        int index = hash(value);
        while (table[index] != -1) {
            index = (index + 1) % size;
        }
        table[index] = value;
    }

    int lookup(int value) {
        int index = hash(value);
        int counter = 0;

        while (table[index] != value && counter++ < size) {
            if (table[index] == -1) {
                return -1;
            }
            index = (index + 1) % size;
        }
        if (table[index] == value){
            return index;
            } 
            else {
                return -1;
            }
        }

    };

int main() {
    HashTable ht;

    int choice, value;
    //Ask for user input
    do {
        cout << "1. Add Value \n2. Lookup Value \n3. Exit \nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to add to the table: ";
                cin >> value;
                ht.add(value);
                break;
            case 2:
                cout << "Enter a value to lookup: ";
                cin >> value;
                if (ht.lookup(value) != -1) {
                    cout << "Value found is in the table.\n";
                } else {
                    cout << "Value not found is not in the table.\n";
                }
                break;
            case 3:
                cout << "Exited.\n";
                break;
            default:
                cout << "Pick a number.\n";
        }
    } while (choice != 3);
    return 0;
}