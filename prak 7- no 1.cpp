#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int Data[MAX];
// Fungsi pertukaran bilangan
void Tukar (int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}
// Fungsi pengurutan penyisipan biner
void SelectionSort()
{
int i, j, k;
for(i=0; i<MAX-1;i++){
k = i;
for (j=i+1; j<MAX; j++)
if(Data[k] > Data[j])
k = j;
Tukar(&Data[i], &Data[k]);
}
}
int main()
{
int i;
srand(0);
// Membangkitkan bilangan acak
printf("DATA SEBELUM TERURUT");
for(i=0; i<MAX; i++)
{
Data[i] = (int) rand()/1000+1;
printf("\nData ke %d : %d ", i, Data[i]);
}
SelectionSort();
// Data setelah terurut
printf("\nDATA SETELAH TERURUT");
for(i=0; i<MAX; i++)
{
printf("\nData ke %d : %d ", i, Data[i]);
}
}
