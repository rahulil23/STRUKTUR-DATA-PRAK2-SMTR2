//Nama    	: Dewi Nur Arifah
//NIM 		: 20051397079
//KELAS 	: 2020-A
// (3) STACK

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#define MaxElemen 200 					//menentukan batas max elemen
using namespace std;

struct Tumpukan{
 	char Isi[MaxElemen];
   	int Atas;
} T;

//sub program PUSH berfungsi memasukkan elemen ke dalam STACK
void PUSH (char x){ 					
    if(T.Atas == MaxElemen){  			//untuk mengecek apakah stack sudah penuh
        cout << "Tumpukan Sudah Penuh";
        getch(); 
} else{
        T.Atas = T.Atas + 1;
        T.Isi[T.Atas] = x;
}
}

//sub program POP berfungsi mengambil elemen dari STACK
char POP(){
 		char hasil;
 if(T.Atas == 0){
    	cout<<"Tumpukan sudah kosong";
      		hasil = ' ';
   } else{
    		hasil = T.Isi[T.Atas];
      		T.Atas = T.Atas - 1;
   }
   return hasil;
}

//program utama
int main (){
     int I;       											// pencacah
     char Kalimat[MaxElemen];   							//kalimat yang akan dibalik
     system ("cls");
     T.Atas =0;  											// nilai awal tumpukan
     
     cout<<"===========================\n";
     cout<<"\t STACK \t \n";
     cout<<"-PROGRAM PEMBALIKAN KALIMAT- \n";
     cout<<"===========================\n\n";

     // Inputkan kalimat yang akan dibalik
     cout << "Masukkan kalimat : "; gets(Kalimat);
	 cout<< "\t ------------------------ \t";
	 cout << "\n \n";
	 
     cout<<"Kalimat asli \t \t : "<<Kalimat;

     //Mem-PUSH huruf dari kalimat ke dalam tumpukan
     for(I=0; I<strlen(Kalimat) ;I++){
      		PUSH(Kalimat[I]);
      }

      cout<<"\nKalimat setelah dibalik  : ";

      //Mem-POP sekaligus mencetak isi tumpukan sehingga diperoleh kalimat yang terbalik
      for (I=0; I<strlen(Kalimat) ;I++){
       		cout<<""<<POP();
      }
      
       getch();
       return 0;
    } 
