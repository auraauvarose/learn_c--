#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
using namespace std;

// Struct untuk menyimpan data kontak
struct Kontak {
    string nama;
    string nomor;
    string email;
};

// Array untuk menyimpan daftar kontak
vector<Kontak> daftarKontak;

// Fungsi untuk membersihkan layar
void bersihkanLayar() {
    system("clear");
}

// Fungsi untuk menekan enter
void tekanEnter() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

// 1. Menambah kontak
void tambahKontak() {
    bersihkanLayar();
    cout << "=== TAMBAH KONTAK BARU ===" << endl;
    
    Kontak baru;
    
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, baru.nama);
    
    cout << "Masukkan nomor HP: ";
    getline(cin, baru.nomor);
    
    cout << "Masukkan email: ";
    getline(cin, baru.email);
    
    daftarKontak.push_back(baru);
    
    cout << "\nKontak berhasil ditambahkan!" << endl;
    tekanEnter();
}

// 2. Menampilkan semua kontak
void tampilkanSemua() {
    bersihkanLayar();
    cout << "=== DAFTAR KONTAK ===" << endl;
    
    if (daftarKontak.empty()) {
        cout << "\nBelum ada kontak yang tersimpan." << endl;
    } else {
        cout << "\n";
        cout << left << setw(5) << "No" 
             << setw(20) << "Nama" 
             << setw(15) << "Nomor HP" 
             << setw(30) << "Email" << endl;
        cout << string(70, '-') << endl;
        
        for (int i = 0; i < daftarKontak.size(); i++) {
            cout << left << setw(5) << (i + 1)
                 << setw(20) << daftarKontak[i].nama
                 << setw(15) << daftarKontak[i].nomor
                 << setw(30) << daftarKontak[i].email << endl;
        }
    }
    
    tekanEnter();
}

// 3. Mencari kontak
void cariKontak() {
    bersihkanLayar();
    cout << "=== CARI KONTAK ===" << endl;
    
    if (daftarKontak.empty()) {
        cout << "\nBelum ada kontak yang tersimpan." << endl;
        tekanEnter();
        return;
    }
    
    string cari;
    cout << "\nMasukkan nama yang dicari: ";
    cin.ignore();
    getline(cin, cari);
    
    // Ubah ke lowercase untuk pencarian tidak case-sensitive
    string cariLower = cari;
    transform(cariLower.begin(), cariLower.end(), cariLower.begin(), ::tolower);
    
    bool ketemu = false;
    
    for (int i = 0; i < daftarKontak.size(); i++) {
        string namaLower = daftarKontak[i].nama;
        transform(namaLower.begin(), namaLower.end(), namaLower.begin(), ::tolower);
        
        if (namaLower.find(cariLower) != string::npos) {
            if (!ketemu) {
                cout << "\nHasil pencarian:" << endl;
                cout << string(70, '-') << endl;
            }
            ketemu = true;
            cout << "Nama  : " << daftarKontak[i].nama << endl;
            cout << "Nomor : " << daftarKontak[i].nomor << endl;
            cout << "Email : " << daftarKontak[i].email << endl;
            cout << string(70, '-') << endl;
        }
    }
    
    if (!ketemu) {
        cout << "\nKontak dengan nama '" << cari << "' tidak ditemukan." << endl;
    }
    
    tekanEnter();
}

// 4. Menghapus kontak
void hapusKontak() {
    bersihkanLayar();
    cout << "=== HAPUS KONTAK ===" << endl;
    
    if (daftarKontak.empty()) {
        cout << "\nBelum ada kontak yang tersimpan." << endl;
        tekanEnter();
        return;
    }
    
    int nomor;
    cout << "\nMasukkan nomor kontak yang akan dihapus: ";
    cin >> nomor;
    
    if (nomor < 1 || nomor > daftarKontak.size()) {
        cout << "\nNomor kontak tidak valid!" << endl;
    } else {
        cout << "\nYakin ingin menghapus kontak '" 
             << daftarKontak[nomor - 1].nama << "'? (y/n): ";
        char konfirmasi;
        cin >> konfirmasi;
        
        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            daftarKontak.erase(daftarKontak.begin() + (nomor - 1));
            cout << "\nKontak berhasil dihapus!" << endl;
        } else {
            cout << "\nPenghapusan dibatalkan." << endl;
        }
    }
    
    tekanEnter();
}

// 5. Mengedit kontak
void editKontak() {
    bersihkanLayar();
    cout << "=== EDIT KONTAK ===" << endl;
    
    if (daftarKontak.empty()) {
        cout << "\nBelum ada kontak yang tersimpan." << endl;
        tekanEnter();
        return;
    }
    
    int nomor;
    cout << "\nMasukkan nomor kontak yang akan diedit: ";
    cin >> nomor;
    
    if (nomor < 1 || nomor > daftarKontak.size()) {
        cout << "\nNomor kontak tidak valid!" << endl;
    } else {
        int idx = nomor - 1;
        cout << "\nEdit kontak '" << daftarKontak[idx].nama << "'" << endl;
        cout << "Ketik 'skip' jika tidak ingin mengubah." << endl;
        
        string input;
        cin.ignore();
        
        cout << "Nama baru (sekarang: " << daftarKontak[idx].nama << "): ";
        getline(cin, input);
        if (input != "skip" && !input.empty()) {
            daftarKontak[idx].nama = input;
        }
        
        cout << "Nomor baru (sekarang: " << daftarKontak[idx].nomor << "): ";
        getline(cin, input);
        if (input != "skip" && !input.empty()) {
            daftarKontak[idx].nomor = input;
        }
        
        cout << "Email baru (sekarang: " << daftarKontak[idx].email << "): ";
        getline(cin, input);
        if (input != "skip" && !input.empty()) {
            daftarKontak[idx].email = input;
        }
        
        cout << "\nKontak berhasil diupdate!" << endl;
    }
    
    tekanEnter();
}

int main() {
    int pilihan;
    
    do {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "    SISTEM MANAJEMEN KONTAK" << endl;
        cout << "========================================" << endl;
        cout << "1. Tambah Kontak" << endl;
        cout << "2. Tampilkan Semua Kontak" << endl;
        cout << "3. Cari Kontak" << endl;
        cout << "4. Hapus Kontak" << endl;
        cout << "5. Edit Kontak" << endl;
        cout << "6. Keluar" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                tambahKontak();
                break;
            case 2:
                tampilkanSemua();
                break;
            case 3:
                cariKontak();
                break;
            case 4:
                hapusKontak();
                break;
            case 5:
                editKontak();
                break;
            case 6:
                cout << "\nTerima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid! Coba lagi." << endl;
                tekanEnter();
        }
        
    } while (pilihan != 6);
    
    return 0;
}
