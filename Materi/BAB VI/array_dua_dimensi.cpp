#include <iostream>
using namespace std;

void contoh_1() {
    int a,b;
    int angka[3][4] = {
        {11,22,33,44},
        {55,66,77,88},
        {99,110,121,132}
    };
    for(a = 0; a < 3; a++) {
        for(b = 0; b < 3; b++) {
            cout << "Index Angka [" << a << "][" << b << "] = " << angka[a][b] << endl;
        }
    }
}


void contoh_2() {
    char nama[2][3][20]={ {"park","Ooh","kim"}, {"Chanyeol","Sehun","JongIn"}, };
        cout<<endl<<nama[0][0]<<" "<<nama[1][0]<<endl; 
        cout<<nama[0][1]<<" "<<nama[1][1]<<endl; 
        cout<<nama[0][2]<<" "<<nama[1][2]<<endl;
}


int main() {
    contoh_1();
    contoh_2();
    return 0;
}