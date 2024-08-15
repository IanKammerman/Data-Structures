//Sort Exercise
#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int split (int array[], int low, int high){
    int pivot = array[high];
    int i = low -1;
    for (int j = low; j <= high - 1; j++){
        if(array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }

    }
    swap(&array[i+1], &array[high]);
    return (i+1);
}

void quicksort(int array[], int low, int high){
    if (low < high){
        int pivot = split(array, low, high);
        quicksort(array, low, pivot -1);
        quicksort(array, pivot+1, high);
    }
}

void output(int array[], int size){
    for(int i=0; i < size; i++)
    cout << array[i]  << " " << endl;
}

int main(){
    int array[] = {10, 7, 8, 9, 1, 5};
    int num = sizeof(array)/sizeof(array[0]);
    quicksort(array, 0, num-1);
    cout << "Sorted array is \n";
    output(array, num);
    return 0;
}