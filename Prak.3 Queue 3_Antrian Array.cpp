#include <iostream>
#include <conio.h>
#include <iomanip>
#define max 10

using namespace std;

typedef struct{
	int data [max];
	int head;
	int tail;
} Queue;

Queue antrian;

void create (){
	antrian.head=antrian.tail=-1;
}

int IsEmpty () {
	if (antrian.tail == -1)
		return 1;
		else 
		return 0;
}

int IsFull () {
	if (antrian.tail == max-1)
		return 1;
		else 
		return 0;
}

void Enqueue (int data){
	system("cls");
	if(IsEmpty () == 1){
		
		antrian.head = antrian.tail = 0;
		antrian.data[antrian.tail] = data;
		cout << "--Nomor Plat Mobil " << antrian.data[antrian.tail] << " Masuk!-- \n";
		
	} else if (IsFull () == 0){
		antrian.tail++;
		antrian.data[antrian.tail] = data;
		
		cout << "--Nomor Plat Mobil " << antrian.data[antrian.tail] << " Masuk!--" << endl;
		
	} else if (IsFull ()== 1){
		cout << "Ruangan Penuh !" << endl;
		cout << data << "--Data tidak bisa masuk!--" << endl;
	}
}

void Dequeue (){
	system("cls");
	int i;
	int e = antrian.data[antrian.head];
	if (antrian.tail == -1){
		cout << "Tidak ada antrian .. antrian telah kosong" << endl;
	} else {
		for (i=antrian.head; i<=antrian.tail; i++){
			antrian.data[i] = antrian.data[i+1];
		}
		antrian.tail--;
		cout << "--Nomor Plat Mobil yang keluar lebih dulu " << e << "--" << endl;
	}
}

void clear (){
	system("cls");
	antrian.head = antrian.tail = -1;
	cout << "Antrian telah kosong " << endl;
	cout << "Data Nomor Plat -- clear" << endl;
}

void tampil(){
	system("cls");
	if (IsEmpty () == 0 ){
		cout << "Data Nomor Plat Mobil dalam Antrian : " << endl;
		
		for (int i=antrian.head; i<=antrian.tail; i++){
			cout << "{" << antrian.data[i] << "}" << endl;
		}
	}else {
		cout << "Data Antrian Kosong" << endl;
	}
}

int main (){
	int data, pil;
	create();
	system("color 74");
			cout << "PROGRAM SIMULASI TEMPAT PARKIR (MOBIL)" << endl;
			cout << endl;
			getch();
		
			cout << "\t\t\t\t PROGRAM SIMULASI TEMPAT PARKIR (MOBIL)" << endl;
		
	do {
		cout << endl;
		cout << "\t\t==========================================================================" << endl;
		cout << "\t\t\t                          PILIHAN                      \t" << endl;
		cout << "\t\t==========================================================================" << endl;
		cout << "\t\t||1.Memasukkan nomor plat mobil                                         ||" << endl;
		cout << "\t\t||2.Mengeluarkan nomor plat mobil / nomor paling depan keluar           ||" << endl;
		cout << "\t\t||3.Tampilkan Data Nomor Plat mobil                                     ||" << endl;
		cout << "\t\t||4.hapus                                                               ||" << endl;
		cout << "\t\t||5.keluar                                                              ||" << endl;
		cout << "\t\t==========================================================================" << endl;
		
		cout << "Masukkan Pilihan (1/2/3/4/5) : ";
		cin >> pil;

		switch (pil){
		case 1 :
		{
			cout << "\nMasukkan Nomor Plat: ";
			cin >> data;
			Enqueue(data);
			break;
		}
		case 2 :
		{
			cout << endl;
			Dequeue();
			break;
		}
		case 3 :
		{
			cout << endl;
			tampil();
			break;
		}
		case 4 :
		{
			cout << endl;
			clear();
			break;
			}
		}

	}
	while (pil != 5);
	
}
