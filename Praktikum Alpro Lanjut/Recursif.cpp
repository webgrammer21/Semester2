#include <iostream>
using namespace std;

/*int faktorial(int n){
	if (n==1){
		return 1;
	}
	else {
		return n* faktorial(n-1);
	}
}
//int rekursif(int n){
//	if (n>0)
//	{
//		cout << n;
//		return rekursif(n-1);
//	}
//}

int main()
{
	int n;
	cout << "masukkan sembarang angka: "; cin >>n;
	cout << "hasil sembarang angka: "<<faktorial(n);
	
	
	return 0;
}*/

/*int main(){
    int limitinput;
    cout << "Deret mau sampai berapa : "; cin >> limitinput;

    int f1, f2;
    cout << "f1 = ";
    cin >> f1;
    cout << "f2 = ";
    cin >> f2;

    cout << f1 << endl;
    cout << f2 << endl;
    
    int fn;

    for (int i = 3; i<= limitinput; i++){

        fn=f1+f2;
        cout << fn << endl;
        f1 = f2;
        f2 = fn;
    }
}*/

int fibonacci (int n){
    if(n==0 || n==1){
        return n;
    }else{
        return (fibonacci(n-1)+fibonacci(n-2));
    }
}

int main(){
    int n, i, j = 0;
    cout << "Batas deret = ";
    cin >> n;

    cout << "Deret Fibonacci = \n";
    for(i=1; i <= n; i++){
        cout << "f_" << i << "=";
        cout << fibonacci(j) << endl;
        j++; 
    }
    return 0;
}