#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
    int jumlah;
    char huruf;
    char nim[10];
    float nilai;

    printf("masukan sebuah bilangan bulat: ");
    scanf("%d", &jumlah);

    printf("masukan sebuah karakter: ");
    scanf(" %c", &huruf);

    printf("masukan NIM: ");
    scanf("%s", nim);

    printf("masukan pecahan: ");
    scanf("%f", &nilai);

    // menampilkan hasil input
    printf("\nNilai Variabel yang anda masukkan adalah : \n");
    printf("Jumlah : %d\n", jumlah);
    printf("Huruf  : %c\n", huruf);
    printf("NIM    : %s\n", nim);
    printf("Nilai  : %f\n", nilai);

    return 0;

}