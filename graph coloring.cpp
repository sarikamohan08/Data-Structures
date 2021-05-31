#include<stdio.h>

int m_color, n;
int c=0;
int count=0;
int graph[50][50];
int x[50];

void nextValue(int s);
void GraphColoring(int s);
int  main()
{

 int i, j;
 int temp;
 printf("\nEnter the number of nodes: " );
 scanf("%d", &n);
 printf("\nEnter Adjacency Matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d", &graph[i][j]);
  }
 }
 printf("\nPossible Solutions are\n");
 for(m_color=1;m_color<=n;m_color++)
 {
  if(c==1)
  {
	printf("no");
   break;
  }
  GraphColoring(1);
 }
printf("\nThe chromatic number is %d", m_color-1);
printf("\nThe total number of solutions is %d", count);
 return 0;

}

void GraphColoring(int s)
{
 int i;
 while(1)
 {
  nextValue(s);
  if(x[s]==0)
  {
   return;
  }
 if(s==n)
 {
  c=1;
  for(i=1;i<=n;i++)
  {
   printf("%d ", x[i]);
  }
  count++;
  printf("\n");
 }
 else
  GraphColoring(s+1);
 }

}
void nextValue(int s)
{
 int j;
 while(1)
 {
  x[s]=(x[s]+1)%(m_color+1);
  if(x[s]==0)
  {
   return;
  }
  for(j=1;j<=n;j++)
  {
   if(graph[s][j]==1&&x[s]==x[j])
    break;
  }
  if(j==(n+1))
  {
   return;
  }
 }
}


