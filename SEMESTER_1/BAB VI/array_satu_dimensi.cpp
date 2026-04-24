#include <iostream>
using namespace std;

void contoh_1() {
    int angka[4] = {94, 61, 25, 14}; 
    for(int a = 0; a < 4; a++) {
        cout << "Index Angka [" << a << "] = " << angka[a] << endl;        
    }
}

void contoh_2() {
    char mem[9][20] = {
        "saya",
        "sedang",
        "belajar",
        "bahasa",
        "c++",
        "di",
        "kuliah",
        "programming",
        "university"
    };
    cout << " Nama personal " << endl;
    for (int m =0; m < 9; m++) {
        cout << m << ". " << mem[m] << endl;
    }
}

int main() {
    contoh_1();
    contoh_2();
    return 0;
}