#include <iostream>
#include <fstream>  
#include <string>
#include <ctime>    

using namespace std;

string ambilWaktu() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string waktu = dt;
    waktu.pop_back(); 
    return waktu;
}

void registrasi() {
    string nim, nama, password;
    cout << "\n=== DAFTAR AKUN BARU ===" << endl;
    cout << "Masukkan NIM      : "; cin >> nim;
    cin.ignore(); 
    cout << "Masukkan Nama     : "; getline(cin, nama);
    cout << "Masukkan Password : "; cin >> password;

    
    ofstream fileUser;
    fileUser.open("data_absensi.txt", ios::app);
    
    fileUser << nim << " " << password << " " << nama << endl; 
    
    fileUser.close();
    cout << ">> SUKSES: Data tersimpan di Database (data_absensi.txt)!" << endl;
}


bool login(string& nimLogin) {
    string nimInput, passInput;
    string dbNim, dbPass, dbNama;
    bool ketemu = false;

    cout << "\n=== LOGIN SYSTEM ===" << endl;
    cout << "NIM      : "; cin >> nimInput;
    cout << "Password : "; cin >> passInput;


    ifstream fileUser("data_absensi.txt");
    
    if (!fileUser.is_open()) {
        cout << "[ERROR] Database belum ada! Daftar dulu." << endl;
        return false;
    }


    while (fileUser >> dbNim >> dbPass >> ws) {
        getline(fileUser, dbNama); 
        
        if (dbNim == nimInput && dbPass == passInput) {
            ketemu = true;
            nimLogin = dbNim; 
            cout << ">> LOGIN BERHASIL! Halo, " << dbNama << endl;
            break;
        }
    }
    fileUser.close();
    
    if (!ketemu) {
        cout << ">> LOGIN GAGAL: NIM atau Password Salah!" << endl;
    }
    
    return ketemu; 
}


void prosesAbsen(string nim) {
    char konfirmasi;
    cout << "\nApakah Anda ingin absen sekarang? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        ofstream fileAbsen;
        fileAbsen.open("log_absensi.txt", ios::app);
        
        string waktu = ambilWaktu();
        fileAbsen << nim << " | HADIR | " << waktu << endl;
        
        fileAbsen.close();
        
        cout << ">> ABSEN TEREKAM! Data masuk ke log_absensi.txt" << endl;
        cout << ">> Waktu: " << waktu << endl;
    } else {
        cout << ">> Absensi dibatalkan." << endl;
    }
}

int main() {
    int pilihan;
    string userNIM;

    while (true) {
        cout << "\n1. Daftar" << endl;
        cout << "2. Login & Absen" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: "; cin >> pilihan;

        if (pilihan == 1) {
            registrasi();
        } 
        else if (pilihan == 2) {
            if (login(userNIM)) {
                prosesAbsen(userNIM);
            }
        } 
        else if (pilihan == 3) {
            break;
        } 
        else {
            cout << "Pilihan tidak ada." << endl;
        }
    }
    return 0;
}