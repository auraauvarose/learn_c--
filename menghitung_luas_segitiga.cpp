#include <iostream>
using namespace std;

int main() {
    double alas, tinggi, luas; // double adalah tipe data dalam C++ yang berfungsi untuk menyimpan bilangan pecahan atau bilangan desimal.

    cout << "mausukan alas:";
    cin >> alas;

    cout << "masukan tinggi:";
    cin >> tinggi;

    cout << "menghitung luas segitiga" << endl;
    luas = 0.5 * alas * tinggi;

    cout << "luas segitiga adalah:" << luas << endl;
    return 0;
}
