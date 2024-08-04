#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct inputt {
    string jurusan;
    string jam;
    string durasi;
};

inputt data[100];
char namafile[20];
int n;
ofstream file2;
const int threshold = 10;

void input() {
    int i, n;
    cout << "INPUT DATA\n";

    cout << "Nama File = ";
    cin >> namafile;
    ofstream Arsip(namafile, ios::out);
    if (Arsip.is_open()) {
        cout << "Jumlah data = ";
        cin >> n;
        cin.ignore();  // To clear the newline character from the input buffer
        for (i = 0; i < n; i++) {
            cout << "Data ke-" << i + 1 << " = " << endl;
            cout << "Jurusan = ";
            getline(cin, data[i].jurusan);
            cout << "Jam = ";
            getline(cin, data[i].jam);  // Changed from cin >> to getline for consistency
            cout << "Durasi = ";
            getline(cin, data[i].durasi);  // Changed from cin >> to getline for consistency
            if (i == n - 1)
                Arsip << data[i].jurusan << endl << data[i].jam << endl << data[i].durasi << endl;
            else
                Arsip << data[i].jurusan << endl << data[i].jam << endl << data[i].durasi << endl;
        }
        Arsip.close();
    }
}
int convertToMinutes(const string& time) {
    // Assuming time is in HH:MM format
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

void hasil() {
    cout << "HASIL DATA\n";
    cout << "Nama File = ";
    cin >> namafile;
    ifstream Arsip(namafile);
    vector<inputt> filteredData;
    if (Arsip.is_open()) {
        int i = 0;
        while (getline(Arsip, data[i].jurusan) && getline(Arsip, data[i].jam) && getline(Arsip, data[i].durasi)) {
            int totalMinutes = convertToMinutes(data[i].jam) + stoi(data[i].durasi);
            if (totalMinutes <= threshold * 60) {
                filteredData.push_back(data[i]);
            }
            i++;
        }
        Arsip.close();
        
        ofstream newArsip(namafile, ios::out);
        if (newArsip.is_open()) {
            for (const auto& entry : filteredData) {
                newArsip << entry.jurusan << endl << entry.jam << endl << entry.durasi << endl;
            }
            newArsip.close();
        }
        
        cout << "Data after filtering:\n";
        for (const auto& entry : filteredData) {
            cout << "Jurusan: " << entry.jurusan << ", Jam: " << entry.jam << ", Durasi: " << entry.durasi << endl;
        }
    } else {
        cout << "File Not Found!\n";
    }
}

int main() {
    int pilih_1;

    do {
        cout << "MENU : " << endl;
        cout << "+=======================================================+" << endl;
        cout << "|                    PROGRAM MEMILIH                    |" << endl;
        cout << "|=======================================================|" << endl;
        cout << "| 1. Input                                              |" << endl;
        cout << "| 2. Output                                             |" << endl;
        cout << "| 3. Hasil                                              |" << endl;
        cout << "| 4. Exit                                               |" << endl;
        cout << "+=======================================================+" << endl;
        cout << "Pilih no : ";
        cin >> pilih_1;

        if (pilih_1 == 1) {
            input();
        } else if (pilih_1 == 2) {
            output();
        } else if (pilih_1 == 3) {
            hasil();
        } else if (pilih_1 == 4) {
            cout << "Terimakasih :)" << endl;
        }
    } while (pilih_1 != 4);

    return 0;
}
