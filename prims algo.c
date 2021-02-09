#include<stdio.h>
#include<string.h>

int prims();
void getgraph();
int edge_lowest();
void add_new_state(int edge_add);
void add_spanningtree(int edge_add);
void print();

typedef struct edge
{
	char v1[100];
	char v2[100];
	float weight;
}edge;
edge edges[100];
edge spanning_tree[100];
int no_of_edges=0;
int edge_spanning=0;


typedef struct state
{
	char name[100];
}state;
state covered[100];
int no_of_states=0;
void getgraph()
{
	FILE*input;
	input=fopen("input.txt","r");
	while(!feof(input))
	{
		fscanf(input,"%s %s %f",edges[no_of_edges].v1,edges[no_of_edges].v2,&edges[no_of_edges].weight);
		no_of_edges++;
	}
}
int edge_lowest()
{
	int b1,b2,i,j,k;
	int marked_edges[100],no_of_marked_edges=0;
	for(i=0;i<no_of_edges;i++)
	{
		b1=1,b2=1;
		for(j=0;j<no_of_states;j++)
		{
			if(strcmp(covered[j].name,edges[i].v1)==0)
			{
				b1=0;
			}
			if(strcmp(covered[j].name,edges[i].v2)==0)
			{
				b2=0;
			}
		}
		if((b1==0 && b2==1)||(b1==1 && b2==0))
		{
			marked_edges[no_of_marked_edges]=i;
			no_of_marked_edges++;
		}
	}
	if(no_of_marked_edges==0)
	{
		return -1;
	}
	float min=edges[marked_edges[0]].weight;
	int lowest_marked_edge=marked_edges[0];
	for(k=0;k<no_of_marked_edges;k++)
	{
		if(edges[marked_edges[k]].weight < min)
		{
			min=edges[marked_edges[k]].weight;
			lowest_marked_edge=marked_edges[k];
		}
		
	}
		return lowest_marked_edge;

}
void add_spanningtree(int edge_add)
{
	strcpy(spanning_tree[edge_spanning].v1,edges[edge_add].v1);
	strcpy(spanning_tree[edge_spanning].v2,edges[edge_add].v2);
	spanning_tree[edge_spanning].weight=edges[edge_add].weight;
	edge_spanning++;
}
void add_new_state(int edge_add)
{
	int b1=1,b2=1,i;
	for(i=0;i<no_of_states;i++)
	{
		if(strcmp(covered[i].name,edges[edge_add].v1)==0)
		{
			b1=0;
		}
		if(strcmp(covered[i].name,edges[edge_add].v2)==0)
		{
			b2=0;
		}
		if(b1==1)
		{
			strcpy(covered[no_of_states].name,edges[edge_add].v1);
			no_of_states++;	
		}
		if(b2==1)
		{
			strcpy(covered[no_of_states].name,edges[edge_add].v2);
			no_of_states++;	
		}	
	}
}
void print()
{
	int i;
	float sum=0.0;
	printf("\nour edges:\n");
	for(i=0;i<no_of_edges;i++)
	{
		printf("\n[%d] %s %s %0.2f",i,edges[i].v1,edges[i].v2,edges[i].weight);
	}	
	printf("\nspanning tree edges:");
	for(i=0;i<edge_spanning;i++)
	{
		
		printf("\n%s %s %0.2f",spanning_tree[i].v1,spanning_tree[i].v2,spanning_tree[i].weight);
	}
	for(i=0;i<edge_spanning;i++)
	{
		
		sum+=spanning_tree[i].weight;
	}
	printf("\nMINIMUM COST:%0.2f",sum);
}
int prims()
{
	int edge_add=edge_lowest();
	if(edge_add==-1)
	{
		return 0;
	}
	add_spanningtree(edge_add);
	add_new_state(edge_add);
	//print();
	prims();
	
}

int main()
{
	getgraph();
	strcpy(covered[no_of_states].name,edges[0].v1);
	no_of_states++;
	prims();
	print();
}
