#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

struct DataPenduduk {
    string NIK;
    string nama;
    string jenisKelamin;
    string tanggalLahir;
};

DataPenduduk data[100];
int jumlahData = 0;

void input() {
    cout << "+===========================================================+\n";
    cout << "|                    INPUT DATA KEPENDUDUKAN                |\n";
    cout << "+===========================================================+\n";
    ofstream file("penduduk.txt", ios::app);
    if (file.is_open()) {
        int jumlahTambah;
        cout << "Masukkan jumlah data penduduk yang ingin ditambahkan: ";
        cin >> jumlahTambah;
        cin.ignore();

        for (int i = 0; i < jumlahTambah; i++) {
            DataPenduduk dapen;

            cout << "\nMasukkan data penjualan baru ke-" << i + 1 << ":" << endl;
            cout << "Masukkan nomor NIK\t\t: ";
            getline(cin, dapen.NIK);            
            cout << "Masukkan Nama KTP\t\t: ";
            getline(cin, dapen.nama);
            cout << "Jenis Kelamin (L/P)\t\t: ";
            cin >> dapen.jenisKelamin;
            cout << "Tanggal Lahir (YYYY-MM-DD)\t: ";
            cin >> dapen.tanggalLahir;

            data[jumlahData++] = dapen;

            file << dapen.NIK << " " << dapen.nama << " " << dapen.jenisKelamin << " " << dapen.tanggalLahir << endl;

            cin.ignore(); 
        }

        file.close();

        cout << "\nData Penduduk berhasil ditambahkan." << endl;
    } else {
        cout << "File penduduk.txt tidak dapat dibuka." << endl;
    }
}

void openDataPenduduk() {
    ifstream file("penduduk.txt");
    if (file.is_open()) {
        int count = 0;
        while (file >> data[count].NIK >> data[count].nama >> data[count].jenisKelamin >> data[count].tanggalLahir) {
            count++;
        }
        file.close();

        sort(data, data + count, [](const DataPenduduk &a, const DataPenduduk &b) {
            return a.NIK < b.NIK;
        });

        cout << "Data Penduduk:" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << setw(16) << left << "Nomor NIK" << " | " << setw(10) << left << "Nama" << " | " << setw(10) << left << "Jenis Kelamin" << " | " << setw(10) << left << "Tanggal Lahir" << endl;
        cout << "-------------------------------------------------------------" << endl;

        for (int i = 0; i < count; i++) {
            cout << setw(15) << left << data[i].NIK << " | " << setw(10) << left << data[i].nama << " | " << setw(13) << left << data[i].jenisKelamin << " | " << setw(10) << left << data[i].tanggalLahir << endl;
        }
        cout << "-------------------------------------------------------------" << endl;
    } else {
        cout << "File penduduk.txt tidak dapat dibuka." << endl;
    }
}

void searchDataPenduduk() {
    cout << "Masukkan Tanggal Lahir yang ingin dicari (YYYY-MM-DD): ";
    string tanggalLahirCari;
    cin >> tanggalLahirCari;

    ifstream file("penduduk.txt");
    if (file.is_open()) {
        bool found = false;
        DataPenduduk temp;
        while (file >> temp.NIK >> temp.nama >> temp.jenisKelamin >> temp.tanggalLahir) {
            if (temp.tanggalLahir == tanggalLahirCari) {
                cout << "-------------------------------------------------------------" << endl;
                cout << "|                   DATA DITEMUKAN BRO!                     |" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "Nomor NIK: " << temp.NIK << endl;
                cout << "Nama: " << temp.nama << endl;
                cout << "Jenis Kelamin: " << temp.jenisKelamin << endl;
                cout << "Tanggal Lahir: " << temp.tanggalLahir << endl;
                found = true;
            }
        }
        file.close();

        if (!found) {
            cout << "Data dengan Tanggal Lahir " << tanggalLahirCari << " tidak ditemukan." << endl;
        }
    } else {
        cout << "File penduduk.txt tidak dapat dibuka." << endl;
    }
}

void menuOutput() {
    int pilihan;
    do {
        cout << "+===========================================================+\n";
        cout << "|                        MENU OUTPUT                        |\n";
        cout << "+===========================================================+\n";
        cout << "| 1. Tampilkan Seluruh Data                                 |\n";
        cout << "| 2. Cari Data                                              |\n";
        cout << "| 3. Kembali ke Menu Utama                                  |\n";
        cout << "+===========================================================+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            openDataPenduduk();
            break;
        case 2:
            searchDataPenduduk();
            break;
        case 3:
            return;
        default:
            cout << "\nANDA SALAH DALAM MEMILIH KAWAN :(.\n";
        }
    } while (true);
}

int main() {
    int pilih_1;
    string ulang;
    
    do {
        cout << "MENU : " << endl;
        cout << "+=======================================================+" << endl;
        cout << "|                    PROGRAM MEMILIH                    |" << endl;
        cout << "|=======================================================|" << endl;
        cout << "| 1. Input                                              |" << endl;
        cout << "| 2. Output                                             |" << endl;
        cout << "| 3. Exit                                               |" << endl;
        cout << "+=======================================================+" << endl;
        cout << "Pilih no : ";
        cin >> pilih_1;

        if (pilih_1 == 1) {
            input();
        } else if (pilih_1 == 2) {
            menuOutput();
        } else if (pilih_1 == 3) {
            cout << "Terimakasih :)" << endl;
            break;
        }
        cout << "Mau Ulangi Lagi? (Y/N) ";
        cin >> ulang;
    } while (ulang == "y" || ulang == "Y");

    return 0;
}
