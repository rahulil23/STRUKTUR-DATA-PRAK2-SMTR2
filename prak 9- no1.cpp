#include <iostream>
#include <conio.h>
void Merge(int* ipA, int iEnd1, int iEnd2) {
    int i = 0;
    int j = iEnd1;
    int k = 0;
    int* ipTemp = new int[iEnd2];
    // Ambil setiap elemen terkecil berikutnya
    while (i < iEnd1 && j < iEnd2) {
        if (ipA[i] < ipA[j]) {
            ipTemp[k] = ipA[i];
            ++i;
        } else {
            ipTemp[k] = ipA[j];
            ++j;
        }
        ++k;
    }
    // Menyalin setiap elemen yang tersisa dari array 1
    while (i < iEnd1) {
        ipTemp[k] = ipA[i];
        ++i;
        ++k;
    }
    // Menyalin setiap elemen yang tersisa dari 2 Array
    while (j < iEnd2) {
        ipTemp[k] = ipA[j];
        ++j;
        ++k;
    }
    // Salin array bergabung kembali dengan aslinya
    for (int iIndex = 0; iIndex < iEnd2; ++iIndex) {
        ipA[iIndex] = ipTemp[iIndex];
    }
    delete [] ipTemp;
}
 
int main() {
    using namespace std;
    
    cout<< "\t MERGE SORT \n\n";
    int iaArray[] = { 9, 1, 2, 5, 6, 4};
    int iSize = 6;
 
    // Proses Pengurutan dengan Merge Sort
    for (int i = 1; i < iSize; i *= 2) {
        for (int j = 0; j < iSize - i; j += 2*i) {  //1. Kelompokan deret bilangan kedalam 2 bagian, 4 bagian, 8 bagian, ......dst   ? (2n)
            int iEnd2 = (2*i < iSize - j) ? 2*i : iSize - j;
            Merge(&(iaArray[j]), i, iEnd2);
        }
    }
    cout<<"Data yang akan di urut \t: 9, 1, 2, 5, 6, 4 \n";
    // Output dari Merge sort dalam array
        cout<<"Data yang telah di urut : ";
 
    for (int i = 0; i < iSize; i++){
        cout << iaArray[i] << " ";
    }
    cout << endl;
    getch();
    return 0;
}
