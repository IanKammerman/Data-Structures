//Array Based Queue exercise
#include <iostream>

using namespace std; 

class Array{
    //Private members of class array
    private:
    static const int MaxSize = 10;
    int Count, Front, Back;
    int array[MaxSize];

    //Public members of class Array
    public:
    //Initliaze variables upon construction
    Array() : Count(0), Front(0), Back(0) {}

    //Add value to the back of the queue 
    void Enqueue(int value){
        if(Count == MaxSize){
            cout << " The list is full, the number will not be added\n";
        }
        else{
            array[Back] = value;
            Back = (Back + 1) % MaxSize;
            Count++;
        }
    }
    //Remove value from front of the queue
    int Dequeue(){
        if(isEmpty()){
            cout << "The List is empty\n";
            return -1;
        }
        else{
            int value = array[Front];
            Front = (Front + 1) % MaxSize;
            Count--;
            return value;
        }
    }
    //Check if the queue is emtpy;
    bool isEmpty() const{
        return Count == 0;
    }
};
