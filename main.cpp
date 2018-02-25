#include <stdio.h>
#include<math.h>
#include <stdlib.h>
void maopao(int a[],int n);
void xuanze(int a[],int n);
void charu(int a[],int n);
void kuai(int a[],int n,int left ,int right);
void shift(int h[],int n,int m);
void HeapSort(int p[],int n);
void  mergSort(int* a,int low,int mid,int high);
void  merg(int* a,int low,int high);
int  getLoopTimes(int num);
void sort2(int *p , int n , int loop);
int findMaxNum( int *p , int n);
void bucketSort3(int *p , int n);
int main()
{
  int m;
  printf("冒泡排序输入1\n选择排序输入2\n插入排序输入3\n快速排序输入4\n并归排序输入5\n基数排序输入6\n堆排序输入7\n");
  scanf("%d",&m);
  int i,j,t,n;
 printf("输入数字个数\n");
 scanf("%d",&n);
 int a[n];
 printf("输入各数字\n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
  switch(m)
  {
    case 1: maopao(a,n);break;
    case 2: xuanze(a,n);break;
    case 3: charu(a,n);break;
    case 4: kuai(a,n,0,n-1);break;
    case 5: merg(a,0,n-1);break;
    case 6: bucketSort3(a,n);;break;
    case 7: HeapSort(a,n);break;
  }
  for(i=0;i<n;i++)
 printf("%d ",a[i]);
 return 0;
}
void xuanze(int a[],int n)
{
   int i,j,k,t;
   for(i=0;i<n-1;i++)
   {
   k=i;
   for(j=i+1;j<n;j++)
     if(a[j]<a[k])k=j;
   if(i!=k)
   t=a[i],a[i]=a[k],a[k]=t;
   }
}
void maopao(int a[],int n)
{
 int i,j,t;
 for(j=0;j<n-1;j++)
  for(i=0;i<n-1-j;i++)
    if(a[i]>a[i+1])
      t=a[i],a[i]=a[i+1],a[i+1]=t;
 }


void kuai(int a[],int n,int left ,int right)
{
  int i,j,t;
  if(left<right)
  {
    i=left;
    j=right+1;
    while(1)
    {
      while(i+1<n&&a[++i]<a[left]);
      while(j-1>-1&&a[--j]>a[left]);
      if(i>=j)break;
      t=a[i],a[i]=a[j],a[j]=t;
     }
  t=a[left],a[left]=a[j],a[j]=t;
  kuai(a,n,left,j-1);
  kuai(a,n,j+1,right);
  }


}

void charu(int a[],int n)
{
  int i,k,t;
  for(i=0;i<n;i++)
  {
  t=a[i];
  k=i-1;
  while(t<a[k])
      {
       a[k+1]=a[k];
       k--;
       if(k==-1)break;
      }
  a[k+1]=t;
  }
}
void shift(int h[],int n,int m)
{
int j,tmp;
tmp = h[m];
j = 2 * (m + 1) - 1;
while (j <= n)
{
if ((j < n)&&(h[j] < h[j + 1]))
{
j += 1;
}
if (tmp < h[j])
{
h[m] = h[j];
m = j;
j = 2 * (m + 1) - 1;
}
else
{
j = n + 1;
}
}

h[m] = tmp;


}
void HeapSort(int p[],int n)
{

int i, k, t;
k = n/2;
for (i = k -1; i >= 0; i--)
{
shift(p,n-1,i);
}
for (i = n - 1; i >= 1; i--)
{
t = p[0];
p[0] = p[i];
p[i] = t;
shift(p,i-1,0);
}
}
void  mergSort(int* a,int low,int mid,int high)

{
int * p=new int[high+1];
int i=low;
int j=low;
int h=mid+1;

while(h<=high&&j<=mid)
{
if(a[j]<=a[h])
{
p[i]=a[j];
j++;
i++;
}
else
{
p[i]=a[h];
h++;
i++;
}
}
for(;j<=mid;j++,i++)
{
p[i]=a[j];
}
for(;h<=high;h++,i++)
{
p[i]=a[h];
}
for(i=low;i<=high;i++)
{
a[i]=p[i];
}


}
void  merg(int* a,int low,int high)
{

if(low<high)
{
int mid=(low+high)/2;
merg(a,low,mid);
merg(a,mid+1,high);
mergSort(a,low,mid,high);
}
}
int  getLoopTimes(int num)
{
int count = 1 ;
int temp = num/10;
while( temp != 0 ) {
count++;
temp = temp / 10;
}
return count;}
void sort2(int *p , int n , int loop)
{
int buckets[10][20] = {} ;
int tempNum = (int) pow(10 , loop-1);
int i , j ;
for( i = 0 ; i < n ; i++ ) {
int  row_index = (*(p+i) / tempNum) % 10;
for(j = 0 ; j < 20 ; j++) {
if(buckets[row_index][j] ==NULL) {
buckets[row_index ][j]  =  *(p+i) ;
break;
}
}
}
int k = 0 ;
for(i = 0 ; i < 10 ; i++) {
for(j = 0 ; j < 20 ; j++) {
if(buckets[i][j] != NULL) {
*(p + k ) = buckets[i][j] ;
buckets[i][j]=NULL;
k++;
}
}
}
}

int findMaxNum( int *p , int n)
{
int i ;
int max = 0;
for( i = 0 ; i < n ; i++) {
if(*(p+i) > max) {
max = *(p+i);
}
}
return max;
}
void bucketSort3(int *p , int n)
{
int maxNum = findMaxNum( p , n );
int loopTimes = getLoopTimes(maxNum);
int i ;
for( i = 1 ; i <= loopTimes ; i++) {
sort2(p , n , i );
}
}
