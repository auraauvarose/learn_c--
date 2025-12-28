#include <iostream>
using namespace std;

void pilihan (int x) {
    if ( x == 1) {
        cout << "Anda memesan nasi goreng" << endl;
    }
    else {
        cout << "Anda memesan mie goreng" << endl;
    }

}

int main() {
    int pilih;

    cout << " 1. Nasi goreng " << '\n';
    cout << " 2. Mie goreng " << '\n';
    cout << "masukan pilihan anda (1-2): "; cin >> pilih;

    pilihan (pilih);
}