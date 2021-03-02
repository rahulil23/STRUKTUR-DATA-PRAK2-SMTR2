#include <iostream>
#include <string.h>
using namespace std;

int main (){
    char kata [50];
    int i, n;

    cout << "===========================================" << endl;
    cout << "\t\t STACK \t" << endl;
    cout << "-PROGRAM MENGECEK KATA PALINDROM ATAU BUKAN-" << endl;
    cout << "=========================================== \n" << endl;
    cout << "Masukkan kata : ";
    cin >> kata;

    n = strlen(kata);
    for (i=0; i<n; i++){

        if (kata[i] != kata[n-1-i]){
        i = n;
        cout << "Kata tersebut bukan palindrom" << endl;
        
            } else {
               i = n;
               cout << "Kata tersebut adalah palindrom" << endl;

       }
    } 
}


