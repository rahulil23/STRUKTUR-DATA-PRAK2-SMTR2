#include <iostream>
using namespace std;

int ambil(int bil, int i){ 
	if (i == 1) { 
		return 1; 
	} 
	else if (bil % i == 0) { 
		return 1 + ambil(bil, --i); 
		} else { 
		return 0 + ambil(bil, --i); 
	} 
}
  
int cek(int bil){ 
	if (bil > 1) { 
		return (ambil(bil, bil) == 2);
	} 
	else 
		return false; 
}

int main(){
	
	int bil;
	cout<<"Masukan Bilangan Prima : ";
	cin>>bil;

	if (cek(bil)){
		cout<<"Bilangan Prima"<<endl;
	}else {
		cout<<"Bukan Bilangan Prima"<<endl;
	}
	return 0;
} 
