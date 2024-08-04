#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream file;
    string a;

    cout << "Masukkan data : ";
    getline(cin,a);

    file.open("teks.txt");
    file << "isi inputan :\n" << a << " ";
}