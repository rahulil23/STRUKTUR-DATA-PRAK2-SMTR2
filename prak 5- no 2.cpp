#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5
typedef int Element;
typedef struct{
int head;
int tail;
Element data[MAX];
}Queue;
void initQueue(Queue *q)
{
(*q).head=(*q).tail=-1;
}
bool isEmpty(Queue q)
{
if(q.head==-1 && q.tail==-1)
return true;
else
return false;
}
bool isFull(Queue q)
{
if((q.head<q.tail && (q.tail-q.head)==MAX-1) ||
(q.head>q.tail && q.head-q.tail==1))
return true;
else
return false;
}
bool isOneElement(Queue q)
{
if(q.head==q.tail && q.head!=-1)
return true;
else
return false;
}
void Enqueue(Queue *q, Element data)
{
if(isFull(*q))
printf("Queue is Full!");
else{
if(isEmpty(*q)){
(*q).head=(*q).tail=0;
(*q).data[(*q).tail]=data;
}else{
if((*q).tail==MAX-1){
(*q).tail=0;
}else{
(*q).tail++;
}
(*q).data[(*q).tail]=data;
}
}
}
void Dequeue(Queue *q)
{
Element temp=(*q).data[(*q).head];
if(isEmpty(*q))
printf("Queue is empty!");
else{
if(isOneElement(*q)){
initQueue(q);
}else{
if((*q).head==MAX-1)
(*q).head=0;
else
(*q).head++;
}
printf("Elemen yang dihapus adalah %d",temp);
}
}
void displayQueue(Queue q)
{
int i;
if(isEmpty(q))
printf("Queue is empty!");
else{
if(q.head<=q.tail){
for(i=q.head;i<=q.tail;i++){
printf("%d ", q.data[i]);
}
}else{
for(i=q.head;i<=MAX-1;i++){
printf("%d ", q.data[i]);
}
for(i=0;i<=q.tail;i++){
printf("%d ", q.data[i]);
}
}
}
}
int main()
{
Queue q;
Element input, temp;
initQueue(&q);
do
{
system("cls");
puts("Menu ");
puts("1. Enqueue Element");
puts("2. Dequeue Element");
puts("3. Display Queue");
puts("Esc. Exit");
puts("Pilih : ");
switch(getch())
{
 case '1' : if(isFull(q))
printf("Queue is full!");
else{
do{
printf("Input Number of Integer: ");scanf("%d", &input);
}while(input==0);
Enqueue(&q, input);
}
break;
case '2' : Dequeue(&q);
break;
case '3' : displayQueue(q);
break;
}
}while(getch()!=27);
getch();
return 0;
}
