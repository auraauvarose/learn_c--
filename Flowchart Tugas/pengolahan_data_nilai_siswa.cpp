/*
TUGAS untuk minggu depan :
1. Buat Judul Aplikasi (contoh : "aplikasi Pengolahan data nilai siswa")
2. Buat deskripsi Aplikasi (contoh : "a. Masukkan nama siswa , b. Masukkan jumlah pelajaran , c. Masukkan nama pelajaran dan nilai (diulang sebanyak jumlah pelajaran yang diinputkan), d. hitung rata-rata nilai, e. tampilkan nama siswa, rata-rata nilai, dan kesimpulan lulus atau tidak, f. selesai)
3. Buatkan Flowchart untuk deskripsi tersebut

tugas boleh di tulis tangan atau di ketik 
minggu depan di konsultasikan
*/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    // deklarasi variabel
    double total = 0;
    int i = 0;
    const int KRITERIA_LULUS = 75;

    // variabel input
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

    return 0; 

}



