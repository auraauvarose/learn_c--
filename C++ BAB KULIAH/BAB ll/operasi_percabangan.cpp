#include <iostream>

// if (jika)
void contoh_if() {
    int umur = 20;

    if (umur >= 17) {
        std::cout << " Anda susah dewasa " << std::endl;
    }

    std::cout << " Program selesai " << std::endl;
}


// if ... else (jika ... jika tidak)
void dua_kondisi() {
    int nilai = 23;

    if (nilai >= 60) {
        std::cout << " Selamat, Anda Lulus " << std::endl;
    } else {
        std::cout << " Maaf, Anda Tidak Lulus " << std::endl;
    }
}

// pernyataan if lebih dari dua kondisi
void lebih_dari_dua_kondisi() {
    int nilai = 85;

    if (nilai >= 80) {
        std::cout << " Selamat, Anda Mendapatkan Nilai A " << std::endl;
    } else if (nilai >= 70) {
        std::cout << " Anda Mendapatkan Nilai B " << std::endl;
    } else if (nilai >= 60) {
        std::cout << " Anda Mendapatkan Nilai C " << std::endl;
    } else {
        std::cout << " Maaf, Anda Tidak Lulus " << std::endl;
    }
}


int main() {
    contoh_if();
    dua_kondisi();
    lebih_dari_dua_kondisi();
    return 0;
}