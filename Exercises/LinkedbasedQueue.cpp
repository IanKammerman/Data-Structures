//Linked Based Queue Exercise
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next; //Will be the pointer to the next node in the list 
    
    //Constructor
    node(int value) : data(value), next(nullptr) {}
};

class Queue{
    private:
    node* front; //Pointer for the front of the queue
    node* end; //Pointer for the end of the queue 
    int count;

    public:
    //Constructor 
    Queue() : front(nullptr), end(nullptr), count(0){}

    void Enqueue(int value){
        node* NextNode = new node(value); //Create a new node when function is called 
        if(end == nullptr){
            front = end = NextNode;
        }
        else{
            end->next = NextNode;
            end = NextNode;
        }
        count++;
    }
    int Dequeue(){
        if(isEmpty()){
            cout << "Error, the queue is empty";
            return -1;
        }
        int value = front->data;
        node* temp = front;
        front = front->next;
        if(front == nullptr){
            end = nullptr;
        }
        count--;
        return value;
    }
    bool isEmpty() const{
        return count == 0;
    }

};

int main(){
    Queue myQ;

    cout << "Adding numbers..." << endl;
    for (int i = 0; i <= 5; i++){
        cout << "Adding " << i << endl;
        myQ.Enqueue(i);
    }
    cout << "Removing numbers.. " << endl;
    while(!myQ.isEmpty()){
        int removednum = myQ.Dequeue();
        cout << "Removed number is " << removednum << endl;
    }
    cout << "Dequeuing from empty queue " << endl;
    int removednum = myQ.Dequeue();
    if (removednum == -1){
        cout << "\nThe queue is empty" << endl;
    }
    return 0;
}