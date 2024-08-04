#include <iostream>
using namespace std;

int main() {
    int i = 10;
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    int awal, tengah, akhir, nilaicari;
    bool found;

    //cari data
    cout << "Cari nomor berapa : ";
    cin >> nilaicari;

    found = false;
    awal = 0;
    akhir = i-1;

    //binary search
    while ((!found) && (awal <= akhir)){
        tengah = (awal + akhir) / 2;
        if (nilaicari = x[tengah]){
            found = true;
        } else {
            if (nilaicari < x[tengah])
            akhir = tengah - 1;
            else
            awal = tengah + 1;
        }
    }

    if (found)
        cout << "Nilai " << nilaicari << " ditemukan di array ke-" << tengah << endl;
    else 
        cout << "Nilai " << nilaicari << " tidak ditemukan dalan array" << endl;
    return 0;
}