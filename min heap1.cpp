#include <stdio.h>
int delete1();
int array[50], n = 9;
void insert(int num, int i)
{
    int j;
    while (i > 0)
    {
        j =(i - 1)/2;
        if (num >= array[j])
        {
            array[i] = num;
            return;
        }
        array[i] = array[j];
        i = j;
    }
    array[0] = num;
}

void display(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int delete1()
{
    int i,temp;
    for(i =0;i<n-1;i++)
    {
        array[i]= array[i+1];
    }
}
int main()
{
   int arr[100],i,j;
	int size,ele;
	printf("enter array  size:");
	scanf("%d",&size);
	printf("enter elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
    while(j<size)
    {
        insert(arr[j],j);
        j=j+1;
    }
   	printf("enter delete element:");
   	scanf("%d",&ele);
    display(ele+1);
    delete1();
    display(ele-1);
    return 0;

}



