#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    const double TUKAR_USD = 16604.0;
    const double TUKAR_EUR = 19303.0;
    const double TUKAR_JPY = 106.0;

    double jumlah_uangrupiah;
    char pilihan_mata_uang;
    double hasil_konversi = 0.0;
    string nama_mata_uang;

    cout << "|==============================|" << endl;
    cout << "|  KONVERTER MATA UANG RUPIAH  |" << endl;
    cout << "|==============================|" << endl;
    cout << endl;

    cout << " Masukan jumlah uang rupiah: ";
    cin >> jumlah_uangrupiah;

    cout << " Pilih mata uang tujuan konversi: " << endl;
    cout << " 1. Dolar Amerika (USD)" << endl;
    cout << " 2. Euro (EUR)" << endl;
    cout << " 3. Yen Jepang (JPY)" << endl;
    cout << " Masukan pilihan (1/2/3): ";
    cin >> pilihan_mata_uang; 
    cout << endl;

    pilihan_mata_uang = tolower(pilihan_mata_uang);

    if (pilihan_mata_uang == '1') {
        hasil_konversi = jumlah_uangrupiah / TUKAR_USD;
        nama_mata_uang = "Dolar Amerika (USD)";
    } else if (pilihan_mata_uang == '2') {
        hasil_konversi = jumlah_uangrupiah / TUKAR_EUR;
        nama_mata_uang = "Euro (EUR)";
    } else if (pilihan_mata_uang == '3') {
        hasil_konversi = jumlah_uangrupiah / TUKAR_JPY;
        nama_mata_uang = "Yen Jepang (JPY)";
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 1;
    }

    cout << " Hasil Konversi" << endl;
    cout << endl;

    cout << fixed << setprecision(2);

    cout << " Nilai IDR: " << jumlah_uangrupiah << " Rupiah" << endl;
    cout << " Nilai Konversi: " << hasil_konversi << " " << nama_mata_uang << endl;

    return 0;
}

