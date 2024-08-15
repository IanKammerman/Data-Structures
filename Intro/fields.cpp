//Implementation FIle
#include "fields.h"
#include <iostream>
using namespace std;


//Constructor
    fields::fields(int count){
        array_size = count;
        array = new int[array_size];
    }
//Load
    void fields::load(){
        int exit = -1;
        cout << "Enter " << array_size << " numbers: ";
        for (int i = 0; i < array_size; i++){
            cin >> array[i];
            if (array[i] == exit)
            break;
        }
    }
//Search
    int fields::search(int Key){
        for (int i = 0; i < array_size; i++){
            if (array[i] == Key){
                return i;
            }
        }
        return -1;
    }
//Print
    void fields::print(){
        cout << "The array is ";
        for (int i = 0; i < array_size; i++){
            cout << array[i] << " ";
        }
    }
