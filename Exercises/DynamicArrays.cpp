//Dynamic Arrays Excercise
#include <iostream>
using namespace std;

int main(){
    //Initialize variables
    int array_size, count = 0;
    int *array;
    int exit = -1;

    //Ask user array size
    cout << "Enter the size of the array: ";
    cin >> array_size;
    array = new int[array_size];

    //Ask user for array input
    cout << "Enter the numbers of the array, enter -1 if you want to exit: ";
    for (int i = 0; i < array_size; i++){
        cin >> array[i];
        if (array[i] == exit)
            break;
        count++;
    }

    //Print the list of numbers
    cout << "The list of numbers: ";
    for (int i = 0; i < count; i++)
        cout << array[i] << " ";
}