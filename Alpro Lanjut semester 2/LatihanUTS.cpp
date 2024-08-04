#include <iostream>
using namespace std;

/// jawaban soal uts no. 1
struct buku{
    int kode, tgl_pinjam, tgl_kembali, denda;
    string judul, terlambat, transaksi;
};

struct mhs{
    string nama, kelas, status;
    int kodeAnggota, no_telpon;
    buku bukupinjam[3];
};

/// jawaban soal uts no. 2
mhs mahasiswa[3];

int main(){

    int total = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            total = total + mahasiswa[i].bukupinjam[j].denda;
        }

        if (total >= 500000){
            cout << "Nama\t: " << mahasiswa[i].nama << endl;
            cout << "Kode\t: " << mahasiswa[i].kodeAnggota << endl;
            cout << "Kelas\t: " << mahasiswa[i].kelas << endl;
        }
    
    total = 0;
    }
}