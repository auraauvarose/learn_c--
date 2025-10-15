angka = 10
print(angka)

if angka > 5:
    print("Angka lebih besar dari 5")
else:
    print("Angka 5 atau lebih kecil")

# Fungsi input() selalu mengembalikan string, jadi kita perlu mengubahnya ke tipe data angka.

# --- Contoh 1: Input Bilangan Bulat (Integer) ---
try:
    # Meminta pengguna memasukkan umur dan langsung mengubahnya menjadi integer
    umur_str = input("Masukkan umur Anda: ")
    umur = int(umur_str)

    print(f"Tahun depan, umur Anda akan menjadi {umur + 1} tahun.")

    # Pengecekan sederhana seperti contoh C++ sebelumnya
    if umur % 2 == 0:
        print(f"Umur Anda ({umur}) adalah angka genap.")
    else:
        print(f"Umur Anda ({umur}) adalah angka ganjil.")

except ValueError:
    # Blok ini akan dijalankan jika pengguna memasukkan sesuatu yang bukan angka
    print("Error: Input tidak valid. Harap masukkan hanya angka.")

print("-" * 20)

# --- Contoh 2: Input Bilangan Desimal (Float) ---
try:
    # Meminta input tinggi badan dan mengubahnya menjadi float
    tinggi_str = input("Masukkan tinggi badan Anda (dalam meter, contoh: 1.75): ")
    tinggi = float(tinggi_str)

    print(f"Tinggi badan Anda adalah {tinggi} meter.")

except ValueError:
    print("Error: Input tidak valid. Harap masukkan angka yang benar.")
