#include <iostream>
using namespace std;

int main() {
    int bil = 1;
    do {
        if (bil >= 6) {
            cout << "Ini adalah bilangan genap: " << bil << endl;
            break;
        }

        if (bil % 2 == 0) {
            cout << "Ini adalah bilangan genap: " << bil << endl;
        }

        bil++; // penting agar loop bergerak maju
    } while (bil <= 10);

    return 0;
}