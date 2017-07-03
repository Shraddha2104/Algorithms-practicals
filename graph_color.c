#include<stdio.h>
int g[10][10],x[10],n,m;
int get_node_color(int k)
{
	int j;
	while(true)
	{
		x[k]=(x[k]+1)%(m+1);
		 
		if(x[k]==0)
			return x[k];
		
		for( j=1;j<=n;j++)
		{
			if(g[k][j]!=0 && x[k]==x[j])
				break;
		}
		if(j==n+1)
			return x[k];
	}
}
int g_color(int k)
{
	while(true)
	{
		x[k]=get_node_color(k);
		if(x[k]==0)
			return x[k];
		else if(k==n)
		{
			for(int i=1;i<=n;i++)
                 printf("vertex %d = color No. %d\t",i,x[i]);
			 
			printf("\n");
		}
		else
			g_color(k+1);
	}
}			
	
	
int main()
{
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	m=n-1;
	printf("enter the boolean adjacency matrix\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	g_color(1);
	return 0;
}
enter the number of nodes
4
enter the boolean adjacency matrix
0 1 0 1
1 0 1 1
0 1 0 1
1 1 1 0
vertex 1 = color No. 1  vertex 2 = color No. 2  vertex 3 = color No. 1  vertex 4 = color No. 3
vertex 1 = color No. 1  vertex 2 = color No. 3  vertex 3 = color No. 1  vertex 4 = color No. 2
vertex 1 = color No. 2  vertex 2 = color No. 1  vertex 3 = color No. 2  vertex 4 = color No. 3
vertex 1 = color No. 2  vertex 2 = color No. 3  vertex 3 = color No. 2  vertex 4 = color No. 1
vertex 1 = color No. 3  vertex 2 = color No. 1  vertex 3 = color No. 3  vertex 4 = color No. 2
vertex 1 = color No. 3  vertex 2 = color No. 2  vertex 3 = color No. 3  vertex 4 = color No. 1
