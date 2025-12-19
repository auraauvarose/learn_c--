#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits>
#include <ctime>

using namespace std;

// Struktur data barang
struct Barang {
    int id;
    string nama;
    string kategori;
    int stok;
    int stok_minimum;
    double harga;
    string tanggal_update;
};

// Struktur aktivitas
struct Aktivitas {
    string jenis;
    string nama_barang;
    int jumlah;
    string tanggal;
};

// Struktur riwayat restock
struct RiwayatRestock {
    string nama_barang;
    int jumlah;
    string supplier;
    string tanggal;
};

// Global variables
vector<Barang> daftarBarang;
vector<Aktivitas> daftarAktivitas;
vector<RiwayatRestock> riwayatRestock;
int id_counter = 1;

// Fungsi utilitas
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    return string(buffer);
}

void showHeader(string title) {
    clearScreen();
    cout << "========================================\n";
    cout << "        STOCKGUARD - " << title << "\n";
    cout << "========================================\n\n";
}

// Fungsi menu utama
void showMainMenu() {
    clearScreen();
    cout << "========================================\n";
    cout << "       APLIKASI PENGELOLAAN STOK        \n";
    cout << "             STOCKGUARD v1.0            \n";
    cout << "========================================\n\n";
    
    cout << "Menu Utama:\n";
    cout << "1. Dashboard\n";
    cout << "2. Kelola Stok Barang\n";
    cout << "3. Tambah Barang Baru\n";
    cout << "4. Manajemen Restock\n";
    cout << "5. Laporan Stok\n";
    cout << "6. Simpan Data ke File\n";
    cout << "7. Load Data dari File\n";
    cout << "8. Keluar\n\n";
}

// Fungsi dashboard
void showDashboard() {
    showHeader("DASHBOARD");
    
    int total_barang = daftarBarang.size();
    int stok_aman = 0;
    int perlu_restock = 0;
    int stok_habis = 0;
    
    // Hitung statistik
    for (const auto& barang : daftarBarang) {
        if (barang.stok == 0) {
            stok_habis++;
        } else if (barang.stok <= barang.stok_minimum) {
            perlu_restock++;
        } else {
            stok_aman++;
        }
    }
    
    // Tampilkan statistik
    cout << "STATISTIK STOK\n";
    cout << "---------------\n";
    cout << "Total Barang      : " << total_barang << " item\n";
    cout << "Stok Aman         : " << stok_aman << " item\n";
    cout << "Perlu Restock     : " << perlu_restock << " item\n";
    cout << "Stok Habis        : " << stok_habis << " item\n\n";
    
    // Barang yang perlu restock
    if (perlu_restock > 0) {
        cout << "BARANG PERLU RESTOCK:\n";
        cout << "---------------------\n";
        for (const auto& barang : daftarBarang) {
            if (barang.stok <= barang.stok_minimum && barang.stok > 0) {
                cout << "- " << barang.nama;
                cout << " (Stok: " << barang.stok;
                cout << ", Min: " << barang.stok_minimum << ")\n";
            }
        }
        cout << "\n";
    }
    
    // Aktivitas terbaru
    cout << "AKTIVITAS TERBARU:\n";
    cout << "------------------\n";
    int count = 0;
    for (int i = daftarAktivitas.size() - 1; i >= 0 && count < 5; i--, count++) {
        cout << "- " << daftarAktivitas[i].nama_barang << " ";
        cout << daftarAktivitas[i].jenis << " " << daftarAktivitas[i].jumlah << " unit\n";
        cout << "  " << daftarAktivitas[i].tanggal << "\n";
    }
    
    if (daftarAktivitas.empty()) {
        cout << "Belum ada aktivitas\n";
    }
    
    pauseScreen();
}

// Fungsi kelola stok
void manageStock() {
    int choice;
    do {
        showHeader("KELOLA STOK BARANG");
        
        cout << "DAFTAR BARANG:\n";
        cout << "--------------------------------------------------------------------\n";
        cout << left << setw(4) << "ID" << setw(30) << "Nama Barang" 
             << setw(10) << "Stok" << setw(10) << "Minimum" << "Status\n";
        cout << "--------------------------------------------------------------------\n";
        
        if (daftarBarang.empty()) {
            cout << "Belum ada data barang\n";
        } else {
            for (const auto& barang : daftarBarang) {
                cout << left << setw(4) << barang.id 
                     << setw(30) << (barang.nama.length() > 28 ? barang.nama.substr(0, 28) + ".." : barang.nama)
                     << setw(10) << barang.stok 
                     << setw(10) << barang.stok_minimum;
                
                if (barang.stok == 0) {
                    cout << "HABIS";
                } else if (barang.stok <= barang.stok_minimum) {
                    cout << "MENIPIS";
                } else {
                    cout << "AMAN";
                }
                cout << "\n";
            }
        }
        
        cout << "\n--------------------------------------------------------------------\n\n";
        cout << "1. Tambah Stok (Barang Masuk)\n";
        cout << "2. Kurangi Stok (Barang Keluar)\n";
        cout << "3. Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
        cin >> choice;
        
        if (choice == 1) {
            // Tambah stok
            int id, jumlah;
            cout << "\nMasukkan ID barang: ";
            cin >> id;
            
            auto it = find_if(daftarBarang.begin(), daftarBarang.end(),
                [id](const Barang& b) { return b.id == id; });
            
            if (it != daftarBarang.end()) {
                cout << "Barang: " << it->nama << " (Stok: " << it->stok << ")\n";
                cout << "Jumlah yang ditambahkan: ";
                cin >> jumlah;
                
                if (jumlah > 0) {
                    it->stok += jumlah;
                    it->tanggal_update = getCurrentDate();
                    
                    // Catat aktivitas
                    Aktivitas akt;
                    akt.jenis = "ditambahkan";
                    akt.nama_barang = it->nama;
                    akt.jumlah = jumlah;
                    akt.tanggal = getCurrentDate();
                    daftarAktivitas.push_back(akt);
                    
                    cout << "\nBerhasil menambah stok!\n";
                    cout << "Stok sekarang: " << it->stok << "\n";
                } else {
                    cout << "Jumlah harus positif!\n";
                }
            } else {
                cout << "Barang dengan ID " << id << " tidak ditemukan!\n";
            }
            pauseScreen();
        } else if (choice == 2) {
            // Kurangi stok
            int id, jumlah;
            cout << "\nMasukkan ID barang: ";
            cin >> id;
            
            auto it = find_if(daftarBarang.begin(), daftarBarang.end(),
                [id](const Barang& b) { return b.id == id; });
            
            if (it != daftarBarang.end()) {
                cout << "Barang: " << it->nama << " (Stok: " << it->stok << ")\n";
                cout << "Jumlah yang dikurangi: ";
                cin >> jumlah;
                
                if (jumlah > 0) {
                    if (jumlah <= it->stok) {
                        it->stok -= jumlah;
                        it->tanggal_update = getCurrentDate();
                        
                        // Catat aktivitas
                        Aktivitas akt;
                        akt.jenis = "dikurangi";
                        akt.nama_barang = it->nama;
                        akt.jumlah = jumlah;
                        akt.tanggal = getCurrentDate();
                        daftarAktivitas.push_back(akt);
                        
                        cout << "\nBerhasil mengurangi stok!\n";
                        cout << "Stok sekarang: " << it->stok << "\n";
                        
                        // Cek apakah perlu restock
                        if (it->stok <= it->stok_minimum) {
                            cout << "\nPERINGATAN: Stok " << it->nama;
                            cout << " menipis (" << it->stok << "/" << it->stok_minimum << ")!\n";
                            cout << "Perlu dilakukan restock!\n";
                        }
                    } else {
                        cout << "Stok tidak cukup! Stok tersedia: " << it->stok << "\n";
                    }
                } else {
                    cout << "Jumlah harus positif!\n";
                }
            } else {
                cout << "Barang dengan ID " << id << " tidak ditemukan!\n";
            }
            pauseScreen();
        }
    } while (choice != 3);
}

// Fungsi tambah barang baru
void addNewItem() {
    showHeader("TAMBAH BARANG BARU");
    
    Barang barang;
    barang.id = id_counter++;
    
    cin.ignore();
    cout << "Nama Barang: ";
    getline(cin, barang.nama);
    
    cout << "Kategori (elektronik/perkakas/bahan/makanan/lainnya): ";
    getline(cin, barang.kategori);
    
    cout << "Stok Awal: ";
    cin >> barang.stok;
    
    cout << "Stok Minimum: ";
    cin >> barang.stok_minimum;
    
    cout << "Harga (Rp): ";
    cin >> barang.harga;
    
    barang.tanggal_update = getCurrentDate();
    
    daftarBarang.push_back(barang);
    
    // Catat aktivitas
    Aktivitas akt;
    akt.jenis = "ditambahkan (baru)";
    akt.nama_barang = barang.nama;
    akt.jumlah = barang.stok;
    akt.tanggal = getCurrentDate();
    daftarAktivitas.push_back(akt);
    
    cout << "\nBarang berhasil ditambahkan!\n";
    cout << "ID Barang: " << barang.id << "\n";
    
    pauseScreen();
}

// Fungsi manajemen restock
void manageRestock() {
    int choice;
    do {
        showHeader("MANAJEMEN RESTOCK");
        
        // Tampilkan barang yang perlu restock
        cout << "BARANG YANG PERLU RESTOCK:\n";
        cout << "--------------------------\n";
        
        bool ada_restock = false;
        for (const auto& barang : daftarBarang) {
            if (barang.stok <= barang.stok_minimum) {
                ada_restock = true;
                cout << "ID: " << barang.id << " | ";
                cout << "Nama: " << barang.nama << " | ";
                cout << "Stok: " << barang.stok << " | ";
                cout << "Minimum: " << barang.stok_minimum << "\n";
                cout << "Kekurangan: " << (barang.stok_minimum - barang.stok) << " unit\n\n";
            }
        }
        
        if (!ada_restock) {
            cout << "Tidak ada barang yang perlu restock\n\n";
        }
        
        cout << "MENU RESTOCK:\n";
        cout << "1. Lakukan Restock\n";
        cout << "2. Lihat Riwayat Restock\n";
        cout << "3. Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
        cin >> choice;
        
        if (choice == 1) {
            // Lakukan restock
            int id, jumlah;
            string supplier;
            
            cout << "\nMasukkan ID barang yang direstock: ";
            cin >> id;
            
            auto it = find_if(daftarBarang.begin(), daftarBarang.end(),
                [id](const Barang& b) { return b.id == id; });
            
            if (it != daftarBarang.end()) {
                cout << "Barang: " << it->nama << "\n";
                cout << "Stok saat ini: " << it->stok << "\n";
                cout << "Stok minimum: " << it->stok_minimum << "\n";
                cout << "Jumlah restock: ";
                cin >> jumlah;
                
                cin.ignore();
                cout << "Nama Supplier: ";
                getline(cin, supplier);
                
                if (jumlah > 0) {
                    it->stok += jumlah;
                    it->tanggal_update = getCurrentDate();
                    
                    // Catat riwayat restock
                    RiwayatRestock riwayat;
                    riwayat.nama_barang = it->nama;
                    riwayat.jumlah = jumlah;
                    riwayat.supplier = supplier;
                    riwayat.tanggal = getCurrentDate();
                    riwayatRestock.push_back(riwayat);
                    
                    // Catat aktivitas
                    Aktivitas akt;
                    akt.jenis = "direstock";
                    akt.nama_barang = it->nama;
                    akt.jumlah = jumlah;
                    akt.tanggal = getCurrentDate();
                    daftarAktivitas.push_back(akt);
                    
                    cout << "\nRestock berhasil!\n";
                    cout << "Stok sekarang: " << it->stok << " unit\n";
                } else {
                    cout << "Jumlah harus positif!\n";
                }
            } else {
                cout << "Barang tidak ditemukan!\n";
            }
            pauseScreen();
        } else if (choice == 2) {
            // Lihat riwayat restock
            showHeader("RIWAYAT RESTOCK");
            
            if (riwayatRestock.empty()) {
                cout << "Belum ada riwayat restock\n";
            } else {
                cout << left << setw(30) << "Barang" << setw(10) << "Jumlah" 
                     << setw(20) << "Supplier" << "Tanggal\n";
                cout << string(80, '-') << "\n";
                
                for (const auto& riwayat : riwayatRestock) {
                    cout << left << setw(30) << (riwayat.nama_barang.length() > 28 ? 
                         riwayat.nama_barang.substr(0, 28) + ".." : riwayat.nama_barang)
                         << setw(10) << riwayat.jumlah
                         << setw(20) << (riwayat.supplier.length() > 18 ? 
                         riwayat.supplier.substr(0, 18) + ".." : riwayat.supplier)
                         << riwayat.tanggal << "\n";
                }
            }
            pauseScreen();
        }
    } while (choice != 3);
}

// Fungsi laporan stok
void showReport() {
    showHeader("LAPORAN STOK");
    
    if (daftarBarang.empty()) {
        cout << "Belum ada data barang\n";
    } else {
        // Hitung total nilai stok
        double total_nilai = 0;
        for (const auto& barang : daftarBarang) {
            total_nilai += barang.stok * barang.harga;
        }
        
        cout << "TOTAL NILAI STOK: Rp " << fixed << setprecision(0) << total_nilai << "\n\n";
        
        cout << left << setw(4) << "ID" << setw(30) << "Nama Barang" 
             << setw(15) << "Kategori" << setw(10) << "Stok" 
             << setw(10) << "Minimum" << setw(15) << "Harga" 
             << setw(12) << "Total Nilai" << "Status\n";
        cout << string(100, '-') << "\n";
        
        for (const auto& barang : daftarBarang) {
            double nilai_barang = barang.stok * barang.harga;
            
            cout << left << setw(4) << barang.id 
                 << setw(30) << (barang.nama.length() > 28 ? barang.nama.substr(0, 28) + ".." : barang.nama)
                 << setw(15) << (barang.kategori.length() > 13 ? barang.kategori.substr(0, 13) + ".." : barang.kategori)
                 << setw(10) << barang.stok 
                 << setw(10) << barang.stok_minimum
                 << setw(15) << fixed << setprecision(0) << barang.harga
                 << setw(12) << fixed << setprecision(0) << nilai_barang;
            
            if (barang.stok == 0) {
                cout << "HABIS";
            } else if (barang.stok <= barang.stok_minimum) {
                cout << "MENIPIS";
            } else {
                cout << "AMAN";
            }
            cout << "\n";
        }
        
        cout << "\nSTATUS WARNA:\n";
        cout << "HABIS   = Stok 0 unit\n";
        cout << "MENIPIS = Stok <= Minimum\n";
        cout << "AMAN    = Stok > Minimum\n";
    }
    
    pauseScreen();
}

// Fungsi save/load data
void saveDataToFile() {
    ofstream file("stock_data.txt");
    
    if (file.is_open()) {
        // Simpan data barang
        file << daftarBarang.size() << "\n";
        for (const auto& barang : daftarBarang) {
            file << barang.id << "\n";
            file << barang.nama << "\n";
            file << barang.kategori << "\n";
            file << barang.stok << "\n";
            file << barang.stok_minimum << "\n";
            file << barang.harga << "\n";
            file << barang.tanggal_update << "\n";
        }
        
        file.close();
        cout << "Data berhasil disimpan ke stock_data.txt\n";
    } else {
        cout << "Gagal membuka file untuk disimpan!\n";
    }
    
    pauseScreen();
}

void loadDataFromFile() {
    ifstream file("stock_data.txt");
    
    if (file.is_open()) {
        daftarBarang.clear();
        
        int jumlah;
        file >> jumlah;
        file.ignore();
        
        id_counter = 1;
        
        for (int i = 0; i < jumlah; i++) {
            Barang barang;
            file >> barang.id;
            file.ignore();
            getline(file, barang.nama);
            getline(file, barang.kategori);
            file >> barang.stok;
            file >> barang.stok_minimum;
            file >> barang.harga;
            file.ignore();
            getline(file, barang.tanggal_update);
            
            daftarBarang.push_back(barang);
            
            // Update id_counter
            if (barang.id >= id_counter) {
                id_counter = barang.id + 1;
            }
        }
        
        file.close();
        cout << "Data berhasil dimuat dari stock_data.txt\n";
    } else {
        cout << "File stock_data.txt tidak ditemukan!\n";
    }
    
    pauseScreen();
}

// Fungsi inisialisasi data contoh
void initializeSampleData() {
    // Data contoh untuk testing
    daftarBarang.clear();
    daftarAktivitas.clear();
    riwayatRestock.clear();
    id_counter = 1;
    
    Barang b1 = {id_counter++, "Laptop ASUS X441BA", "elektronik", 15, 10, 7500000, "2024-01-15"};
    Barang b2 = {id_counter++, "Mouse Wireless Logitech", "elektronik", 8, 5, 250000, "2024-01-14"};
    Barang b3 = {id_counter++, "Kertas A4 80gsm", "bahan", 3, 10, 50000, "2024-01-13"};
    Barang b4 = {id_counter++, "Pulpen Standard", "alat tulis", 50, 20, 3000, "2024-01-12"};
    Barang b5 = {id_counter++, "Kabel HDMI 2m", "elektronik", 0, 5, 75000, "2024-01-10"};
    
    daftarBarang.push_back(b1);
    daftarBarang.push_back(b2);
    daftarBarang.push_back(b3);
    daftarBarang.push_back(b4);
    daftarBarang.push_back(b5);
    
    cout << "Data contoh berhasil dimuat!\n";
    pauseScreen();
}

// Fungsi utama
int main() {
    // Inisialisasi data contoh
    initializeSampleData();
    
    int pilihan;
    do {
        showMainMenu();
        cout << "Pilih menu (1-8): ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                showDashboard();
                break;
            case 2:
                manageStock();
                break;
            case 3:
                addNewItem();
                break;
            case 4:
                manageRestock();
                break;
            case 5:
                showReport();
                break;
            case 6:
                saveDataToFile();
                break;
            case 7:
                loadDataFromFile();
                break;
            case 8:
                cout << "\nTerima kasih telah menggunakan StockGuard!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                pauseScreen();
                break;
        }
    } while (pilihan != 8);
    
    return 0;
}