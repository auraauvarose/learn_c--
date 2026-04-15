#include <iostream>
using namespace std;

int main() {
    // ============================================
    // ESCAPE SEQUENCES DALAM C++
    // ============================================
    
    cout << "\n=== 1. NEWLINE (\\n) ===" << endl;
    cout << "Baris pertama\nBaris kedua\nBaris ketiga" << endl;
    
    cout << "\n=== 2. TAB (\\t) ===" << endl;
    cout << "Nama\t: " << "John Doe" << endl;
    cout << "Alamat\t: " << "123 Main St" << endl;
    cout << "Golongan darah\t: " << "A" << endl;
    
    cout << "\n=== 3. BACKSLASH (\\\\) ===" << endl;
    cout << "Path: C:\\Users\\Documents\\File.txt" << endl;
    cout << "URL: http:\\\\www.example.com" << endl;
    
    cout << "\n=== 4. DOUBLE QUOTE (\\\") ===" << endl;
    cout << "Dia berkata: \"Halo, apa kabar?\"" << endl;
    cout << "Program ini \"sangat\" berguna" << endl;
    
    cout << "\n=== 5. SINGLE QUOTE (\\') ===" << endl;
    cout << "Karakter: \'A\'" << endl;
    cout << "Lambang: \'@\'" << endl;
    
    cout << "\n=== 6. BACKSPACE (\\b) ===" << endl;
    cout << "Halo\b\b\bDunia" << endl;  // Menghapus 3 karakter terakhir
    
    cout << "\n=== 7. CARRIAGE RETURN (\\r) ===" << endl;
    cout << "Teks awal\rTeks baru" << endl;
    
    cout << "\n=== 8. VERTICAL TAB (\\v) ===" << endl;
    cout << "Baris 1\vBaris 2\vBaris 3" << endl;
    
    cout << "\n=== 9. FORM FEED (\\f) ===" << endl;
    cout << "Halaman 1\fHalaman 2" << endl;
    
    cout << "\n=== 10. ALERT/BEEP (\\a) ===" << endl;
    cout << "Perhatian!\a" << endl;  // Akan mengeluarkan suara beep
    cout << "Adakah suara beep? (Bergantung pada speaker)" << endl;
    
    cout << "\n=== 11. NULL CHARACTER (\\0) ===" << endl;
    cout << "Sebelum\0Sesudah" << endl;  // Sesudah tidak akan ditampilkan
    
    cout << "\n=== 12. HEXADECIMAL (\\xhh) ===" << endl;
    cout << "Karakter dari kode hex:" << endl;
    cout << "\x41\x42\x43\x44\x45" << endl;  // ABCDE
    cout << "\x50\x72\x6F\x67\x72\x61\x6D" << endl;  // Program
    
    cout << "\n=== 13. OCTAL (\\ooo) ===" << endl;
    cout << "Karakter dari kode octal:" << endl;
    cout << "\101\102\103\104\105" << endl;  // ABCDE (kode octal)
    cout << "\120\162\157\147\162\141\155" << endl;  // Program
    
    cout << "\n=== 14. KOMBINASI ESCAPE SEQUENCES ===" << endl;
    cout << "Tabel Data:\n\n";
    cout << "No.\tNama\t\tAlamat\n";
    cout << "---\t----\t\t------\n";
    cout << "1\tJohn Doe\t123 Main St\n";
    cout << "2\tJane Smith\t456 Oak Ave\n";
    cout << "3\tBob Wilson\t789 Pine Rd\n";
    
    cout << "\n=== 15. CONTOH PRAKTIS ===" << endl;
    cout << "Direktori: \"C:\\Users\\Documents\\project\\file.cpp\"" << endl;
    cout << "Status: File \'data.txt\' telah diproses\n" << endl;
    cout << "Pesan: \"Program selesai dengan status \'SUCCESS\'\"" << endl;
    
    return 0;
}