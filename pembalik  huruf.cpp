//Nama    	: Dewi Nur Arifah
//NIM 		: 20051397079
//KELAS 	: 2020-A
// (1) ARRAY

#include <iostream>
using namespace std;

int main(){
	cout << "PROGRAM ARRAY MEMBALIK HURUF" << endl;
	cout << "============================" << endl;
	char a[6] = {'p', 'e', 'n', 's', 'i', 't'};
	int i, j;
	
	cout << "--Kata sebelum dibalik : --"<< endl;
	for (i=0; i<6; i++){
		cout << a [i];	
	}
	cout << "\n\n";
	cout << "--kata setelah dibalik : --"<< endl;
	for (j=6; j>=0; j--){
		cout << a [j];
	}
	return 0;
}
