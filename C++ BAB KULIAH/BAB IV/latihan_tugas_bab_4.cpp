#include <iostream>
#include <string>

using namespace std;

int main() {
    // --- Deklarasi Variabel ---
    string nama;
    string status_juara;
    double nilai1, nilai2, rata_rata;

    // --- Layar Masukkan ---
    cout << "PROGRAM HITUNG NILAI RATA-RATA" << endl;
    cout << "-----------------------------" << endl;

    // Menggunakan getline untuk membaca nama yang mungkin mengandung spasi
    cout << "Nama Peserta : ";
    getline(cin, nama);

    cout << "Nilai I : ";
    cin >> nilai1;

    cout << "Nilai II : ";
    cin >> nilai2;

    // --- Proses Perhitungan dan Penentuan Juara ---
    // Menghitung nilai rata-rata
    rata_rata = (nilai1 + nilai2) / 2;

    // Menentukan status juara berdasarkan nilai rata-rata
    if (rata_rata > 80) {
        status_juara = "Juara Umum";
    } else if (rata_rata > 75) {
        status_juara = "Juara Kelas";
    } else if (rata_rata > 65) {
        status_juara = "Juara Harapan";
    } else {
        status_juara = "tidak juara";
    }

    // --- Layar Keluaran ---
    cout << "\n--- Hasil ---" << endl;
    cout << "Siswa yang bernama " << nama 
         << " memperoleh nilai rata-rata " << rata_rata 
         << " dan menjadi " << status_juara 
         << " dari hasil pertandingan yang diikutinya." << endl;

    return 0;
}

