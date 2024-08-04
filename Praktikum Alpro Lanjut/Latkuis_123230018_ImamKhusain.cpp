#include <iostream>
using namespace std;

struct Pasien{
    int id;
    string nama;
    int umur;
    string penyakit;
};
    int jumlahPasien;
    Pasien pasienbaru[10];

void inputdataPasien(){

    cout << "Masukkan jumlah pasien yang akan ditambahkan: ";
    cin >> jumlahPasien;

    for (int i = 0; i < jumlahPasien; i++){

        cout << "Input Data Pasien" << endl;
        pasienbaru[i].id = i;
        cout << "Id Pasien : ";
        cin >> pasienbaru[i].id;
	    cout << "Nama Pasien : ";
	    cin>>pasienbaru[i].nama;
	    cout << "Penyakit Pasien : ";
        cin>>pasienbaru[i].penyakit;
        cout << "Umur Pasien : ";
        cin>>pasienbaru[i].umur;
    }
}
void lihatdataPasien(){
    cout << "Data Pasien:" << endl;
    cout << "ID\tNama" << endl;
    for (int i = 0; i < jumlahPasien; ++i) {
    cout << pasienbaru[i].id << "\t" << pasienbaru[i].nama << endl;
    } 
}
void caridataPasien(){
 int idCari;
    cout << "Masukkan ID pasien yang ingin dicari: ";
    cin >> idCari;
    
    bool ditemukan = false;
    for (int i = 0; i < jumlahPasien; ++i) {
        if (pasienbaru[i].id == idCari) {
            cout << "Data Pasien:" << endl;
            cout << "ID: " << pasienbaru[i].id<< endl;
            cout << "Nama: " << pasienbaru[i].nama<< endl;
            cout << "Umur: " << pasienbaru[i].umur<< endl;
            cout << "Penyakit: " << pasienbaru[i].penyakit<< endl;
            ditemukan = true;
            break;
        }
    }
    
    if (!ditemukan) {
        cout << "Data pasien dengan ID " << idCari << " tidak ditemukan." << endl;
    }
}

int main(){
    
    int pilih_1;
    string ulang;

    do{
        cout << "MENU : " << endl;
        cout << "+=======================================================+" << endl;
        cout << "|                  MENU RUMAH SAKIT                     |" << endl;
        cout << "|=======================================================|" << endl;
        cout << "| 1. Input Data Pasien                                  |" << endl;
        cout << "| 2. Lhat Data Pasien                                   |" << endl;
        cout << "| 3. Cari Data Pasien                                   |" << endl;
        cout << "| 4. Exit                                               |" << endl;
        cout << "+=======================================================+" << endl;
        cout << "Pilih Menu : ";
        cin >> pilih_1;
    if (pilih_1 == 1){
		inputdataPasien ();
        cout << "=========================================================" << endl;
		}
    if (pilih_1 == 2){
        lihatdataPasien ();
        cout << "=========================================================" << endl;
    }
    if (pilih_1 == 3){
        caridataPasien ();
        cout << "=========================================================" << endl;
    }
    if (pilih_1 == 4){

        cout<<"SEMANGAT BERJUANG KAWAN!!!" << endl;
        cout << "=========================================================" << endl;
    }
    cout<<"Mau Ulangi Lagi? (Y/N) ";
	cin>>ulang;}
	while(ulang == "y" || ulang == "Y");

}