   <h2 align="center" font-size="30px">BELAJAR C++ </h2>
   di repositories ini saya belajar mengenal c++ lebih dekat, dari membuat perhitungan sederhana sampai perhitungan tingkat lanjut (semoga).

   ## Install C++ Windows
   1. **Install Visual Studio Code:** Download and install VS Code from the <a href="https://code.visualstudio.com/">official website</a>
   2. **Install the C/C++ Extension:**
      1. Open VS Code.
      2. Go to the Extensions view (Ctrl+Shift+X).
      3. Search for "C++" and install the Microsoft C/C++ extension.
   3. **Install MinGW-w64 (GCC Compiler):**
      1. Download and install MSYS2 from the <a href="https://www.msys2.org/">MSYS2 website.</a>
      2. Follow the instructions to update packages and install the GCC compiler using the pacman command within the MSYS2 terminal (the specific commands are detailed in the <a href="https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/">freeCodeCamp guide).</a>
   4. **Add to PATH:** Add the path to the MinGW bin folder (e.g., C:\msys64\ucrt64\bin) to your Windows environment variables so VS Code can find the compiler. 
   5. Configure VS Code: Follow the <a href="https://code.visualstudio.com/docs/cpp/config-mingw">official VS Code documentation</a> to configure your project to use the MinGW compiler. 

## Run Program 
membuat kompilasi 
```
g++ nama_file -o nama_file_di_kompilasi
```
jalankan file kompilasi
```
./nama_file_di_kompilasi
```

atau bisa membaca <a href="https://code.visualstudio.com/docs/cpp/config-mingw">official VS Code documentation</a> 

## 📁 Absensi Mahasiswa
Sistem ini menggunakan penyimpanan file eksternal untuk menyimpan data akun dan log kehadiran.

```cpp
// Menghasilkan timestamp otomatis untuk setiap absen
string ambilWaktu() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string waktu = dt;
    waktu.pop_back(); 
    return waktu;
}
 ```

setelah berhasil buat akun atau berhasil absen akan ada 2 file yaitu ```data_absensi.txt``` dan ```log_absensi.txt``` yang dibuat otomatis untuk menyimpan log absen dan data login.

## 📁 Konverter Mata Uang (IDR)
Mata uang yang bisa dikonversi
<table>

<tr>
   <td> IDR(16604)</td>
   <td> ke</td>
   <td> USD(1)</td>
</tr>
<tr>
   <td> IDR(19303)</td>
   <td> ke</td>
   <td> EUR(1)</td>
</tr>
<tr>
   <td> IDR(106)</td>
   <td> ke</td>
   <td> JPY(1)</td>
</tr>

</table>

selebihnya menyusul hehe..

## 📁 Pengolahan Nilai
malasss 