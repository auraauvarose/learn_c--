/* 1. Buatlah program untuk menampilkan bilangan ganjil dari kecil ke besar sampai batas
tertentu sampai menemukan break, program selesai.


2. Bulatlah program untuk menghitung 20 deret bilangan genap dengan hasilnya :
2 + 4 + 6 + 8 + 10 + 12 + 14 + 16 + 18 + 20+22+24+26+28+30+32+34+36+38+40 = 420
36 */



#include <iostream>
using namespace std;

void bilangan_ganjil() {
    for(int bil = 1; bil <= 20; bil += 2) {
        if (bil > 15) {
            cout << "berhenti brok<>" << endl;
            break;
        }
        cout << "bilangan ganjil: " << bil << endl;
    }
}


void bilangan_genap() {
    int hasil_dari_bilangan_genap = 0;
    for(int i = 1; i <= 20; i++) {
        int genap = i * 2;
        hasil_dari_bilangan_genap += genap;
        cout << genap;
        if (i < 20) {
            cout << " + ";
        }
    }
    cout << " = " << hasil_dari_bilangan_genap << endl;
}


int main(){
    bilangan_ganjil();
    cout << "  --------------   " << endl;
    bilangan_genap();
    return 0;
}