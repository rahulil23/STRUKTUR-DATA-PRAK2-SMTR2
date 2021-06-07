#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct simpul MNode;
struct simpul{
int NRP;
char Nama[30];
int Kelas;
MNode *next;
};
MNode *baru,*head=NULL;
void alokasi_simpul_mhs(int nrp,int kelas,char nama[])
{
baru=(MNode *)malloc(sizeof(MNode));
if(baru==NULL){
printf("Alokasi gagal\n");
exit(1);
}else{
baru->NRP=nrp;
strcpy(baru->Nama,nama);
baru->Kelas=kelas;
baru->next=NULL;
}
}
void cetak(){
MNode *p=head;
printf("NRP\tNAMA\tKELAS\n");
while(p!=NULL){
printf("%d\t%s\t%d\n",p->NRP,p->Nama,p->Kelas);
p=p->next;
}
printf("\n");
}
sisip_awal(){
baru->next=head;
head=baru;
}
sisip_akhir(){
MNode *tail=head;
while(tail->next != NULL){
tail = tail->next;
}
tail->next = baru;
}
//Operasi hapus
void free_Node(MNode *p)
{
free(p);
p=NULL;
}
hapus_simpul_awal(){
MNode *hapus = head;
head = hapus->next;
free_Node(hapus);
}
void hapus(int x)
{
MNode *hapus=head, *before=head;
if(hapus->NRP==x){
hapus_simpul_awal();
}
else{
while(hapus!=NULL && hapus->NRP!=x){
before=hapus;
hapus=hapus->next;
}
if(hapus==NULL){
printf("Simpul tidak tersedia\n");
}
else{
before->next=hapus->next;
free_Node(hapus);
}
}
}
void sisip_urut()
{
MNode *before=head;
if(head==NULL){
head=baru;
}
else if(baru->NRP<head->NRP){
sisip_awal();
}
else{
while(before!=NULL && baru->NRP > before->NRP){
before=before->next;
}
if(before==NULL){
sisip_akhir();
}
else if(baru->NRP==before->NRP){
printf("\nDuplikat data\n\n");
}
}
}
//fungsi sisip sebelum simpul tertentu
sisip_sebelum_simpul_tertentu(int x){
MNode *before = head;
while(before->next->NRP != x)
before = before->next;
baru->next = before->next;
before->next = baru;
}
//x=nrp,y=nama,k=kelas
update_data(int x,char y,int k){
MNode *p=head;
if(p==NULL)
printf("\nTidak dapat mengedit\n");
while(p->next!=NULL){
if(p->NRP==x){
}else{
printf("\nPrefix NRP tidak ditemukan\n");
exit(1);//out program
}
}
}
main() {
 int nrp;
 char nama[30];
 int kelas;
 int menu;
 char lagi='y';
printf("DOUBLE LINKED LIST:\n");
 do{
printf("\n1.Sisip Urut\n");
printf("2.hapus Node(Prefix NRP)\n");
printf("3.Edit Data (Prefix NRP)");
printf("\nMenu:");scanf("%d",&menu);fflush(stdin);
switch(menu){
case 1:printf("Nama:");gets(nama);
printf("NRP:");scanf("%d",&nrp);
 printf("kelas:");scanf("%d",&kelas);

 alokasi_simpul_mhs(nrp,kelas,nama);
 sisip_urut();
 break;
case 2:printf("Mana yang akan di hapus(NRP):");
scanf("%d",&nrp);
printf("\n");
hapus(nrp);
break;
case 3: printf("Nama Baru:");gets(nama);
printf("Kelas Baru:");scanf("%d",&kelas);
printf("Mana yang akan di edit(NRP):");
scanf("%d",&nrp);
break;
 }
 cetak();
 }while(lagi=='y');
}
