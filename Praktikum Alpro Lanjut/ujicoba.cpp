#include <iostream>
using namespace std;

int pangkat(int x, int n);

int main(){
 int x,y;
 cout << "Menghitung X pangkat Y" << endl;
 cout << "Masukan nilai X:";
 cin >> x;
 cout << "Masukan nilai Y:";
 cin >> y;
 cout << "Hasil :" << pangkat(x,y);
}

int pangkat(int x, int n){
 if(n == 1){
  return x;
 } else{
  return x * pangkat(x,n-1);
 }
}