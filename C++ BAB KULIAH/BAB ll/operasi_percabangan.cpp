#include <iostream>

// if (jika)
void contoh_if() {
    int umur = 20;

    if (umur >= 17) {
        std::cout << " Anda susah dewasa " << std::endl;
    }

    std::cout << " Program selesai " << std::endl;
}


void dua_kondisi() {
    int nilai = 23;

    if (nilai >= 60) {
        std::cout << " Selamat, Anda Lulus " << std::endl;
    } else {
        std::cout << " Maaf, Anda Tidak Lulus " << std::endl;
    }
}


int main() {
    contoh_if();
    return 0;
}