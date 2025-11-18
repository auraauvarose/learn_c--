#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << " ## Perkalian matriks dinamis ##" << endl;
    cout << " ============================= " << endl;
    cout << endl;

    int matriksA[2][2], matiksB[2][2], matrikshasil[2][2], i, j, k;

    cout << "Masukan elemen matriks A (2x2):" << endl;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << "baris" << i + 1 << ", kolom " << j + 1 << " =";
            cin >> matriksA[i][j];
        }
    }

    cout << endl;

    cout << "Masukan elemen matriks B (2x2):" << endl;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << "baris" << i + 1 << ", kolom " << j + 1 << " =";
            cin >> matiksB[i][j];
        }
    }

    cout << endl;

    cout << "matirks A" << endl;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << setw(3) << matriksA[i][j] << "";
        }
        cout << endl;
    }

    cout << endl;

    cout << "matriks B" << endl;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << setw(3) << matiksB[i][j] << "";
        }

        cout << endl;
    }

    cout << endl;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            for(k = 0; k < 2; k++) {
                matrikshasil[i][j] = matrikshasil[i][j] + matriksA[i][k] * matiksB[k][j]; 
            }
        }
    }

    cout << "Hasil perkalian matriks A dan B adalah :" << endl;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << setw(3) << matrikshasil[i][j] << "";
        }
        cout << endl;
    }

    return 0;
    
}

