#include<stdio.h>
void min_Heapify(int *arr,int i,int size);
void Buildheap(int arr[],int size);
//void Heapify(int arr[],int index,int size);
void swap( int *a, int *b );


void Buildheap(int arr[],int size)
{
	int i;
	for(i=size/2;i>=0;i--)
	{
		min_Heapify(arr,i,size);
	}
}
void min_Heapify(int *arr,int i,int n)
{
    int j, temp;
    temp = arr[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && arr[j+1] < arr[j])
            j = j + 1;
        if (temp < arr[j])
            break;
        else if (temp >= arr[j])
        {
            arr[j/2] = arr[j];
            j = 2 * j;
        }
    }
    arr[j/2] = temp;
    return;
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
  	for(j=0; j<=size; j++) 
  {
    printf("%d\n",arr[j]);
  }
	return 0;
}


