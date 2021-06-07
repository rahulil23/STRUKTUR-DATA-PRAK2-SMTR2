#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct simpul{
char judul[30];
char nama[30];
char penerbit[30];
struct simpul *next;
struct simpul *prev;
};
struct simpul *head=NULL;
struct simpul *tail=NULL;
struct simpul *cek;
void display(){
cek=tail;
while(cek!=NULL){
printf("Judul buku : %s", cek->judul);
printf("Nama pengarang : %s", cek->nama);
printf("Penerbit buku : %s\n", cek->penerbit);
cek=cek->prev;
}
}
void dlt(){
cek=tail;
char title[30];
if(cek==NULL){
return;
}
else{
printf("Hapus data buku (Input berupa judul buku) : ");fgets(title, sizeof title, stdin);
if(strcmpi(cek->judul, title)==0){
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
if(strcmpi(cek->judul, title)==0){
if(cek==head){
head=head->next;
head->prev=cek->prev;
free(cek);
return;
}
else{

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
printf("judul buku : ");fgets(sementara->judul, sizeof sementara->judul, stdin);
printf("nama pengarang : ", sementara->judul);fgets(sementara->nama, sizeof sementara->nama, stdin);
printf("penerbit : ", sementara->judul);fgets(sementara->penerbit, sizeof sementara->penerbit, stdin);
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
