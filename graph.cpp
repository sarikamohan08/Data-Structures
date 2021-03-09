#include<stdio.h>
# define   v 5


void intit(int arr[][v]);
void addedge(int arr[][v],int i,int j);
void printedge(int adj[][v]);	

int main()
{
	int src,dest;
	int adj[v][v];
	intit(adj);
	addedge(adj,0,2);
	addedge(adj,0,3);
	addedge(adj,1,1);
	addedge(adj,1,4);
	addedge(adj,2,3);
	addedge(adj,4,3);
	printedge(adj);
	return 0;
}

void intit(int arr[v][v])
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			arr[i][j]=0;
		}
	}
}
void addedge(int arr[][v],int src,int dest)
{
   	arr[src][dest]=1;
}
void printedge(int arr[][v])
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf(" %d",arr[i][j]);
		}
		printf("\n");
	}
}

