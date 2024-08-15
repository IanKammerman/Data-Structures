//Sorted Linked List Exercise 
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next; //Will be the pointer to the next node in the list 
    
    //Constructor
    node(int value) : data(value), next(nullptr){}
};

class SortedList{
    private:
    node* head;
    public: 
    SortedList() : head(nullptr){}

    void insert(int value){
        node* NewNode = new node(value);
        if(head == nullptr || head->data >= NewNode->data){
            NewNode->next = head;
            head = NewNode;
        }
        else{
            node* current = head;
            while(current->next != nullptr && current->next->data < NewNode->data){
                current = current->next;
            }
            NewNode->next = current->next;
            current->next = NewNode;
        }
    }
    void print() const{
        node* current = head;
        cout << "The linked list is: ";
        while(current != nullptr){
            cout << current->data << ", ";
            current = current->next;
        }
    }
};

int main(){
    SortedList List;
    int num;

    cout << "Enter numbers to add to the linked list, enter -1 to stop";
    while(true){
        cout << "\nEnter a number: ";
        cin >> num;
        if(num == -1){
            break;
        }
        List.insert(num);
        List.print();
    }
}