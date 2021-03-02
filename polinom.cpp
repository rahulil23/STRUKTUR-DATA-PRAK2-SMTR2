#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

void awal()
{
cout <<("======================================");
cout <<("PROGRAM POLINOMIAL");
cout <<("======================================\n");

cout <<("Diketahui : ")<<endl;
cout <<("1. P1 = 6x^8 + 8x^7 + 5x^5 + x^3 + 15")<<endl;
cout <<("2. P2 = 3x^9 + 4x^7 + 3x^4 + 2x^3 + 2x^2 + 10")<<endl;
cout <<("3. P3 = x^2 + 5") <<endl;
cout <<("Operasi : ")<<endl;
cout <<("1. Penjumlahan")<<endl;
cout <<("2. Pengurangan")<<endl;
cout <<("3. Perkalian")<<endl;
cout <<("4. Turunan\n")<<endl;
}

float tambah (int P1[], int P2[], int x)
{
float hasil=0;
for(int i=0; i<10; i++)
hasil += (P1[i]+P2[i]) * (float) pow(x,i);
return hasil;
}

float kurang (int P1[], int P2[], int x)
{
float hasil=0;
for(int i=0; i<10; i++)
hasil += (P1[i]-P2[i]) * (float) pow(x,i);
return hasil;
}

float kali(int P1[], int P2[], int x)
{
float hasil=0;
for(int i=0; i<10; i++)
{
for(int j=0; j<10; j++)
hasil += P1[i] * P2[j] * (float) pow(x,(i+j));
}
return hasil;
}

float turun(int P1[], int x)
{
float hasil=0;
for(int i=0; i<10; i++)
hasil = hasil + P1[i] * i * (float) pow(x,i-1);
return hasil;
}
void pilihan()
{
int operasi, pil1, pil2, x;
float hasil, hasil2;
int P1[10] = {15,0,0,1,0,5,0,8,6,0};
int P2[10] = {10,0,2,2,3,0,0,4,0,3};
int P3[10] = {5,0,1,0,0,0,0,0,0,0};

do{
printf("Masukkan Jenis Operasi : ");
scanf("%d", &operasi);
} while(operasi>4 || operasi<1);

do{
printf("Pilih Polinomial Pertama : ");
scanf("%d", &pil1);
} while(pil1>3 || pil1<1);

do{
printf("Pilih Polinomial Kedua : ");
scanf("%d", &pil2);
} while(pil2>3 || pil2<1);

printf("Masukkan Nilai x : ");
scanf("%d", &x);

if(operasi==1) /* OPERASI PENJUMLAHAN */
{
switch(pil1)
{
case 1 :
switch(pil2)
{
case 1 :
hasil = tambah(P1,P1,x);
break;
case 2 :
hasil = tambah(P1,P2,x);
break;
case 3 :
hasil = tambah(P1,P3,x);
break;
}
break;
case 2 :
switch(pil2)
{
case 1 :
hasil = tambah(P2,P1,x);
break;
case 2 :
hasil = tambah(P2,P2,x);
break;
case 3 :
hasil = tambah(P2,P3,x);
break;
}
break;
case 3 :
switch(pil2)
{
case 1 :
hasil = tambah(P3,P1,x);
break;
case 2 :
hasil = tambah(P3,P2,x);
break;
case 3 :
hasil = tambah(P3,P3,x);
break;
}
break;
}
}
else if(operasi==2) /* OPERASI PENGURANGAN */
{
switch(pil1)
{
case 1 :
switch(pil2)
{
case 1 :
hasil = kurang(P1,P1,x);
break;
case 2 :
hasil = kurang(P1,P2,x);
break;
case 3 :
hasil = kurang(P1,P3,x);
break;
}
break;
case 2 :
switch(pil2)
{
case 1 :
hasil = kurang(P2,P1,x);
break;
case 2 :
hasil = kurang(P2,P2,x);
break;
case 3 :
hasil = kurang(P2,P3,x);
break;
}
break;
case 3 :
switch(pil2)
{
case 1 :
hasil = kurang(P3,P1,x);
break;
case 2 :
hasil = kurang(P3,P2,x);
break;
case 3 :
hasil = kurang(P3,P3,x);
break;
}
break;
}
}
else if(operasi==3) /* OPERASI PERKALIAN */
{
switch(pil1)
{
case 1 :
switch(pil2)
{
case 1 :
hasil = kali(P1,P1,x);
break;
case 2 :
hasil = kali(P1,P2,x);
break;
case 3 :
hasil = kali(P1,P3,x);
break;
}
break;
case 2 :
switch(pil2)
{
case 1 :
hasil = kali(P2,P1,x);
break;
case 2 :
hasil = kali(P2,P2,x);
break;
case 3 :
hasil = kali(P2,P3,x);
break;
}
break;
case 3 :
switch(pil2)
{
case 1 :
hasil = kali(P3,P1,x);
break;
case 2 :
hasil = kali(P3,P2,x);
break;
case 3 :
hasil = kali(P3,P3,x);
break;
}
break;
}
}

else /* OPERASI PENURUNAN */
{
switch(pil1)
{
case 1 :
hasil = turun(P1,x);
break;
case 2 :
hasil = turun(P2,x);
break;
case 3 :
hasil = turun(P3,x);
break;
}
switch(pil2)
{
case 1 :
hasil2 = turun(P1,x);
break;
case 2 :
hasil2 = turun(P2,x);
break;
case 3 :
hasil2 = turun(P3,x);
break;
}
}

if(operasi<4)
printf("Hasil = %8.2f\n\n", hasil);
else
{
printf("Hasil Pertama = %8.2f\n", hasil);
printf("Hasil Kedua = %8.2f\n\n", hasil2);
}
}

int main()
{
char lagi='y';

do{
system("cls");
awal();
pilihan();
printf("Apakah Mengulang (y/n) ? ");
fflush(stdin);
scanf("%c", &lagi);
}
while(lagi=='y' || lagi=='Y');
}

