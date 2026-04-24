// contoh perulangan 1
#include <iostream>
using namespace std;

void perulangan_1() {
    int a;
    for(a = 1; a <= 10; a++) {
        cout << "halo ini perulangan" << endl;
    }
}

// contoh perulangan 2
void perulangan_2() {
    int i;
    for (i = 1; i <= 30; ++i) { // jika i++ dia akan turun 
        cout << i << endl;
    }
}

// contoh perulagan 3
void perulangan_3() {
    int a, b;
    for(a = 1; a <= 10; a++) {
        cout << "\n";
        for(b = a; b <= 10; b++) {
            cout << " " << a << " ";
        }
        cout << endl;
    }
}


int main() {
    perulangan_1();
    perulangan_2();
    perulangan_3();
    return 0;
}