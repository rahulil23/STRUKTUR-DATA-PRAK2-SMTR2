#include<iostream>
using namespace std;
int i;
int angka(int n )
{
    cout<<"MASUKKAN HURUF :";
    cin>>n;
     for (i=n; i<0; i++)
    {
        cout<<"Rekursi Dari N Ke 0 : "<<i;
        cout<<endl;
    }
    return n;
}

int main ()
{
    int n;
    int i;
    cout<<angka(i);
}
