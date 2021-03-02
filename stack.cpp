#include <iostream>
#include <conio.h>
#define maxstack 5
using namespace std; 


struct STACK
{
      int top;
      float data[4];
};
float dta;


struct STACK stackbaru;


bool isfull()
{
      if(stackbaru.top == maxstack)
            return true;
      else
            return false;
}


bool isempty()
{
      if(stackbaru.top == -1)
            return true;
      else
            return false;
}


void push(float dta)
{
     if(isfull() == true) 
      {
            puts("Maaf, stack penuh");
      }
      else{
            stackbaru.top++;
            stackbaru.data[stackbaru.top]=dta;
      }
}


void pop()
{
      if(isempty() == true) 
      {
            cout<<"Data telah kosong!";
      }
      else
      {
            cout<<"Data yang terambil : " <<stackbaru.data[stackbaru.top]<<endl;
            stackbaru.top--;
      }
}


void print()
{
      printf("\nData yang terdapat dalam stack : \n");
      printf("--------------------------------\n");
      for(int i=0; i<=stackbaru.top; i++)
      {
            cout<<stackbaru.data[i]<<"    ";
      }
}


void clear()
{
      stackbaru.top = -1;
      printf("\nSekarang stack kosong");
}


int main()
{
      stackbaru.top = -1;
      
      char menu;
      char ulang;
      
      do
      {
            system("cls");
            printf("\t PROGRAM STACK\n");
            printf("\t===============\n");
            printf("Menu : ");
            puts("\n1. Pop stack");
            puts("2. Push stack");
            puts("3. Cetak");
            puts("4. Bersihkan stack");
            puts("5. Exit");
           
            cout<<"Menu pilihan Anda : ";
            cin>>menu;
           
            if(menu == '1')
            {
                  pop(); //panggil fungsi pop()
                  ulang = 'y';
                  getch();
            }
            else if(menu == '2')
            {
                  cout<<"\nTambah Data";
                  cout<<"\n-----------";
                  cout<<"\nData yang akan disimpan di stack : ";
                  cin>>dta;
                 push(dta); 
                  ulang = 'y';
            }
            else if(menu == '3')
            {
                  print(); 
                  cout<<"\n\nUlang ? (y/t)";
                  cin>>ulang;
            }
            else if(menu == '4')
            {
                  clear(); 
                  cout<<"\n\nUlang ? (y/t)";
                  cin>>ulang;
            }
            else if(menu == '5')
            {
                  exit(0); 
            }
       }while(ulang == 'Y' || ulang == 'y'); 
} 
