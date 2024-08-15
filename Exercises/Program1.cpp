//Program 1, reverse polish expressions
#include <iostream>
#include <sstream>
using namespace std;

//Struct for creating nodes
struct node{
    float value;
    node* next;

    node(float value, node* next = nullptr) : value(value), next(next) {}
};

//Class for stack, including pop, push, check if the stack is emtpy, and evaluating the reverse polish expression
class stack{
    private:
        node* top;

    public:
        stack() : top(nullptr){}
        void push(float value){
            node* newNode = new node(value, top);
            top = newNode;
        }
        float pop(){
            if(isEmpty()){
                throw runtime_error("Error stack is empty");
            }
            node* temp = top;
            float value = temp->value;
            top = top->next;
            delete temp;
            return value;
        }
        bool isEmpty() const{
            return top == nullptr;
        }
};

//Evaluation function, check the reverse polish expression for its operators and operands, make sure they are acceptable and calculate. 
float evaluation(const string& expression){
    stack stack;
    istringstream operand(expression);
    string token;

    while (operand >> token){
        if(token == "=") 
        break;
        stringstream number(token);
        float num;
        if(number >> num){
            stack.push(num);
        }
        else{
            if(stack.isEmpty()){
                throw runtime_error("Error not enough operands and operators in the expression ");
            }
            float right = stack.pop();
            if(stack.isEmpty()){
                throw runtime_error("Error too many operators in the expression");
            }
            float left = stack.pop();
            if (token == "+")
            stack.push(left + right);
            else if (token == "-")
            stack.push(left - right);
            else if (token == "*")
            stack.push(left * right);
            else if (token == "/"){
                if(right == 0){
                throw runtime_error("Error division by zero ");
                }
            stack.push(left / right);
            }
        }
    }
    if(stack.isEmpty())
        throw runtime_error("Error stack is empty after evaluating the expression / something went wrong with the operation");
    float result = stack.pop();
    if(!stack.isEmpty())
        throw runtime_error("Error too many operands or not enough operators");
    return result;
    }

//Main function, ask for the reverse polish expression and print the solution
int main(){
    string input;
    while(true){
        cout << "Enter reverse Polish expression or 0 to exit: ";
        getline(cin, input);
        if(input == "0")
        break;

        try{
            float result = evaluation(input + "=");
            cout << result << endl;
        }
        catch (const runtime_error& e){
            cout << e.what() << endl;
        }
    }
    return 0;
}

/* Output from program with sample IO
Enter reverse Polish expression or 0 to exit: 10 15 + = 
25
Enter reverse Polish expression or 0 to exit: 10 15 - = 
-5
Enter reverse Polish expression or 0 to exit: 2.5 3.5 + = 
6
Enter reverse Polish expression or 0 to exit: 10 0 / = 
Error division by zero 
Enter reverse Polish expression or 0 to exit: 10 20 * / = 
Error too many operators in the expression
Enter reverse Polish expression or 0 to exit: -10 -30 - = 
20
Enter reverse Polish expression or 0 to exit: 100 10 50 25 / * - -2 / = 
-40
Enter reverse Polish expression or 0 to exit: 0
*/