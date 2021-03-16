#include <iostream>
#include <conio.h>
#include <iomanip>
#define max 100

using namespace std;

typedef struct{
	//int data [max];
	string nama [max], nrp [max], nilai [max]; 
	int head, tail;
} Queue;

Queue antrian;

void create (){
	antrian.head = antrian.tail = -1;
}

bool IsEmpty (){
	if (antrian.tail == -1)
		return 1;
	else 
		return 0;
}

bool IsFull (){
	if (antrian.tail == max-1)
	return 1;
		else 
	return 0;
}

int Enqueue (string nama, string nrp, string nilai){
	if (IsEmpty() == 1){
		antrian.head = antrian.tail = 0;
		antrian.nrp [antrian.tail] = nrp;
		antrian.nama [antrian.tail] = nama;
		antrian.nilai [antrian.tail] = nilai;
		cout << "\t\tData telah dimasukkan" << endl;
		
	}else if (IsFull () == 0){
		antrian.tail++;
		antrian.nrp [antrian.tail] = nrp;	
		antrian.nama [antrian.tail] = nama;
		antrian.nilai [antrian.tail] = nilai;
		cout << "\t\tData telah dimasukkan" << endl;
	}
	return 0;
}

int Dequeue (){
	int i;
	if (IsEmpty ()) {
		cout << "\t\tAntrian Kosong";
		getch ();
		
	} else {
		cout << "\t\tNomor Antrian " << antrian.head+1 << endl;
		for (int i = antrian.head; i <= antrian.tail; i++ ){
			cout << "\t\tDengan Nama " << antrian.nama[i] << endl;
		}
		for (i = antrian.head; i<=antrian.tail-1; i++){
			antrian.nama [i] = antrian.nama[i+1];
			antrian.nrp [i] = antrian.nrp[i+1];
			antrian.nilai [i] = antrian.nilai[i+1];
		}
		antrian.tail--;
	}
	return 0;
}

void clear (){
	antrian.head = antrian.tail = -1;
	cout << "\t\tData telah di Format";
}

void tampil (string nama, string nrp, string nilai) {
	
	if (IsEmpty() == 0){
		
		cout << endl;
		cout << "\t\t ==============================================" << endl;
		cout << "\t\t|                 DATA MAHASISWA               |\t" << endl;
		cout << "\t\t|==============================================|" << endl;
		cout << "\t\t| No |    NRP     |      NAMA      |   NILAI   |" << endl;
		cout << "\t\t|==============================================|" << endl;
		for (int i = antrian.head; i <= antrian.tail; i++){
			cout << setw (19) << i+1 << setw (9)<<antrian.nrp[i]<<setw (18)<< antrian.nama[i] << setw (14) << antrian.nilai[i] << endl;
		cout << "\t\t ==============================================" << endl;	
		}
		
	}else {
			cout << "\t\tData Kosong";
			}
}

int main (){
	int x, a;
	int pil;
	string nama, nrp, nilai;
	
	a = 1;
	
	create();
	do {
		cout << endl;
		cout << "\t\t    PROGRAM DATA MAHASISWA DENGAN QUEUE  \t" << endl;
		cout << "\t\t ==============================================" << endl;
		cout << "\t\t|                 PILIHAN MENU                 |\t" << endl;
		cout << "\t\t|==============================================|" << endl;
		cout << "\t\t|1. Pemasukan data mahasiswa                   |" << endl;
		cout << "\t\t|2. Panggil / keluarkan data                   |" << endl;
		cout << "\t\t|3. cetak data                                 |" << endl;
		cout << "\t\t|4. Hapus data                                 |" << endl;
		cout << "\t\t|5. Exit                                       |" << endl;
		cout << "\t\t ==============================================" << endl;
		
		cout << "\t\tMasukkan Pilihan (1/2/3/4/5) : ";
		cin >> pil;
		
		switch (pil){
			
			case 1 :
				cout << "\t\tMasukkan NRP : " ;
				cin >> nrp;
				cout << "\t\tMasukkan Nama : " ;
				cin >> nama;
				cout << "\t\tMasukkan Nilai : " ;
				cin >> nilai;
				Enqueue (nama, nrp, nilai);
				break;
				
			case 2 :
				Dequeue ();
				break;
				
			case 3 :
				tampil (nama, nrp, nilai);
				break;
				
			case 4 : 
				clear ();
				break;				 
		}

	} while (pil != 5);
}
