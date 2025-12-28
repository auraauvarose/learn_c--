#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Fungsi untuk konverter mata uang
void konverterMataUang() {
    // Disarankan menggunakan data Maybank terbaru
    const double Tukar_USD = 16785.0; 
    const double Tukar_EUR = 19568.0; 
    const double Tukar_JPY = 110.80; 

    double jumlah_rupiah;
    char pilihan;
    double hasil_konversi = 0.0;
    string nama_matauang;

    cout << "\nMasukan jumlah uang rupiah: ";
    cin >> jumlah_rupiah;

    cout << "|===========================|" << endl;
    cout << "|PILIHAN PENUKARAN MATA UANG|" << endl;
    cout << "|1. Dolar Amerika (USD)     |" << endl;
    cout << "|2. Euro (EUR)              |" << endl;
    cout << "|3. Yen Jepang (JPY)        |" << endl;
    cout << "|===========================|" << endl;
    cout << "Pilih (1-3): ";
    cin >> pilihan;

    if (pilihan == '1') {
        hasil_konversi = jumlah_rupiah / Tukar_USD;
        nama_matauang = "USD";
    } else if (pilihan == '2') {
        hasil_konversi = jumlah_rupiah / Tukar_EUR;
        nama_matauang = "EUR";
    } else if (pilihan == '3') {
        hasil_konversi = jumlah_rupiah / Tukar_JPY;
        nama_matauang = "JPY";
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\n--- HASIL KONVERSI ---" << endl;
    cout << "Nilai IDR: " << jumlah_rupiah << " Rupiah" << endl;
    cout << "Nilai Konversi: " << hasil_konversi << " " << nama_matauang << endl;
}

// Fungsi pengolahan data nilai siswa
void pengolahanDataSiswa() { 
    double total = 0;
    int i = 0; // PERBAIKAN 1: Tambahkan titik koma (;)
    const int KRITERIA_LULUS = 75;

    string namasiswa;
    int jumlah;
    const int MAX = 100;

    string nama_pelajaran[MAX];
    double nilai[MAX];

    cin.ignore(); // PERBAIKAN 2: Membersihkan buffer Enter dari menu utama
    cout << "\nMasukan nama siswa: ";
    getline(cin, namasiswa);

    cout << "Masukan jumlah pelajaran: ";
    cin >> jumlah;

    while (i < jumlah){
        cout << "Masukan nama pelajaran ke-" << (i + 1) << ": ";
        cin >> nama_pelajaran[i];

        cout << "Masukan nilai pelajaran: ";
        cin >> nilai[i];

        total += nilai[i];
        i++;
    }

    double rata = total / jumlah;
    string status = (rata >= KRITERIA_LULUS) ? "LULUS" : "TIDAK LULUS";

    cout << fixed << setprecision(2);
    cout << "\n====================================\n";
    cout << "Nama Siswa        : " << namasiswa << endl;
    cout << "Rata-rata Nilai   : " << rata << endl;
    cout << "Status Kelulusan  : " << status << endl;
    cout << "====================================\n";
}


void keluarprogram() {
    cout << "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
}

int main() {
    int pilihan_menu;
    
    do {
        cout << "\n|==============================|" << endl;
        cout << "|      MENU UTAMA PROGRAM      |" << endl;
        cout << "|1. Konverter Mata Uang Rupiah |" << endl;
        cout << "|2. Pengolahan Data Sederhana  |" << endl;
        cout << "|3. Keluar                     |" << endl;
        cout << "|==============================|" << endl;
        cout << "Pilihan menu (1-3): ";
        cin >> pilihan_menu;

        switch (pilihan_menu) {
            case 1:
                konverterMataUang();
                break;
            case 2:
                pengolahanDataSiswa();
                break;
            case 3:
                keluarprogram();
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan_menu != 3); // PERBAIKAN 3: Loop berjalan selama pilihan bukan 3

    return 0;
}