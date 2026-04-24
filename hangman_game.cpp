#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

// Daftar kata untuk ditebak
const char* KATA[] = {
    "programming",
    "computer",
    "cplusplus",
    "hangman",
    "keyboard",
    "monitor",
    "variable",
    "function",
    "algorithm",
    "developer"
};
const int JUMLAH_KATA = sizeof(KATA) / sizeof(KATA[0]);
const int MAX_NYAWA = 6;

void tampilkanHangman(int nyawa) {
    cout << "\n";
    if (nyawa == MAX_NYAWA) {
        cout << "   _______" << endl;
        cout << "  |       |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "__|__" << endl;
    } else if (nyawa == 5) {
        cout << "   _______" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "__|__" << endl;
    } else if (nyawa == 4) {
        cout << "   _______" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |       |" << endl;
        cout << "  |       |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "__|__" << endl;
    } else if (nyawa == 3) {
        cout << "   _______" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |      /|" << endl;
        cout << "  |       |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "__|__" << endl;
    } else if (nyawa == 2) {
        cout << "   _______" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |      /|\\" << endl;
        cout << "  |       |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "__|__" << endl;
    } else if (nyawa == 1) {
        cout << "   _______" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |      /|\\" << endl;
        cout << "  |       |" << endl;
        cout << "  |      /" << endl;
        cout << "  |" << endl;
        cout << "__|__" << endl;
    } else if (nyawa == 0) {
        cout << "   _______" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |      /|\\" << endl;
        cout << "  |       |" << endl;
        cout << "  |      / \\" << endl;
        cout << "  |" << endl;
        cout << "__|__" << endl;
    }
    cout << "\n";
}

void tampilkanKata(const char* kata, bool* terTebak, int panjang) {
    for (int i = 0; i < panjang; i++) {
        if (terTebak[i]) {
            cout << kata[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << "\n";
}

bool cekMenang(bool* terTebak, int panjang) {
    for (int i = 0; i < panjang; i++) {
        if (!terTebak[i]) return false;
    }
    return true;
}

bool sudahDitebak(const char* hurufDitebak, int jumlahTebak, char huruf) {
    for (int i = 0; i < jumlahTebak; i++) {
        if (hurufDitebak[i] == huruf) return true;
    }
    return false;
}

int main() {
    srand(time(0));
    
    cout << "========================================" << endl;
    cout << "     SELAMAT DATANG DI GAME HANGMAN      " << endl;
    cout << "========================================" << endl;
    cout << "\nPetunjuk:" << endl;
    cout << "- Tebak kata dengan memasukkan huruf" << endl;
    cout << "- Anda punya " << MAX_NYAWA << " nyawa" << endl;
    cout << "- Setiap tebakan salah akan mengurangi nyawa" << endl;
    cout << "- Selamat bermain!" << endl;
    cout << "========================================\n" << endl;

    char mainLagi;
    do {
        // Pilih kata random
        int indexKata = rand() % JUMLAH_KATA;
        const char* kataTebak = KATA[indexKata];
        int panjangKata = strlen(kataTebak);
        
        // Inisialisasi status tebakan
        bool* terTebak = new bool[panjangKata];
        for (int i = 0; i < panjangKata; i++) {
            terTebak[i] = false;
        }
        
        int nyawa = MAX_NYAWA;
        char hurufDitebak[50];
        int jumlahTebak = 0;
        bool menang = false;
        
        while (nyawa > 0 && !menang) {
            system("clear"); // Gunakan "cls" untuk Windows
            
            cout << "========================================" << endl;
            cout << "              GAME HANGMAN               " << endl;
            cout << "========================================" << endl;
            cout << "Nyawa tersisa: " << nyawa << endl;
            cout << "Huruf ditebak: ";
            for (int i = 0; i < jumlahTebak; i++) {
                cout << hurufDitebak[i] << " ";
            }
            cout << "\n\n";
            
            tampilkanHangman(nyawa);
            tampilkanKata(kataTebak, terTebak, panjangKata);
            
            cout << "\nMasukkan huruf (a-z): ";
            char input;
            cin >> input;
            
            // Konversi ke huruf kecil
            input = tolower(input);
            
            // Validasi input
            if (input < 'a' || input > 'z') {
                cout << "\nInput tidak valid! Masukkan huruf a-z saja." << endl;
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                continue;
            }
            
            // Cek apakah sudah ditebak
            if (sudahDitebak(hurufDitebak, jumlahTebak, input)) {
                cout << "\nHuruf '" << input << "' sudah pernah ditebak!" << endl;
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                continue;
            }
            
            // Simpan huruf yang ditebak
            hurufDitebak[jumlahTebak] = input;
            jumlahTebak++;
            
            // Cek apakah huruf ada di kata
            bool benar = false;
            for (int i = 0; i < panjangKata; i++) {
                if (kataTebak[i] == input) {
                    terTebak[i] = true;
                    benar = true;
                }
            }
            
            if (benar) {
                cout << "\nBenar! Huruf '" << input << "' ada di kata." << endl;
            } else {
                nyawa--;
                cout << "\nSalah! Huruf '" << input << "' tidak ada di kata." << endl;
                cout << "Nyawa berkurang! Sisa nyawa: " << nyawa << endl;
            }
            
            // Cek menang
            menang = cekMenang(terTebak, panjangKata);
            
            if (!menang && nyawa > 0) {
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
            }
        }
        
        system("clear"); // Gunakan "cls" untuk Windows
        cout << "========================================" << endl;
        cout << "              GAME HANGMAN               " << endl;
        cout << "========================================" << endl;
        
        if (menang) {
            cout << "\nSELAMAT! Anda menang!" << endl;
            cout << "Kata yang ditebak: " << kataTebak << endl;
        } else {
            cout << "\nGAME OVER! Anda kalah!" << endl;
            cout << "Kata yang benar: " << kataTebak << endl;
            tampilkanHangman(0);
        }
        
        cout << "\nApakah ingin main lagi? (y/t): ";
        cin >> mainLagi;
        
        delete[] terTebak;
        
    } while (mainLagi == 'y' || mainLagi == 'Y');
    
    cout << "\nTerima kasih telah bermain! Sampai jumpa!" << endl;
    
    return 0;
}
