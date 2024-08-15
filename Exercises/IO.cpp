//IO exercise
#include <iostream>
using namespace std;

int main() {
    // Initialize variables
    string input, word;
    cout << "Enter a sentence: ";
    getline(cin, input);

    // Loop to read the sentence
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ') {
            word += input[i];
        }
        //Check if there is a number
        if (input[i] == ' ' || input[i+1] == '\0') {
            if (!word.empty()) {
                bool number = true;
                for (char c : word) {
                    if ((c < '0' || c > '9') && c != '.') {
                        number = false;   
                        break;
                    }
                }
                //Multiply number by 2 and print
                if (number) {
                    try {
                        float num = stof(word);
                        cout << num * 2 << endl;
                    } catch (const invalid_argument&) {
                        cout << word << endl;
                    }
                } else {
                    //Print if not a number
                    cout << word << endl;
                }
                //Clear word for next word or number
                word.clear();
            }
        }
    }
    return 0;
}