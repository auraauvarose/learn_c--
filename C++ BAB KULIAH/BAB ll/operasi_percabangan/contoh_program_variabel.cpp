#include <iostream>
#include <string>

using namespace std;

int main() {

    // deklarasi data variabel
    string nama;
    int umur;
    char jenis_kelamin;


    // --- proses input ---
    cout << "Siapa nama kamu? " << endl;
    cout << "jawab: ";
    // menyimpan data ke variabel
    cin >> nama;

    cout << "Berapa umur kamu? " << endl;
    // menyimpan data ke variabel
    cin >> umur;

    cout << "Jenis kelamin (L/P)? " << endl;
    // menyimpan data ke variabel
    cin >> jenis_kelamin;

    // --- proses output ---
    cout << "halo " << nama << ", sekarang umur kamu? ";
    cout << umur << " dan jenis kelamin kamu " << jenis_kelamin;

    return 0;
}