#include<stdio.h>
#define infinity 9999

int cost[10][10],key[10],parent[10],n;
int mst[10];

int minkey()
{
	int min=infinity,min_index;
	for(int i=1;i<=n;i++)
	{
		if(key[i]<min && mst[i]==0)
		{
		min=key[i];
		min_index=i;
		}
	}
return min_index;
}
int printmst()
{
   printf("Edge   Weight\n");
   for (int i = 2; i <=n; i++)
      printf("%d - %d    %d \n", parent[i], i,cost[i][parent[i]]);
}

int main()
{
	int i,j,count;
	printf("\nenter number of nodes:");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&cost[i][j]);
		
			
	}	
	
	printf("\n");
	for(i=1;i<=n;i++)
	{
		key[i]=infinity;
		mst[i]=0;
	}
	key[1]=0;
	parent[1]=-1;
	for(count=1;count<n;count++)
	{
		int u=minkey();
		mst[u]=1;
		for(int v=1;v<=n;v++)
		{
			if(cost[u][v] && mst[v]==0 && cost[u][v]<key[v])
			parent[v]=u, key[v] =cost[u][v];
		}
	}
printmst();
return 0;
}

