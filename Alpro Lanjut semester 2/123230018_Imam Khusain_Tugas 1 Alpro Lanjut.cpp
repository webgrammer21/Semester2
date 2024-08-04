#include <iostream>
#include <ctime>

using namespace std;

//Deklarasi struct Anggota
struct Anggota{
	string nama;
	string alamat;
	string nomorTelepon;
	string email;
	time_t tanggalLahir;
	string statusKeanggotaan;
};

//Deklarasi struct Buku
struct Buku{
	string ISBN;
	string namaBuku;
	string penulis;
	string penerbit;
	int tahunTerbit;
	string genre;
	int jumlahEksemplar;
};

//Deklarasi struct Peminjaman
struct Peminjaman{
	time_t tanggalPeminjaman;
	time_t tanggalJatuhTempo;
	string bukuYangDipinjam;
	string statusPeminjaman;
};

int main(){
	
	return 0;
}
