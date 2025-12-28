#include <iostream>
using namespace std;

void contoh_1() {
    int bil = 5;
    while(bil <= 30) {
        cout << bil << " ";
        bil += 5;
    }
}

void while_katakteristik() {
    int bil = 1;
    while (bil <= 20) {
        cout << " " << bil;
        bil++;
    }
    
}


int main() {
    contoh_1();
    while_katakteristik();
    return 0;
}