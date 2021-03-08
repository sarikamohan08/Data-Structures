#include<stdio.h>
int BinarySearch(int arr[],int start, int end ,int key)
{
	int mid;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]<key)
		{
			return BinarySearch(arr,mid+1,end,key);
		}
		else
		{
	
			return BinarySearch(arr,start,mid-1,key);
		}
	}
	return 0;
}
int main()
{
	int arr[100],size, key,i,r,ind;
	printf("enter size:");
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter key to be searched:");
	scanf("%d",&key);
	ind=BinarySearch(arr,0,size-1,key);
	if(ind==1)
	{
		printf("element %d is found at the position %d",key,ind);
	}
	else
	{
		printf("element %d is found is not found",key);
	}
	return 0;
}
