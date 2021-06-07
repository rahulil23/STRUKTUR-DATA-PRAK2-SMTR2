#include <stdio.h>
#include <stdlib.h>
struct simpul{
int nomor;
char car[30];
char pemilik[30];
struct simpul *next;
struct simpul *prev;
};
struct simpul *head=NULL;
struct simpul *tail=NULL;
struct simpul *cek;
void display(){
cek=tail;
while(cek!=NULL){
printf("nomor plat : %d\n", cek->nomor);
printf("merk mobil: %s", cek->car);
printf("nama pemilik : %s\n", cek->pemilik);
cek=cek->prev;
}
}
void dlt(){
cek=tail;

int nmr;
if(cek==NULL){
return;
}
else{
printf("Hapus data parkir (Input berupa nomor mobil) : ");scanf("%d", &nmr);
if(cek->nomor == nmr){
if(tail==head){
head=NULL;
tail=NULL;
free(cek);
}
else{
tail=tail->prev;
tail->next=cek->next;
free(cek);
}
}
else{
while(cek!=NULL){
if(cek->nomor == nmr){
if(cek==head){
head=head->next;
head->prev=cek->prev;
free(cek);
return;
}
else{
cek->next->prev=cek->prev;
cek->prev->next=cek->next;
free(cek);
return;
}
}
cek=cek->prev;
}
}
}
}
void insert(){
static int i=0;
struct simpul *sementara=(struct simpul*)malloc(sizeof(struct simpul));
printf("nomor plat : ");scanf("%d", &sementara->nomor);
fflush(stdin);
printf("merk mobil : ", sementara->nomor);fgets(sementara->car, sizeof sementara->car,
stdin);
printf("pemilik mobil: ", sementara->nomor);fgets(sementara->pemilik, sizeof sementara->pemilik, stdin);
if(head==NULL&&tail==NULL){
sementara->next=NULL;
sementara->prev=NULL;
head=sementara;
tail=sementara;
}
else{
sementara->next=head;
sementara->prev=NULL;
head->prev=sementara;
head=sementara;
}
}
int main()
{
int pilihan;
do{
puts("Yuk dipilih");
puts("1.Tampil");
puts("2.Insert");
puts("3.Delete");
puts("4.Keluar");
printf("Pilihan : ");scanf("%d", &pilihan);
fflush(stdin);
switch(pilihan){
case 1 : display();
break;
case 2 : insert();
break;
case 3 : dlt();
break;
case 4 : break;
default : puts("salah!! coba lagi");
}
}while(pilihan!=4);
}
