    //Linear Search Exercise
    #include <iostream>
    using namespace std;

    //Search Function
    int Search(int *array, int array_size, int key){
        for(int i = 0; i < array_size; i++){
            if (array[i] == key){
                return i;
            }
        }
        return -1;
    }

    int main(){
        //Initalize Variables
        int key, index, array_size = 5;
        int array[] = {5, 20, 13, 24, 6};
        
        //Ask for number to search for
        cout << "Enter a value to search: ";
        cin >> key;

        //Call Function
        index = Search(array, array_size, key);

        //Print the index found from search function
        if(index != -1){
            cout << "The index of your number was at: " << index;
        }
        else
            cout << "Your number was not in the list of numbers.";
    }