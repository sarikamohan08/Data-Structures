
#include<stdio.h>
#define aathi 100
#define max 1000

int t=-1,check[aathi],q=-1,track[aathi][2];

void tracking(int vertex1,int vertex2)
{
	int i, prev_vertex=0,condition =1; 
	for(i=0;i<=q;i++)
	{
		if(track[i][1] == vertex2)
		{
			prev_vertex = i;
			condition = 0;
			break;
		}
	}
	if(condition == 0)
	{
		track[prev_vertex][0] = vertex1;
	}
	else
	{
		q=q+1;
		track[q][0]=vertex1;
		track[q][1]=vertex2;	
	}
	
}

void push(int vertex)
{
	t = t+1;
	check[t]=vertex;
}

int checking(int vertex)
{
	int i,condition=1;
	for(i=0;i<=t;i++)
	{
		if(check[i] == vertex)
		{
			condition = 0;
			break;
		}
			
	}
	return condition;
}

int main()
{
	int vertices,i,j;
	//Getting the vertices from the user
	printf("Enter the total number of vertices\n(Make sure that you are counting from 0 th vertex to n th vertex): \n");
	scanf("%d",&vertices);
	int adj[vertices][vertices];
	//Making all the elements of the adjacency matrix as 0
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<vertices;j++)
		{
			adj[i][j]=0;
		}	
	}
	//Getting the weight between two vertices
	int vertex1, vertex2, weight, terminate=1;
	while(terminate == 1)
	{
		printf("Enter the vertices and distance between them: \n");
		scanf("%d %d %d",&vertex1,&vertex2,&weight);
		adj[vertex1][vertex2]=weight;
		adj[vertex2][vertex1]=weight;
		printf("Enter 0--Terminate or 1--Continue: ");
		scanf("%d",&terminate);
		printf("\n");
	}
	//printing the matrix
	printf("The adjacency matrix:\n");
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<vertices;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	int close=1;
	while(close==1)
	{
		t=-1;
		q=-1;
		//Declaring the distance matrix
		int distance[vertices];
		for(i=0;i<vertices;i++)
		{
			distance[i]=max;
		}
		//Getting the source and destination
		int source,destination;
		printf("Enter the source and destination: ");
		scanf("%d %d",&source, &destination);
		//Declaring the weight of source as 0
		distance[source] = 0;
		//Getting the shortest path
		int temp_vertex, temp_distance, new_distance;
		while(t != vertices-1)
		{
			temp_distance=max;
			//To find the shortest distance item.
			for(i=0;i<vertices;i++)
			{
				if(checking(i) == 1)
				{
					if(distance[i]<temp_distance)
					{
						temp_vertex = i;
						temp_distance = distance[i];
					}
				}
			}
			//Pushing the shortest distance item into the check array
			push(temp_vertex);
			for(i=0;i<vertices;i++)
			{
				if(checking(i) == 1)
				{
					if(adj[temp_vertex][i] != 0)
					{
						new_distance = distance[temp_vertex] + adj[temp_vertex][i];
						if(new_distance < distance[i])
						{
							distance[i] = new_distance;
							tracking(temp_vertex,i);
						}
					}
				}	
			}	
		}
		printf("The shortest distance between %d and %d is: %d",source, destination, distance[destination]);
		printf("\n");
		int a=-1,b=destination,path[aathi];
		for(i=0;i<=q;i++)
		{
			if(track[i][1] == b)
			{
				a=a+1;
				path[a] = b;
				b=track[i][0];
				i=-1;
			}
			if(b == source)
			{
				a=a+1;
				path[a]=b;
				break;
			}
		}
		printf("The path is via: ");
		for(i=a;i>=0;i--)
		{
			printf("%d",path[i]);
			if(i!=0)
				printf("--> ");			
		}
		printf("\n\n");
		printf("Do you want to continue? 1--Yes 0--No ");
		scanf("%d",&close);
	}
	printf("Bye Bye\n");
}	

