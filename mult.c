
#include<stdio.h>
#define infinity 9999
int dist[10], parent[10]={0};
int n, cost[10][10], stages, slen[10];
int G[10][10];	
void UpdateNeighbours(int node )
{
	int i;
	for(i=0;i<n;i++)
	{
		if(G[node][i]!=0)
		{
			if( (dist[node]+G[node][i])<dist[i] )
			{
				dist[i] = dist[node]+G[node][i];
				parent[i] = node;
			}
		}
	}
}
void multistage()
{
	 int i,j,node;
	dist[0] = 0;  //Source
	for(i=0;i<stages-1;i++)
	{
		for(j=0;j<slen[i];j++)
		{
			node = cost[i][j];
			UpdateNeighbours(node); //Updates the dist value of neighbours of node
		}
	}
}

int main()
{
	
	int i,j;

	printf("Enter no. of vertices & stages: ");
	scanf("%d %d",&n,&stages);
	printf("\nEnter adjacency matrix: \n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);

	for(i=0;i<n;i++)
		dist[i]=infinity;
	
	cost[0][0] = 0;
	slen[0] = 1; 

	cost[stages-1][0] = n-1;
	slen[stages-1] = 1; 
	
	for(i=1;i<=stages;i++)
	{
		printf("\nEnter No. of Nodes for Stage %d:",i);
		scanf("%d",&slen[i]);
		printf("\nEnter Nodes for Stage %d:\n",i);		
		for(j=0;j<slen[i];j++)
			scanf("%d",&cost[i][j]);
	}
	multistage();
	printf("\nCost is: %d\n",dist[n-1]); 
	return 0;
}


Enter no. of vertices & stages: 7
4

Enter adjacency matrix:
0 1 2 7 0 0 0
0 0 0 0 3 6 0
0 0 0 0 4 10 0
0 0 0 0 0 3 0
0 0 0 0 0 0 8
0 0 0 0 0 0 2
0 0 0 0 0 0 0

Enter No. of Nodes for Stage 1:3

Enter Nodes for Stage 1:
1
2
3

Enter No. of Nodes for Stage 2:2

Enter Nodes for Stage 2:
4
5

Enter No. of Nodes for Stage 3:1

Enter Nodes for Stage 3:
6

Enter No. of Nodes for Stage 4:1

Enter Nodes for Stage 4:
7

Cost is: 9