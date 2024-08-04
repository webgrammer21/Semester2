#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream myfile ("teks.txt");
    string line;

    if (myfile.is_open()){
        while (getline(myfile, line)){
            cout << line << endl;
        }
        myfile.close(); // close
    }
    else {
        cout << "File not found";
    }
}