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

// pernyataan if bersarang
void if_bersarang() {
    int nilai = 75;
    bool hadir = true;

    if (hadir) {
        if (nilai >= 60) {
            std::cout << " Anda Lulus " << std::endl;
        } else {
            std::cout << " Anda Tidak Lulus " << std::endl;
        }
    } else {
        std::cout << " Anda Tidak Bisa Mengikuti Ujian Karena Tidak Hadir " << std::endl;
    }
}

// pernyataan switch case
void contoh_switch_case() {
    int hari = 3; // 1=Senin, 2=Selasa, dst.

    switch (hari) {
        case 1:
            std::cout << "Hari ini Senin." << std::endl;
            break; // 'break' penting agar tidak lanjut ke case berikutnya
        case 2:
            std::cout << "Hari ini Selasa." << std::endl;
            break;
        case 3:
            std::cout << "Hari ini Rabu." << std::endl; // Ini yang akan jalan
            break;
        default: // Mirip seperti 'else' terakhir
            std::cout << "Nomor hari tidak valid." << std::endl;
            break;
    }
}

int main() {
    contoh_if();
    dua_kondisi();
    lebih_dari_dua_kondisi();
    if_bersarang();
    contoh_switch_case();
    return 0;
}