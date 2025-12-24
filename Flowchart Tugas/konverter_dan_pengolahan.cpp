#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



// Fungsi untuk konverter mata uang
void konverterMataUang() {
    const double Tukar_USD = 16604.0;
    const double Tukar_EUR = 19303.0;
    const double Tukar_JPY = 106.0;


    double jumlah_rupiah;
    char pilihan;
    double hasil_konversi = 0.0;
    string nama_matauang;

    cout <<"Masukan jumlah uang rupiah: ";
    cin >> jumlah_rupiah;

    cout << "|===========================|" << endl;
    cout << "|PILIHAN PENUKARAN MATA UANG|" << endl;
    cout << "|1. Dolar Amerika (USD)     |" << endl;
    cout << "|2. Euro (EUR)              |" << endl;
    cout << "|3. Yen Jepang (JPY)        |" << endl;
    cout << "|===========================|" << endl;
    cin >> pilihan;
    cout << endl;

    pilihan = tolower(pilihan);

    if (pilihan == '1') {
        hasil_konversi = jumlah_rupiah / Tukar_USD;
        nama_matauang = "Dolar Amerika (USD)";
    } else if (pilihan == '2') {
        hasil_konversi = jumlah_rupiah / Tukar_EUR;
        nama_matauang = "Euro (EUR)";
    } else if (pilihan == '3') {
        hasil_konversi = jumlah_rupiah / Tukar_JPY;
        nama_matauang = "Yen Jepang (JPY)";
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return;
    }




}


int main() {
    int pilihan_menu;
    
    do {
        cout << "|==============================|" << endl;
        cout << "1. Konverter Mata Uang Rupiah" << endl;
        cout << "2. Pengolahan Data Sederhana" << endl;
        cout << "3. Keluar" << endl;
        cout << "|==============================|" << endl;

        switch (pilihan_menu) {
            
        }
    }
} 
