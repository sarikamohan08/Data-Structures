#include<stdio.h>

void Buildheap(int arr[],int size);
void Heapify(int arr[],int index,int size);
void swap( int *a, int *b );


void Buildheap(int arr[],int size)
{
	int i;
	for(i=size/2;i>=0;i--)
	{
		Heapify(arr,i,size);
	}
}
void Heapify(int arr[],int index,int size)
{
	int left=2*index+1;
	int right=left+1;
	int max=index;
	if(left<=size&&arr[left]>arr[max])
	{
		max=left;
	}
	if(right<=size&&arr[right]>arr[max])
	{
		max=right;
	}
	if(index!=max)
	{
		swap(&arr[max],&arr[index]);
		Heapify(arr,max,size);
	}
}
void swap( int *a, int *b ) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}
int main()
{
	int arr[100],i,j;
	int size;
	printf("enter array  size:");
	scanf("%d",&size);
	printf("enter elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	Buildheap(arr,size);
	printf("\nthe elements are:");
  	for(j=0; j<=size; j++) 
 	 {
    printf("%d\n",arr[j]);
	  }
	return 0;
}


