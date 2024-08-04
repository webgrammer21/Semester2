#include <iostream>
using namespace std;

int main(){
    int *a, *b, *f, **c, d, e[2]= {1,2};
    f = (int *)malloc(sizeof(int));
    cout << "dua digit nim terakhir anda = "; cin>>d;
    d = d%10; b=e; c=&a; a=b; *f=d;
    cout << d << " " << e[0] << " " << e[1] << " " << *a << " " << *b << " " << **c << " " << endl;
    a=&e[1]; **c=d-*a+*f; a=&d; *a=*(b+1)-e[1]; c=&f;
    cout << d << " " << e[0] << " " << e[1] << " " << *a << " " << *b << " " << **c << " " << endl;  
}

