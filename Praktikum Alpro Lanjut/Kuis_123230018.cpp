#include <iostream>
using namespace std;

struct Data{
    int id;
    string nama, tujuan, jenis;
};
    int jumlahPesanan;
    Data dataPesanan[100];

void inputdata(){

    cout << "Masukkan jumlah penumpang yang akan ditambahkan: ";
    cin >> jumlahPesanan;

    for (int i = 0; i < jumlahPesanan; i++){

    cout << "-----Input Data Penumpang-----\n";
        dataPesanan[i].id = i;
        cout << "Id Penumpang : ";
        cin >> dataPesanan[i].id;
	    cout << "Nama Penumpang : ";
	    cin>>dataPesanan[i].nama;
	    cout << "Tujuan Perjalanan : ";
        cin>>dataPesanan[i].tujuan;
        cout << "Jenis Perjalanan (Gold, Silver, Bronze) : ";
        cin>>dataPesanan[i].jenis;
    }
}
void lihatdata(){
    cout << "Data Penumpang:" << endl;
    cout << "ID\tNama" << endl;
    for (int i = 0; i < jumlahPesanan; ++i) {
    cout << dataPesanan[i].id << "\t" << dataPesanan[i].nama << endl;
    } 
}
void caridata(){
 int idCari;
    cout << "Masukkan ID penumpang yang ingin dicari: ";
    cin >> idCari;
    
    bool ditemukan = false;
    for (int i = 0; i < jumlahPesanan; ++i) {
        if (dataPesanan[i].id == idCari) {
            cout << "Data Penumpang:" << endl;
            cout << "ID: " << dataPesanan[i].id<< endl;
            cout << "Nama: " << dataPesanan[i].nama<< endl;
            cout << "Umur: " << dataPesanan[i].tujuan<< endl;
            cout << "Penyakit: " << dataPesanan[i].jenis<< endl;
            ditemukan = true;
            break;
        }
    }
    
    if (!ditemukan) {
        cout << "Data penumpang dengan ID " << idCari << " tidak ditemukan." << endl;
    }
}

int main(){
    
    int pilih_1;
    string ulang;

    do{
        cout << "MENU : " << endl;
        cout << "+=======================================================+" << endl;
        cout << "|                  MENU TIKET PESANAN                   |" << endl;
        cout << "|=======================================================|" << endl;
        cout << "| 1. Input Data Perjalanan                              |" << endl;
        cout << "| 2. Lhat Data Perjalanan                               |" << endl;
        cout << "| 3. Cari Data Perjalanan                               |" << endl;
        cout << "| 4. Exit                                               |" << endl;
        cout << "+=======================================================+" << endl;
        cout << "Pilih Menu : ";
        cin >> pilih_1;
    if (pilih_1 == 1){
		inputdata ();
        cout << "=========================================================" << endl;
		}
    if (pilih_1 == 2){
        lihatdata ();
        cout << "=========================================================" << endl;
    }
    if (pilih_1 == 3){
        caridata ();
        cout << "=========================================================" << endl;
    }
    if (pilih_1 == 4){

        cout <<"|   TERIMAKASIH ATAS KUNJUNGAN ANDA\t|\n";
        cout <<"| Semoga Perjalanan Anda Menyenangkan\t|\n";
        cout << "=========================================================" << endl;
    }
    cout<<"Mau Ulangi Lagi? (Y/N) ";
	cin>>ulang;}
	while(ulang == "y" || ulang == "Y");

}