#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
    int hasil; // dengan menggunakan tipe data integer
    char hurufAja; // dengan menggunakan tipe data karakter
    char nim[20]; // dengan menggunakan tipe data array karakter
    // nim tidak boleh lebih qdari 20 karakter 
    float nilaiAnda; // dengan menggunakan tipe data float

    /* Kode Format scanf() dan kegunaannya
    
    %c,Membaca sebuah karakter
    %s,Membaca sebuah string
    "%i, %d",Membaca sebuah bilangan bulat (integer)
    "%f, %e",Membaca sebuah bilangan pecahan (real)
    %o,Membaca sebuah bilangan oktal
    %x,Membaca sebuah bilangan heksadesimal
    %u,Membaca sebuah bilangan tak bertanda (unsigned)

    */
    printf("masukan sebuah bilangan : "); scanf("%d", &hasil);
    printf("masukan sebuah karakter : "); scanf(" %c", &hurufAja);
    printf("masukan NIM : "); scanf("%s", nim);
    printf("masukan nilai anda : "); scanf("%f", &nilaiAnda);

    printf("\nNilai Variabel yang anda masukkan adalah : \n");
    printf("Hasil : %d\n", hasil);
    printf("Huruf : %c\n", hurufAja);
    printf("NIM   : %s\n", nim);
    printf("Nilai : %f\n", nilaiAnda);

}
