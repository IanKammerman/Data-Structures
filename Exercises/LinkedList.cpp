    //Linked List Exercise
    #include <iostream>
    using namespace std;

    class node{
        public:
        node* next;
        int data;

        node(int value) : data(value), next(nullptr) {}
    };

    class LinkedList{
        public:
        node* head;

        LinkedList() : head(nullptr){}

        void Add(int value){
            node* newNode = new node(value);
            newNode ->next = head;
            head = newNode;
        }
        void print(){
            node* current = head;
            if (current != nullptr){
                cout << current->data;
                current = current->next;
            while (current != nullptr){
                cout << ", " << current->data;
                current = current->next;
            }
            }
            cout << endl;
        }
    };

    int main(){
        LinkedList List;
        int num;

        cout << "Enter numbers, enter -1 to stop \n";
        while(true){
            cin >> num;
            if (num == -1){
                break;
            }
            List.Add(num);
        }
        cout << "Output: ";
        List.print();
    }