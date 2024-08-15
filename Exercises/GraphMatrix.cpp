//Graph Matrix Exercise
#include <iostream>
using namespace std;

//Initialize Variables
int Matrix[50][50];
char Labels[50];

//Find location of index
int FindIndex(char Label, int vertices){
    for(int i = 0; i < vertices; i++){
        if(Labels[i] == Label){
            return i;
        }
    }
    return -1;
}

//Add edge to the matrix
void AddEdge(char A, char B, int vertices){
    int indexA = FindIndex(A, vertices);
    int indexB = FindIndex(B, vertices);
    if(indexA != -1 && indexB != -1){
        Matrix[indexA][indexB] = 1;
    }
    cout << "Added Edge " << A << "->" << B << endl;
}

//Print the edges 
void PrintEdges(int v){
    bool isFirst = true;
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(Matrix[i][j] == 1){
                if(!isFirst){
                    cout << ", ";
                }
                cout << Labels[i] << Labels[j];
                isFirst = false;
            }
        }
    }
    cout << endl;
}

int main(){
    int vertices;
    //Ask for input
    cout << "How many Vertices? ";
    cin >> vertices;
    for(int i = 0; i < vertices; i++){
        cout << "What is the label for vertex " << i + 1 << "? ";
        cin >> Labels[i];
    }
    cout << "Define an edge by listing a pair of vertices, i.e. \"A B\", or -1 to stop.\n";
    while (true) {
        string inputA, inputB;
        cin >> inputA;
        if (inputA == "-1") 
            break;
        cin >> inputB;
        char vertexA = inputA[0], vertexB = inputB[0];
        AddEdge(vertexA, vertexB, vertices);
    }
    cout << "Your edges are: ";
    PrintEdges(vertices);
    return 0;
}