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

    cout << "hasil konversi" << endl;
    cout << endl;

    cout << fixed << setprecision(2);

    cout << "Nilai IDR: " << jumlah_rupiah << " Rupiah" << endl;
    cout << "Nilai KOnversi: " << hasil_konversi << " " << nama_matauang << endl;

}

//FUngsi pengolahan data nilai siswa
void pengolahanDataSiswa() { 
    double total = 0;
    int i = 0
    const int KRITERIA_LULUS = 75;

        string namasiswa;
    int jumlah;
    const int MAX = 100;

    string nama_pelajaran[MAX];
    double nilai[MAX];

    cout << "Masukan nama siswa: ";
    getline(cin, namasiswa);

    cout << "Masukan jumlah pelajaran: ";
    cin >> jumlah;

    // loop 
    while (i < jumlah){
        cout << "Masukan nama pelajaran ke-" << (i + 1) << ": ";
        cin >> nama_pelajaran[i];

        cout << "Masukan nilai pelajaran ";
        cin >> nilai[i];

        total += nilai[i];
        i++;
    }

    // hitung rata rata
    double rata = total / jumlah;

    // Keputusan 
    string status;
    if (rata >= KRITERIA_LULUS) {
        status = "LULUS";
    } else {
        status = "TIDAK LULUS";
    }

    // Output hasil
    cout << fixed << setprecision(2);
    cout << "\n====================================\n";
    cout << "Nama Siswa        : " << namasiswa << endl;
    cout << "Rata-rata Nilai   : " << rata << endl;
    cout << "Status Kelulusan  : " << status << endl;
    cout << "====================================\n";

    return; 

}



int main() {
    int pilihan_menu;
    
    do {
        cout << "|==============================|" << endl;
        cout << "1. Konverter Mata Uang Rupiah" << endl;
        cout << "2. Pengolahan Data Sederhana" << endl;
        cout << "3. Keluar" << endl;
        cout << "|==============================|" << endl;
        cout << "Pilihan menu 1 sampai 3" << endl;
        cin >> pilihan_menu;


        switch (pilihan_menu) {
            case 1:
                konverterMataUang();
                break;

            case 2:
                pengolahanDataSiswa();
                break;

            case 3:
                cout << "Keluar dari program." << endl;
                break;

        default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan_menu != 3);
    return 0;
}
