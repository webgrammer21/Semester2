/*#include <iostream>
using namespace std;

int main(){
	
	    int matrix [3][2][2] = {{1,2,3,4},{5,6,7,8},{10,11,12,13}};
	    
	    for (short i = 0; i<3; i++){
			for (short j = 0; j<2; j++){
				for (short k = 0; k<2; k++){
					cout << " | " << matrix [i] [j] [k] << " ";
				}
				cout << " | " << endl;
			}
		}
    return 0;
}*/

#include <iostream>
using namespace std;

typedef struct{
	int tgl, bulan, tahun;
	}info;

typedef struct{
	int nim;
	string nama;
	info kelahiran;
	}data;

int main(){

	data mhs[99];
	for (short i = 0; i<2; i++)
	{
		cout << i+1 << endl;
		cout << "Nama : "; cin >> mhs[i].nama;
		cout << "NIM : "; cin >> mhs[i].nim;
		cout << "Tanggal Lahir : "; cin >> mhs[i].tgl;
		cout << "bulan Lahir : "; cin >> mhs[i].bulan;
		cout << "tahun lahir : "; cin >> mhs[i].tahun;
	}

	/*mhs[0].nim = 123;
	mhs[0].nama = "Agus";
	mhs[0].kelahiran.tgl = 18;
	mhs[0].kelahiran.bulan = 03;
	mhs[0].kelahiran.tahun = 1987;

	mhs[1].nim = 125;
	mhs[1].nama = "Yanto";
	mhs[1].kelahiran.tgl = 05;
	mhs[1].kelahiran.bulan = 03;
	mhs[1].kelahiran.tahun = 1969;	

	cout << mhs[0].nama << endl;
	cout << mhs[0].nim << endl;
	cout << mhs[0].kelahiran.tgl << endl;
	cout << mhs[0].kelahiran.bulan << endl;
	cout << mhs[0].kelahiran.tahun << endl;

	cout << mhs[1].nama << endl;
	cout << mhs[1].nim << endl;
	cout << mhs[1].kelahiran.tgl << endl;
	cout << mhs[1].kelahiran.bulan << endl;
	cout << mhs[1].kelahiran.tahun << endl;*/



	return 0;
}