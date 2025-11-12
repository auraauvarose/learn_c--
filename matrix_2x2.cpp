#include <iostream>
using namespace std;

/*

Tugas 
1. Buatlah matrix 2 kali 2
2. Buatlah penghitungan antar matrix

*/


void matriks_2x2() {
    int matrix[2][2];
    int i, j;

    cout << "masukan matrix 2x2:\n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << "elemen [" << i << "][" << j << "] : ";
            cin >> matrix[i][j];
        }
    }

    cout << "matrix 2x2 yang dimasukan adalah:\n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }        
        cout << endl;
    }

    cout << "\n";
}



void pergitungan_matriks() {
    int A[2][2];
    int B[2][2];
    int C[2][2];
    
    int i,j;
    cout << "perhitungan penjumlahan matriks:" << endl;
    cout << "masukan matriks a:\n";

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\n";

    cout << "Masukan matriks b:\n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\n";

    cout << "hasil dari pemjumlahan a dan b adalah : \n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}




int main(){
    matriks_2x2();
    pergitungan_matriks();
    return 0;
}