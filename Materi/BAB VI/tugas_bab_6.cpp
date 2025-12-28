#include <iostream>
#include <string> 

using namespace std;

int main() {
    const int jumlah = 10; 
    int jumlah_mhs; 
    string nama[jumlah];
    int nilai[jumlah];

    cout << "Masukkan jumlah Mahasiswa maksimal 10: ";
    cin >> jumlah_mhs;

    if (jumlah_mhs > jumlah || jumlah_mhs <= 0) {
        cout << "Jumlah mahasiswa melebihi 10." << endl;
        return 1; 
    }

    for(int i = 0; i < jumlah_mhs; i++) {
        cout << "Masukkan Nama Mahasiswa: ";
        cin >> nama[i]; 
        cout << "Masukkan Nilai Mahasiswa: ";
        cin >> nilai[i];
    }

    cout << "hasil input data mahasiswa (" << jumlah_mhs << " Orang)";
    
    for (int i = 0; i < jumlah_mhs; i++) {
        cout << "\n------------------------\n";
        cout << "Nama Mahasiswa : " << nama[i] << endl;
        cout << "Nilai          : " << nilai[i] << endl;
    }

    return 0;
}