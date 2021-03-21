#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct edge 
{
  int u, v, w;
} edge;

typedef struct edge_list 
{
  edge data[MAX];
  int n;
} edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanning;

void kruskalAlgo();
int find_dup(int if_belongs[], int vertexno);
void Union(int if_belongs[], int c1, int c2);
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo() {
  int if_belongs[MAX], i, j, c1, c2;
  elist.n = 0;

  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++) 
    {
      if (Graph[i][j] != 0) 
      {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }

  sort();

  for (i = 0; i < n; i++)
    if_belongs[i] = i;

  spanning.n = 0;

  for (i = 0; i < elist.n; i++) 
  {
    c1 = find_dup(if_belongs, elist.data[i].u);
    c2 = find_dup(if_belongs, elist.data[i].v);

    if (c1 != c2) 
    {
      spanning.data[spanning.n] = elist.data[i];
      spanning.n = spanning.n + 1;
      Union(if_belongs, c1, c2);
    }
  }
}

int find_dup(int if_belongs[], int vertexno) 
{
  return (if_belongs[vertexno]);
}

void Union(int if_belongs[], int c1, int c2) 
{
  int i;

  for (i = 0; i < n; i++)
    if (if_belongs[i] == c2)
      if_belongs[i] = c1;
}

// Sorting 
void sort() 
{
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) 
      {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

// Printing the result
void print() 
{
  int i, cost = 0;
  printf("Vertices with cost:");
  for (i = 0; i < spanning.n; i++) 
  {
    printf("\n%d - %d : %d", spanning.data[i].u+1, spanning.data[i].v+1, spanning.data[i].w);
    cost = cost + spanning.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}

int main() {
  int i, j, total_cost;

  n = 3;
  int houses[][2] = { { 3, 12 }, { -2, 5 }, 
                        { -4, 1}};
  for(i=0;i<5;i++)
    {
	for(j=0;j<5;j++)
	{
		int p = abs(houses[i][0] - houses[j][0]);
 
        p = p + abs(houses[i][1] - houses[j][1]);
		
		Graph[i][j]=p;
	}
    }

  kruskalAlgo();
  print();
}
