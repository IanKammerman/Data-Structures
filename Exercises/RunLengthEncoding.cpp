//Run Length Encoding Exercise
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Run Length encoding function
string runLengthEncode(const string& input) {
    if (input.empty()) return ""; 

    ostringstream encoded;
    int count = 1;

    for (size_t i = 1; i <= input.size(); i++) {
        if (i == input.size() || input[i] != input[i - 1]) {
            encoded << input[i - 1] << count;
            count = 1;
        } 
        else 
        {
            count++; 
        }
    }
    return encoded.str();
    
}

//Main function asking for user input
int main() {
    cout << "Enter a string to encode: ";
    string input;
    getline(cin, input); 
    string encoded = runLengthEncode(input);
    cout << "Encoded string: " << encoded << '\n';
    double compressionRate = (double)encoded.length() / input.length();
    cout << "Compression rate: " << compressionRate << '\n';
    return 0;
}