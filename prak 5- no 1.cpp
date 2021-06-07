#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct simpul DNode;
struct simpul{
int data;
DNode *next;
DNode *prev;
};
DNode *head=NULL, *tail=NULL, *baru;
void alokasi_Dnode(int x)
{
baru=(DNode *) malloc (sizeof(DNode));
if(baru==NULL){
printf("Alokasi gagal\n"); exit(1);
}
else{
baru->data=x;
baru->next=NULL;
baru->prev=NULL;
}
}
void cetak_headtail()
{
DNode *p=head;
while(p!=NULL){
printf("%d ",p->data);
p=p->next;
}
printf("\n");
}
void cetak_tailhead()
{
DNode *p=tail;
while(p!=NULL){
printf("%d ",p->data);
p=p->prev;
}
printf("\n");
}
void sisip_awal(){
baru->next=head;
head->prev=baru;
head=baru;
}
void sisip_akhir()
{
baru->prev=tail;
tail->next=baru;
tail=baru;
}
void sisip_setelah_simpul(int x){
DNode *after = head;
while (after->data!= x)
after = after->next;
baru->prev = after;
baru->next = after->next;
after->next->prev = baru;
after->next = baru;
}
void sisip_sebelum_simpul(int x){
DNode *before = head;
while (before->data!= x)
before = before->next;
baru->prev = before->prev;
baru->next = before;
before->prev->next = baru;
before->prev = baru;
}
void free_DNode(DNode *p)
{
free(p);
p=NULL;
}
void hapus_awal(){
DNode *hapus = head;
head->next->prev = NULL;
head = hapus->next;
free_DNode(hapus);
}
void hapus_akhir(){
DNode *hapus = tail;
tail->prev->next = NULL;
tail = hapus->prev;
free_DNode(hapus);
}
void hapus_tertentu(int x){
DNode *hapus = head;
while (hapus->data != x)
hapus = hapus->next;
hapus->prev->next = hapus->next;
hapus->next->prev = hapus->prev;
free_DNode(hapus);
}
main()
{
int pilih, dt,first, x;
char lagi='y';
alokasi_Dnode(10);
head=tail=baru;
printf("Head-tail : ");cetak_headtail();
printf("Tail-Head: ");cetak_tailhead();
printf("\n");
while(lagi=='y')
{
printf("1. Sisip awal\n");
printf("2. Sisip akhir\n");
printf("3. Sisip sebelum simpul tertentu\n");
printf("4. Sisip setelah simpul tertentu\n");
printf("5. Hapus awal\n");
printf("6. Hapus akhir\n");
printf("7. Hapus tengah\n");
printf("8. Cetak dari head ke tail\n");
printf("9. Cetak dari tail ke head\n");
printf("Pilihan : ");fflush(stdin);scanf("%d",&pilih);
switch(pilih){
case 1:
printf("Masukkan data: "),scanf("%d",&dt);
printf("\n");
alokasi_Dnode(dt);
sisip_awal();
break;
case 2:
printf("Masukkan data: "),scanf("%d",&dt);
printf("\n");
alokasi_Dnode(dt);
sisip_akhir();
break;
case 3:
printf("Masukkan data: "),scanf("%d",&dt);
alokasi_Dnode(dt);
printf("Ingin Menyisipkan data sebelum? "); scanf("%d",&x);
sisip_sebelum_simpul(x);
printf("\n");
break;
case 4:
printf("Masukkan data: "),scanf("%d",&dt);
alokasi_Dnode(dt);
printf("Ingin Menyisipkan data setelah? "); scanf("%d",&x);
sisip_setelah_simpul(x);
printf("\n");
break;
case 5 :
hapus_awal();printf("\n");
break;
case 6:
hapus_akhir();printf("\n");
break;
case 7:
printf("Ingin menghapus data? "); scanf("%d",&x);
hapus_tertentu(x);
printf("\n");
break;
}
printf("Cetak head-tai; : ");cetak_headtail();
printf("Cetak tail-head : ");cetak_tailhead();
printf("lagi[y/t]? ");fflush(stdin);scanf("%c",&lagi);
printf("\n");
}
}
