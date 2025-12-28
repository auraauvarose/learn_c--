#include <iostream>

using namespace std;

// Program untuk mengalikan dua buah matriks
// ADINDA SABRINA SULI (SOULED)

int main() {
    // Deklarasi variabel untuk matriks dan ukurannya
    // static agar variabel diinisialisasi dengan nilai 0
    static int x[11][11], y[11][11], kali[11][11];
    int r1, c1, r2, c2, i, j, k;

    // 1. Meminta input ukuran untuk matriks pertama
    cout << "Masukkan baris dan kolom untuk matriks pertama: ";
    cin >> r1 >> c1;

    // 2. Meminta input ukuran untuk matriks kedua
    cout << "Masukkan baris dan kolom untuk matriks kedua: ";
    cin >> r2 >> c2;

    // 3. Validasi: Syarat perkalian matriks adalah jumlah kolom matriks pertama
    //    harus sama dengan jumlah baris matriks kedua.
    while (c1 != r2) {
        cout << "\nError! Kolom matriks pertama tidak sama dengan baris matriks kedua.\n";
        cout << "Silakan masukkan ulang ukuran matriks.\n\n";

        cout << "Masukkan baris dan kolom matriks pertama: ";
        cin >> r1 >> c1;
        cout << "Masukkan baris dan kolom matriks kedua: ";
        cin >> r2 >> c2;
    }

    // 4. Mengisi elemen matriks pertama
    cout << "\nMasukkan elemen matriks 1:" << endl;
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c1; ++j) {
            cout << "Masukkan elemen x" << i + 1 << j + 1 << ": ";
            cin >> x[i][j];
        }
    }

    // 5. Mengisi elemen matriks kedua
    cout << "\nMasukkan elemen matriks 2:" << endl;
    for (i = 0; i < r2; ++i) {
        for (j = 0; j < c2; ++j) {
            cout << "Masukkan elemen y" << i + 1 << j + 1 << ": ";
            cin >> y[i][j];
        }
    }

    // 6. Melakukan perkalian matriks
    // Hasil perkalian akan memiliki ukuran baris matriks pertama (r1)
    // dan kolom matriks kedua (c2).
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            // Inisialisasi elemen matriks hasil dengan 0 sebelum dihitung
            kali[i][j] = 0;
            for (k = 0; k < c1; ++k) {
                kali[i][j] += x[i][k] * y[k][j];
            }
        }
    }

    // 7. Menampilkan hasil perkalian matriks
    cout << "\nOutput Matrix (Hasil Perkalian):" << endl;
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            cout << " " << kali[i][j];
            if (j == c2 - 1) {
                cout << endl; // Pindah baris setelah satu baris matriks selesai dicetak
            }
        }
    }

    return 0;
}