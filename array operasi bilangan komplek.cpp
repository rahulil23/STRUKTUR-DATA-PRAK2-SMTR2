#include<iostream>

using namespace std;

struct bilangan {
	char r1;
	char r2;
	char i1;
	char i2;
};

bilangan bil;
int main(){
 char bilangan ;
 cout<<"====================================";
 cout<<"\n PROGRAM OPERASI BILANGAN KOMPLEKS ";
 cout<<"\n====================================\n\n";
 cout<<"Bilangan (a/b/c/d)" << endl;
 cout<<"Bilangan real 1 = "; cin>> bil.r1;
 cout<<"Bilangan imajiner 1 = "; cin>>bil.i1;
 cout<<endl;
 cout<<"Bilangan real 2 = "; cin>>bil.r2;
 cout<<"Bilangan imajiner 2 = "; cin>>bil.i2;
 cout<<"|-------------------------------------|" << endl;
cout<< "\n";

cout<<"--PENJUMLAHAN--"<<endl;
	
cout<<"("<<bil.r1<<"+"<<bil.i1<<"i) " << " + "<<"("<<bil.r2<<"+"<<bil.i2<<"i) = (" 
    <<bil.r1 << "+" << bil.r2 << ") + (" <<bil.i1 << "+" << bil.i2 << ")\i" << endl;
cout<< "\n \n";

cout << "--PENGURANGAN--" <<endl;
cout<<"("<<bil.r1<<"+"<<bil.i1<<"i) " << "-" << "(" <<bil.r2<< "+" <<bil.i2<<"i) = (" 
    <<bil.r1 << "-" << bil.r2 << ") + (" <<bil.i1 << "-" << bil.i2 <<")i"<< endl;
cout<< "\n \n";

cout<<"--PERKALIAN--"<<endl;
cout<<"("<<bil.r1<<"+"<<bil.i1<<"i) " << "*" << "(" <<bil.r2<<"+"<<bil.i2<<"i) = (" 
    <<bil.r1<<bil.r2<< "+" <<bil.i1<<bil.i2<<") + (" <<bil.r1<<bil.i2<<"+"<<bil.i1<<bil.r2 << ")i" << endl;
cout<< "\n \n";    

cout << "--PEMBAGIAN--" << endl;
cout << "("<<bil.r1<<"+"<<bil.i1<<"i) " << " / "<<"("<<bil.r2<<"+"<<bil.i2<<"i) = [(" 
    << bil.r1<<bil.r2<< "+" <<bil.i1<<bil.i2<<")/(" << bil.r1 <<  "^2+" << bil.i1 << "^2+"
    << ")] + [(" << bil.i1<<bil.r2 << "-" << bil.r1 << bil.i2 << ")/(" << bil.r2 << "^2" << bil.i2  
    << "^2)]i" << endl;

    return 0;
}
