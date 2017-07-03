#include<stdio.h>	
#define infinity 9999
int d[10],cost[10][10];
int n;
void bellman()
{
	int i,v,k,u;
	int source=1;
	d[source]=0;
	for(k=1;k<n-1;k++)  //iterate each edge n-1 times
	{
		for(i=1;i<=n;i++)
		{
			u=i;
			for(v=1;v<=n;v++)
			{
				if( d[v] > (d[u]+cost[u][v]) )
					d[v] = (d[u]+cost[u][v]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
	printf("edge    distance");
		printf("%d ",i);
		printf("%d\n",d[i]);
	}
}
int main()
{
	int i,j;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter adjacency matrix: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=infinity;
		}
	}

	for(i=1;i<=n;i++)
		d[i]=infinity;
	
	printf("\n");
	bellman( );
	
	return 0;
}

enter the number of nodes
5
Enter adjacency matrix:
0 10 0 5 0
0 0 1 2 0
0 0 0 0 4
0 3 9 0 2
7 0 6 0 0

1 0
2 8
3 9
4 5
5 7
