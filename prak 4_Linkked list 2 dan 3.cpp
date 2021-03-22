#include <iostream>
#include <conio.h>
using namespace std;
struct node {
	char nama[200],alamat[100];
	double ip;
	int nrp;
	node *next;
};
node *pos;
int pilihan = 0;
class linkedlist{
	private:
		node *a;
	public :
		linkedlist(){
			a = NULL;
		}
	void TambahAwal(){
		node *n;  
		n = new node;


cout<<"========================================:"<<endl;
cout << "Masukkan Nama\t: ";
cin >> n->nama;
cout << "Masukkan Nrp\t: ";
cin >> n->nrp;
cout << "Masukkan Alamat\t: ";
cin >> n->alamat;
cout << "Masukkan IP\t: ";
cin >> n->ip;
n->next = NULL;
	if(a == NULL)
	{
		a=n;
		a->next = NULL;
	}
	else
 	{
 		n->next = a;
 		a = n;
 	}
}
void TambahTengah()
{
 node *n, *Help;
 int pos;
 if(a != NULL)
 {
 cout<<"Akan disisip setelah Data Ke : ";
 cin>>pos;
 Help=a;
 n = new node;
 for(int i=0;i<pos;i++) {
 if(Help->next != NULL)
	 Help=Help->next;
 else
 break;
 }
 cout <<
"============================================ "<<endl;
 cout << "Masukkan Nama\t: ";
 cin >> n->nama;
 cout << "Masukkan Nrp\t: ";
 cin >> n->nrp;
 cout << "Masukkan Alamat\t: ";
 cin >> n->alamat;
 cout << "Masukkan Ip\t: ";
 cin >> n->ip;
 n->next=Help->next;
 Help->next=n;
 }
 else
 	{
 	cout<<"Belum ada data, silahkan masukkan datanya dulu...\n";
 	getch();
 	}
}
void HapusTengah()
{
 int Jumlahdata,p,poshapus;
 node *hapus, *bantu;
 if(a != NULL)
 	{
 		cout<<" Akan dihapus pada data ke : ";
 		cin>>p;
 		Jumlahdata=1;
 		bantu=a;
	while(bantu->next != NULL)
 	{
 		bantu=bantu->next;
 		Jumlahdata++;
 	}
 if((p<1)||(p>Jumlahdata))
 	{
 		cout<<"Belum ada data, silahkan masukkan datanya dulu...\n";
	}
 else
 	{
 		bantu=a;
 		poshapus=1;
 while(poshapus<(p-1))
 	{
 		bantu=bantu->next;
 		poshapus++;
 	}
 		hapus=bantu->next;
 		bantu->next=hapus->next;
 		delete hapus;
 	}
 }
 else
 	cout<<"Tidak ada Data"<<endl;
 getch();
}
void RataRata() {
node *Jumlah = a;
float a;
float hasil = 0;
while (Jumlah!= NULL){
a++;
hasil = hasil+Jumlah ->ip;
Jumlah =Jumlah ->next;
 }
 cout<<hasil/a<<endl;
}
void Tampilkan()
{
 node *DataAwal;
 DataAwal = a;
 cout << endl;
 if (DataAwal == NULL)
 cout << "Data Belum Ada" << endl;
 else
 {
 while (DataAwal != NULL)
 {
 cout << "Nama\t: " << DataAwal->nama <<endl;
 cout << "NRP\t: " << DataAwal->nrp <<endl;
 cout << "IP\t: " << DataAwal->ip <<endl;
 cout << "Alamat\t: " << DataAwal->alamat;
 if (DataAwal == pos)
 cout << " Posisi node";
 cout << endl;
 DataAwal = DataAwal->next;
 }
 cout << "Akhir dari List" << endl;
 }
}
};
void Menu(){
linkedlist l;
 int a;
 do
 {
l.Tampilkan();
 cout << endl;
 cout << "============================================="<<endl;
 cout << "============PROGRAM DATA MAHASISWA==========="<<endl;
 cout << "============================================="<<endl;
 cout << "Menu : " << endl;
 cout << "1. Masukkan Data" << endl;
 cout << "2. Sisipkan Data di posisi tertentu"<< endl;
 cout << "3. Hapus Data di posisi tertentu" << endl;
 cout << "4. Nilai Rata - Rata" << endl;
 cout << endl << " Pilihan : ";
 cin >> pilihan;
if(pilihan==1){
	l.TambahAwal();
}
else if(pilihan==2){
	l.TambahTengah();
}
else if(pilihan==3){
	l.HapusTengah();
}
else if(pilihan==4){
	l.RataRata();
}
else{
	 cout<<"Pilihan anda tidak ada"<<endl;}

 }
while (pilihan != 0);
}
int main(){
Menu();

}


















	
	
	
	
	
	
	
	
	
	
