#include <iostream>
#define maks 100

using namespace std;

typedef struct {
    string nama;
    int pesanan[maks], totalPesanan,jumlah[maks],noAntrean;
} pelanggan;

void menu(char *pilih, pelanggan data[maks], int &banyakPelanggan,int &pencarian);
void menuMakanan();
void inputPelanggan(pelanggan data[maks], int &banyakPelanggan);
void tampil(pelanggan data[maks], int &banyakPelanggan);
void nota(pelanggan data[maks], int &banyakPelanggan,int &pencarian);

int main() {
    pelanggan data[maks];
    int banyakPelanggan = 0,pencarian; 
    char pil, pilih;
    do {
        system("cls");
        menu(&pilih,data,banyakPelanggan,pencarian);
        cout << "\nApakah Anda ingin menggunakan program ini lagi (y/n): ";
        cin >> pil;
    } while (pil == 'y' || pil == 'Y');
    cout << "\nTerima kasih telah menggunakan Program ini.\n";

    return 0;
}

void menu(char *pilih, pelanggan data[maks],int &banyakPelanggan,int &pencarian) {
    system("cls");
    cout << "=============================================\n";
    cout << "|            Warung Makan Sentosa           |\n";
    cout << "=============================================\n";
    cout << "| 1. Menu Makanan                           |\n";
    cout << "| 2. input Data Pelanggan                   |\n";
    cout << "| 3. Tampil Pelanggan                       |\n";
    cout << "| 4. Nota Pelanggan                         |\n";
    cout << "| 5. Exit                                   |\n";
    cout << "=============================================\n";
    cout << "Pilihan : ";
    cin >> *pilih;
    switch (*pilih) {
        case '1':
            menuMakanan();
            break;
        case '2':
            inputPelanggan(data,banyakPelanggan);
            break;
        case '3':
            tampil(data,banyakPelanggan);
            break;
        case '4':
            nota(data,banyakPelanggan,pencarian);
            break;
        case '5':
            system("cls");
            exit(0);
        default:
            cout << "Input tidak valid.\n";
    }
}
void menuMakanan() {
    system("cls");
    cout << "=============================================\n";
    cout << "| No. |     Menu           |       Harga    |\n";
    cout << "=============================================\n";
    cout << "| 1.  | Nasi Goreng        | Rp15.000       |\n";
    cout << "| 2.  | Magelangan         | Rp20.000       |\n";
    cout << "| 3.  | Bakmie Goreng      | Rp18.000       |\n";
    cout << "| 4.  | Bakmie Ghodog      | Rp18.000       |\n";
    cout << "| 5.  | Nasi Ghodog        | Rp15.000       |\n";
    cout << "| 6.  | Mie Lethek         | Rp25.000       |\n";
    cout << "=============================================\n";
}
void inputPelanggan(pelanggan data[maks],int &banyakPelanggan) {
    system("cls");
    cout << "=============================================\n";
    cout << "|            Input Data Pelanggan           |\n";
    cout << "=============================================\n\n";
    cout << "Banyak Pelanggan yang di input (1-1000): ";
    cin >> banyakPelanggan;
    if (banyakPelanggan < 1 || banyakPelanggan > 1000) {
        cout << "Input tidak valid\n";
        return;
    } else {
        cout << endl;
        for (int i = 0; i < banyakPelanggan; i++) {
            cout << "Nomor Antrean ke-" << i + 1 << endl;
            data[i].noAntrean = i+1;
            cout << "Nama Pelanggan\t\t: ";
            cin.ignore();
            getline(cin, data[i].nama);
            cout << "Menu:\n 1. Nasi Goreng\n 2. Magelangan\n 3. Bakmie Goreng\n 4. Bakmie Ghodog\n 5. Nasi Ghodog\n 6. Mie Lethek\n";
            cout << "Jumlah pesanan\t\t: ";
            cin >> data[i].totalPesanan;
            for (int j = 0; j < data[i].totalPesanan; j++) {
                cout << "pilih nomor menu\t: ";
                cin >> data[i].pesanan[j];
                if (data[i].pesanan[j] < 1 || data[i].pesanan[j] > 6) {
                    cout << "Input tidak valid. Mohon ulangi program Anda.\n";
                    return;
                }
                cout << "Jumlah pesanan menu " << data[i].pesanan[j] << "\t: ";
                cin >> data[i].jumlah[j];
            }
            cout << endl;
        }
    }
}
void tampil(pelanggan data[maks], int &banyakPelanggan){
	system("cls");
    cout << "=============================================\n";
    cout << "|           Tampil Data Pelanggan           |\n";
    cout << "=============================================\n\n";
    if (banyakPelanggan == 0) {
		cout << "Anda belum menginputkan data.\n";
		return;
	}else {
		for (int i = 0; i < banyakPelanggan; i++) {
            cout << "Nomor Antrean ke-" << i + 1 << endl;
            cout << "Nama Pelanggan\t\t: " << data[i].nama << endl;
            cout << "Jumlah pesanan\t\t: " << data[i].totalPesanan << endl;
            for (int j = 0; j < data[i].totalPesanan; j++) {
                cout << "Jumlah pesanan menu " << data[i].pesanan[j] << "\t: " << data[i].jumlah[j] << endl;
            }
            cout << endl;
        }
	}
}
void nota(pelanggan data[maks], int &banyakPelanggan, int &pencarian) {
    system("cls");
    cout << "=============================================\n";
    cout << "|               Nota Pelanggan              |\n";
    cout << "=============================================\n\n";
    if (banyakPelanggan == 0) {
        cout << "Anda belum menginputkan data.\n";
        return;
    } else {
        bool found = false;
        cout << "Masukkan noAntrean Pelanggan : ";
		cin >> pencarian;
		cout << endl;	
        for (int i = 0; i < banyakPelanggan; i++) {
            if (data[i].noAntrean == pencarian) {
                found = true;
                cout << "=============================================\n";
                cout << "             --Nota Pelanggan--             \n";
                cout << "Nomor Antrean ke-" << i + 1 << endl;
                cout << "Nama Pelanggan\t\t: " << data[i].nama << endl;
                cout << "Pesanan:\n";
                for (int j = 0; j < data[i].totalPesanan; j++) {
                    cout << "  - ";
                    switch (data[i].pesanan[j]) {
                        case 1:
                            cout << "Nasi Goreng";
                            break;
                        case 2:
                            cout << "Magelangan";
                            break;
                        case 3:
                            cout << "Bakmie Goreng";
                            break;
                        case 4:
                            cout << "Bakmie Ghodog";
                            break;
                        case 5:
                            cout << "Nasi Ghodog";
                            break;
                        case 6:
                            cout << "Mie Lethek";
                            break;
                        default:
                            cout << "Menu tidak valid";
                            break;
                    }
                    if (data[i].pesanan[j] == 3 || data[i].pesanan[j] == 4) {
                        cout << "\t: " << data[i].jumlah[j] << endl;
                    } else {
                        cout << "\t\t: " << data[i].jumlah[j] << endl;
                    }
                }
                int totalHarga = 0;
                for (int j = 0; j < data[i].totalPesanan; j++) {
                    int harga = 0;
                    switch (data[i].pesanan[j]) {
                        case 1:{
                            harga = 15000;
                            cout << "Harga Nasi Goreng\t: Rp" << harga * data[i].jumlah[j] << endl;
                            break;
                        }case 2:{
                            harga = 20000;
                            cout << "Harga Magelangan\t: Rp" << harga * data[i].jumlah[j] << endl;
                            break;
                        }case 3:{
							harga = 18000;
                            cout << "Harga Bakmie Goreng\t: Rp" << harga * data[i].jumlah[j] << endl;
                            break;
                        }case 4:{
                            harga = 18000;
                            cout << "Harga Bakmie Ghodog\t: Rp" << harga * data[i].jumlah[j] << endl;
                            break;
                        }case 5:{
                            harga = 15000;
                            cout << "Harga Nasi Ghodog\t: Rp" << harga * data[i].jumlah[j] << endl;
                            break;
                        }case 6:{
                            harga = 25000;
                            cout << "Harga Mie Lethek\t: Rp" << harga * data[i].jumlah[j] << endl;
                            break;
                        }default:{
                            harga = 0;
                            break;
                        }
                    }
                    totalHarga += harga * data[i].jumlah[j];
                }
                cout << "Total Harga\t\t: Rp" << totalHarga << endl;
                cout << "=============================================\n";
                cout << endl;
                break; 
            }
        }
        if (!found) {
            cout << "Nomor Antrean tidak ditemukan.\n";
        }
    }
}
