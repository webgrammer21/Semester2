#include<iostream>
using namespace std;

int deret(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    else if (n == 5){
        return deret(n-1) + (2*deret(n-2));
        // deret(4) + 2* deret(3)
        // deret(3) + deret(2) + deret(1) + 2* (deret(2) + deret(1) + deret(0))
        // (deret(2) + deret(1) + deret(0) + 2 + 1 + 2* (2 + 1+ 0)
        // (2 + 1 + 0 ) + 3 + 2*(3)
        // 3 + 3 + 6 = 12
    }
    else{
        return (deret(n-1) + deret(n-2)) + deret(n-3); 
                // deret(2) + deret(1) + deret(0)
                // 2 + 1 + 0 = 3
    }
}

int main(){
    int n;
    cout << "Masukkan nilai n :";
    cin >> n; //n = 3
    cout << deret(n);
}


//1, 5, 7, 9
//n1 =1
//n2 =5
//n3 =7
//n4 =9
//int deret(int n){ //n = 3
  //  if(n == 1){
   //     return 1;
    //}
    //else{
      //  return deret(n-1) + 2;
        //deret(2) + 2
        //deret(1) + 2 + 2
        //1 + 2 + 2 =5
    //}
//}