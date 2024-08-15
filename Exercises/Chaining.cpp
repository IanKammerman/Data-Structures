//Chaining Exercise
#include <iostream>
using namespace std;

//Node structure for the linked list
struct Node {
    int key;
    string value;
    Node* next;

    Node(int k, string v) : key(k), value(v), next(nullptr) {}
};

//Hash table class using chaining with linked lists
class HashTable {
private:
    static const int HASH_SIZE = 10;
    Node* table[HASH_SIZE] = {nullptr};

    int hashFunction(int key) {
        return key % HASH_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < HASH_SIZE; i++) {
            Node* entry = table[i];
            while (entry) {
                Node* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
    }
    //Add key with value function
    void add(int key, const string& value) {
        int index = hashFunction(key);
        Node* prev = nullptr;
        Node* entry = table[index];

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            entry = new Node(key, value);
            if (prev == nullptr) {
                table[index] = entry;
            } else {
                prev->next = entry;
            }
        } else {
            entry->value = value;
        }
    }
    //Lookup key function
    string lookup(int key) {
        int index = hashFunction(key);
        Node* entry = table[index];

        while (entry != nullptr) {
            if (entry->key == key) {
                return entry->value;
            }
            entry = entry->next;
        }

        return "Not Found";
    }
    //Delete Entry function
    bool deleteEntry(int key) {
        int index = hashFunction(key);
        Node* prev = nullptr;
        Node* entry = table[index];

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            return false;
        } else {
            if (prev == nullptr) {
                table[index] = entry->next;
            } else {
                prev->next = entry->next;
            }
            delete entry;
            return true;
        }
    }
};
//Main function asking user for input
int main() {
    HashTable ht;
    int choice, key;
    string value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Key-Value Pair\n";
        cout << "2. Lookup Value by Key\n";
        cout << "3. Delete Entry by Key\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value: ";
                cin >> key;
                cin.ignore();
                getline(cin, value);
                ht.add(key, value);
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                value = ht.lookup(key);
                cout << "Value: " << value << endl;
                break;
            case 3:
                cout << "Enter key: ";
                cin >> key;
                if (ht.deleteEntry(key)) {
                    cout << "Entry Deleted\n";
                } else {
                    cout << "Entry Not Found\n";
                }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please choose again.\n";
        }
    }

    return 0;
}