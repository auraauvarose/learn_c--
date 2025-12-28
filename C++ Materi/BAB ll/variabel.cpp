/** Variabel  Adalah sebuah  tempat  untuk  menampung  data  dimemori  dimana  tempat  tersebut 
dapat menampung nilai (data) yang dapat berubah-ubah selama proses program. atau variabel 
juga disebut sebagai sebuah identifier yang mempunyai nilai dinamis, arti kata dinamis disini 
bermaksud bahwa nilai variabel tersebut dapat kita ubah sesuai kebutuhan dalam program. 
Dari pengertian variabel diatas dapat disimpulkan bahwa fungsi variabel adalah sebagai tempat 
yang akan digunakan untuk menampung data dimemori dimana tempat tersebut dapat 
menampung nilai (data) yang dapat berubah-ubah selama proses program. 
Terdapat beberapa jenis variabel yang digunakan dalam pemrograman C++, yaitu : Variabel 
Auto,  Variabel  Statis,  Variabel  Register,  dan  Variabel  Eksternal.  Klasifikasi  ini  sebenarnya 
hanya didasarkan pada ruang penyimpanannya saja. **/

#include <iostream>
using namespace std;

// Variabel Auto 
void variabelAuto() {
    int angka = 1; // variabel auto
    angka++;
    std::cout << " Nilai variabel auto " << angka << std::endl;
}

// variabel statis 
void hitungStatis() {
    static int angkaStatis = 1; // Ini variabel statis
    angkaStatis++;
    std::cout << "Angka statis sekarang: " << angkaStatis << std::endl;
}       

// variabel register
void loopCepat() {
    register int i; // Minta agar 'i' disimpan di register CPU
    for (i = 0; i < 10; i++) {
        // ... lakukan sesuatu dengan cepat
    }
}


int main() {
    variabelAuto();
    variabelAuto();
    variabelAuto();
    hitungStatis();
    hitungStatis();
    hitungStatis();
    loopCepat();
    return 0;
}