#include <iostream>
#include <iomanip> 
using namespace std;



int main() {
    cout << "## Perkalian matrix 2x2 ##" << endl;
    cout << "==========================" << endl;

    cout << endl;

    int matriksA[2][2], matriksB[2][2], matrikshasil[2][2],i,j,k;

    matriksA[0][0] = 1;
    matriksA[0][1] = 2;
    matriksA[1][0] = 3;
    matriksA[1][1] = 4;

    matriksB[0][0] = 5;
    matriksB[0][1] = 6;
    matriksB[1][0] = 7;
    matriksB[1][1] = 8;

    cout << "matriks A" << endl;
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
            cout << setw(3) << matriksB[i][j] << "";
        }
        cout << endl;
    }

    cout << endl;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            for(k = 0; k < 2; k++) {

                matrikshasil[i][j] = matrikshasil[i][j] + (matriksA[i][k] * matriksB[k][j]);

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

