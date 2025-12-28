#include <iostream>
using namespace std;

// Sorting adalah suatu proses pengurutan data yang sebelumnya disusun secara acak atau tidak teratur menjadi urut dan teratur menurut suatu aturan tertentu

int main() {
    int A[5];
    int j,k,i,temp;
    int jmax,u = 4;

    cout <<"mausukan nilai pada element array :" << endl;
    for(i = 0; i < 5; i++) {
        cout << "A ["<< i <<"] ="; cin >> A[i];
    }
    for(j = 0; j < 5; j++) {
        jmax = 0;
        for(k = 1; k <= u; k++) {
            if(A[k] > A[jmax]) {
                jmax = k;
                temp = A[u];
                A[u] = A[jmax];
                A[jmax] = temp;
                u--;
            }
        }
    }
    cout << "\nNilai element array setelah diurutkan : " << endl;
    for(i = 0; i < 5; i++) 
    cout << A[i] << " " << endl;
}