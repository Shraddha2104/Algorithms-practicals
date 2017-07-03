#include<stdio.h>
#define infinity 9999

int cost[10][10],key[10],parent[10],n;
int minkey(int key[])
{
	int min=infinity,min_index;
	for(int i=1;i<=n-1;i++)
	{
		if(key[i]<min )
		{
			min=key[i];
			min_index=i;
		}
	}
return min_index;
}
int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;   //wrwr
		return 1;
	}
	return 0;
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
	parent[1]=-1;
	for(count=1;count<n;count++)
	{
		int u=minkey(key);
		
		for(int v=1;v<=n;v++)
		{
			u=find(u);
			v=find(v);
			if(uni(u,v))
			{
				mincost+=min;
			}
	}