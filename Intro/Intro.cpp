#include <iostream>
#include <iomanip>
#include "fields.h"
using namespace std;

int main(){
    int size, Key;
    cout << "Enter the size of the array: ";
    cin >> size;

    fields fields(size);
    fields.load();
    cout << "Enter a number to search for: ";
    cin >> Key;

    int index = fields.search(Key);

    if(index != -1){
        cout << "Number found at index " << index << endl;
    }
    else{
        cout << "Number not found." << endl;
    }
    fields.print();
}