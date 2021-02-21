#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define max 6

int px[max],py[max];
//void bubblesort(int[],int[],int n);
int cmpfunc(const void *a,const void *b);
void closestpair(int);

//int cmpfunc(const void *a,const void *b)
//{
//	return ((int)a- (int)b);	
//}

void bubblesort(int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(px[j] > px[j+1])
			{
				temp = px[j];
				px[j] = px[j+1];
				px[j+1] = temp;
			}
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(py[j] > py[j+1])
			{
				temp = py[j];
				py[j] = py[j+1];
				py[j+1] = temp;
			}
		}
	}
}
void closestpair(int n)
{
	bubblesort(6);
	int i,mid,j;
	//qsort(px,5,sizeof(px),cmpfunc);
	//qsort(py,5,sizeof(py),cmpfunc);
	printf("\n Sorted elements are \n");
	for(i=0;i<n;i++)
	{
		printf("|| X%d = %d || Y%d = %d ||\n",i+1,px[i],i+1,py[i]);
	}
	mid = n/2;
	int lx[mid+1],rx[mid+1];
	memcpy(lx,px,mid*sizeof(int));
	memcpy(rx,&px[mid],mid*sizeof(int));
	for(i=0;i<mid;i++)
	{
		printf("|| %d = %d ||\n",lx[i],rx[i]);
	}
}
  
int main()
{
	int size,i;
	for(i=0;i<6;i++)
	{
		printf("Enter the %d value for x y = ",i+1);
		scanf("%d %d",&px[i],&py[i]);
			
	} 
	size = (sizeof(px)/sizeof(px[0]));
	printf("\n No of points %d",size);
	closestpair(size);
	return 0;	
}
