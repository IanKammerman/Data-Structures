//Program 4 BORG language
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

//Const 
#define Table_Size 100
#define Table_Scope 100

//Create Nodes
struct Node {
    string key;
    int value;
    Node* next;
    Node(const string& key, int value) : key(key), value(value), next(nullptr) {}
};

//Hash Table
class HashTable{
    private:
    Node* Table[Table_Size];

    size_t hash(const string& key){
        size_t sum = 0;
        for(size_t i = 0; i < key.length(); ++i){
            sum += size_t(key[i]) * (i + 1);
        }
        return sum % Table_Size;
    }

    //Public members of HashTable Class
    public:
    //Initialize slots in Table
    HashTable(){
        for (int i = 0; i < Table_Size; ++i){
            Table[i] = nullptr;
        }
    }
    //Insert variable in Table
    void insert(const string& key, int value){
        size_t index = hash(key);
        Node* newNode = new Node(key, value);
        if(Table[index] == nullptr){
            Table[index] = newNode;
        }
        else{
            newNode->next = Table[index];
            Table[index] = newNode;
        }
    }
    //Search for Variable in Table
    int search(const string& key){
        size_t index = hash(key);
        Node* current = Table[index];
        while(current != nullptr){
            if(current->key == key){
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    //Clear table after block
    void clear(){
        for(int i = 0; i < Table_Size; ++i){
            Node* current = Table[i];
            while (current != nullptr){
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            Table[i] = nullptr;
        }
    }
    //Update value
    void update(const string& key, int newValue) {
        size_t index = hash(key);
        Node* current = Table[index];
        while (current) {
            if (current->key == key) {
                current->value = newValue;
                return;
            }
            current = current->next;
        }
        insert(key, newValue);
    }
    //Increment Value
    void increment(const string& key) {
    int value = search(key);
    if (value != -1) {  
        update(key, value + 1);
    } else {
        insert(key, 1); 
    }
    }
    //Decrement Value
    void decrement(const string& key) {
        int value = search(key);
        if (value != -1) {  
            update(key, value - 1);
        } else {
            insert(key, -1); 
        }
    }
};

//Global Variables
int currentScope = 0;
HashTable scopes[Table_Scope];

//Update variable if new value is assigned
void updateVariable(const string& varName, int newValue) {
    bool found = false;
    for (int i = currentScope; i >= 0; i--) {
        if (scopes[i].search(varName) != -1) {
            scopes[i].update(varName, newValue);
            found = true;
            break;
        }
    }
    if (!found) {
        scopes[currentScope].insert(varName, newValue);
        }
    }

//Increase scope by 1 when Start
void enterScope() {
    if (currentScope + 1 < Table_Scope) {
        currentScope++;
    }
}

//Decrease scope by 1 and clear block when Finish
void exitScope() {
    if (currentScope > 0) {
        scopes[currentScope].clear(); 
        currentScope--;
    }
}

//Search table for Variable
int searchInScopes(const string& varName) {
    int closestScopeIndex = -1, closestValue = -1;
    int minDistance = INT_MAX; 

    for (int i = 0; i < Table_Scope; i++) {
        if (i >= 0 && i < Table_Scope) {
            int val = scopes[i].search(varName);
            int distance = abs(currentScope - i);
            if (val != -1 && distance < minDistance) {
                minDistance = distance;
                closestScopeIndex = i;
                closestValue = val;
            }
        }
    }
    return (closestScopeIndex != -1) ? closestValue : -1;
}

//Calculate depending on expression passed in
int Operation(int left, int right, char expression) {
    switch (expression) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': 
        if(right != 0)
            return left / right;
        else
            throw runtime_error("Division by zero");
        case '%': 
        if(right != 0)
            return left % right;
        else
            throw runtime_error("Modulus by zero");
        case '^': 
            return (pow(left, right));
        default:
            throw runtime_error("Not an operation supported by BORG");
    }
}

//Switch value of two variables
void SwitchVal(const string& varName1, const string& varName2) {
    int index1, index2, value1, value2;
    if (scopes[currentScope].search(varName1) != -1 && scopes[currentScope].search(varName2) != -1) {
        value1 = scopes[currentScope].search(varName1);
        value2 = scopes[currentScope].search(varName2);
        scopes[currentScope].update(varName1, value2);
        scopes[currentScope].update(varName2, value1);
    } else {
        cout << "Variables not in scope" << endl;
    }
}

//Process input
void Processing(const string& input) {
    stringstream ss(input);
    string token, varName, nextToken;
    int num;
    ss >> token;

    if (token == "COM")
        return;
    if (token == "VAR") {
        string equal;
        int value;
        ss >> varName >> equal >> value;
        scopes[currentScope].insert(varName, value);
    } else if (token == "PRINT") {
        ss >> varName;
        int VarValue = scopes[currentScope].search(varName), OOSValue;
        if (ss.peek() == EOF) {
            int OOSValue = searchInScopes(varName);
            if(VarValue == -1 && OOSValue == -1){
                    cout << varName << " IS UNDEFINED" << endl;
                }else {
                    cout << varName << " IS " << OOSValue << endl;
                }
        }
        if (ss >> ws && !ss.eof()){
            int Operand;
            ss >> nextToken >> Operand;
            if (nextToken == "++"){
                scopes[currentScope].increment(varName);
            } else if (nextToken == "--") {
                scopes[currentScope].decrement(varName);
            } else {
                char expression = nextToken[0];
            int solution = Operation(VarValue, Operand, expression);
                cout << varName << " " << expression << " " << Operand << " IS " << solution << endl;
            }
        }
            } else if(token == "SWITCH"){
                string varName2;
                ss >> varName >> varName2;
                SwitchVal(varName, varName2);
            }else if (token == "START") {
                enterScope();
            } else if (token == "FINISH") {
                exitScope();
            }
            else {
                varName = token;
                int VarValue = scopes[currentScope].search(varName);
                if (VarValue!= -1) {
                    if (ss >> nextToken) {
                        if (nextToken == "++") {
                            scopes[currentScope].increment(varName);
                        } else if (nextToken == "--") {
                            scopes[currentScope].decrement(varName);
                        } else if (nextToken == "+" || nextToken == "-" || nextToken == "*" || nextToken == "/" || nextToken == "%" || nextToken == "^") {
                            if (ss >> num) {
                                char expression = nextToken[0];
                                int result = Operation(VarValue, num, expression);
                                cout << varName << " " << expression << " " << num << " IS " << result << endl;
                    }
                }
            }
        } else{
            ss >> nextToken;
            if (nextToken == "=")
                ss >> VarValue;
                    updateVariable(varName, VarValue);
        }
    }
}

//Int Main - Ask for user input
int main() {
    string input;
    cout << "Enter BORG Commands or EXIT to quit" << endl;
    while (getline(cin, input)) {
        if (input == "EXIT") {
            break;
        }
        Processing(input);
    }
    return 0;
}

/*
Sample IO from canvas 
Enter BORG Commands or EXIT to quit
COM HERE IS OUR FIRST BORG PROGRAM
COM WHAT A ROBUST LANGUAGE IT IS 
START
VAR BORAMIR = 25
VAR LEGOLAS = 101
PRINT BORAMIR
BORAMIR IS 25
BORAMIR ++
PRINT LEGOLAS
LEGOLAS IS 101
PRINT GANDALF
GANDALF IS UNDEFINED
PRINT BORAMIR * 2
BORAMIR * 2 IS 52
COM
COM NESTED BLOCK
COM
START
VAR GANDALF = 49
PRINT GANDALF
GANDALF IS 49
PRINT BORAMIR
BORAMIR IS 26
FINISH
PRINT GANDALF
GANDALF IS UNDEFINED
START
LEGOLAS = 1000
PRINT LEGOLAS
LEGOLAS IS 1000
FINISH
PRINT LEGOLAS
LEGOLAS IS 1000
LEGOLAS --
PRINT LEGOLAS
LEGOLAS IS 999
FINISH
EXIT
*/

/*
My IO
START
VAR RYAN = 6
VAR TONY = 2 
PRINT TONY ^ 2
TONY ^ 2 IS 4
RYAN ++
PRINT RYAN
RYAN IS 7
COM THIS DOES NOTHING
START
RYAN = 10
PRINT RYAN
RYAN IS 10
FINISH
PRINT RYAN
RYAN IS 10
START
VAR LLAMA = 12
LLAMA --
PRINT LLAMA
LLAMA IS 11
FINISH
PRINT TONY
TONY IS 2
FINISH
PRINT TONY
TONY IS UNDEFINED
FINISH
EXIT
*/