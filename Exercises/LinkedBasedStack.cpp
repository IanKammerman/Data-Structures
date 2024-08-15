//Linked Based Stack
#include <iostream>
#include <stack>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value) : data(value), next(nullptr) {}

};
class Stack{
    private:
    stack<int> st;
    public:
    void push(int value){
        st.push(value);
    }
    bool isEmpty(){
        return st.empty();
    }
    int pop(){
        if (isEmpty()){
            cout << "The Stack is empty\n";
            return -1;
        }
        else{
            int popped = st.top();
            st.pop();
            return popped;
        }
    }
    int count(){
        return st.size();
    }
};
int main(){
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "The Stack count is " << stack.count() << '\n';
    int count = stack.count();
    for(int i = 0; i < count +1; i++){
        int value = stack.pop();
        if(value != -1)
            cout << "The number popped is: " << value << '\n';
        else
        break;
    }
}

