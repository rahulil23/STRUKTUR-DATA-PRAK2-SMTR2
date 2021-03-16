#include <iostream>
using namespace std;

int cqueue[5];
int front = -1, rear = -1, n=5;

void insertCQ(int val) {
   if ((front == 0 && rear == n-1) || (front == rear+1)) {
      cout<<"Queue Overflow \n";
      return;
   }
   if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      if (rear == n - 1)
      rear = 0;
      else
      rear = rear + 1;
   }
   cqueue[rear] = val ;
}
void deleteCQ() {
   if (front == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Data Yang Keluar Dari Antrian : "<<cqueue[front]<<endl;

   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == n - 1)
      front = 0;
      else
      front = front + 1;
   }
}
void displayCQ() {
   int f = front, r = rear;
   if (front == -1) {
      cout<<"Antrian kosong"<<endl;
      return;
   }
   cout<<"Antrian data :\n";
   if (f <= r) {
      while (f <= r){
         cout<<cqueue[f]<<" ";
         f++;
      }
   } else {
      while (f <= n - 1) {
         cout<<cqueue[f]<<" ";
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<cqueue[f]<<" ";
         f++;
      }
   }
   cout<<endl;
}
int main() {

   int ch, val;
   cout<<"______________________\n";
   cout<<"______________________\n";
   cout<<"||1)masukan         ||\n";
   cout<<"||2)keluarkan       ||\n";
   cout<<"||3)tampilkan       ||\n";
   cout<<"||4)keluar          ||\n";
   cout<<"______________________\n";
   cout<<"______________________\n";
   do {
      cout<<"Masukkan Pilihan : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"masukan data: "<<endl;
         cin>>val;
         insertCQ(val);
         break;

         case 2:
         deleteCQ();
         break;

         case 3:
         displayCQ();
         break;

         case 4:
         cout<<"keluar\n";
         break;
         default: cout<<"pilihan anda salah!\n";
      }
   } while(ch != 4);
   return 0;
}

