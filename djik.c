#include<stdio.h>
#define infinity 9999
int d[10];int cost[10][10];
int short1[10];
int source,n;
int mindist(int d[10],int short1[10])
{
   // Initialize min value
   int min =infinity, min_index;
  
   for (int v = 1; v <=n; v++)
     if (short1[v] == 0 && d[v] <= min)
         min = d[v], min_index = v;
  
   return min_index;
}
int printSolution()
{
   printf("Vertex   Distance from Source\n");
   for (int i = 1; i <=n; i++)
      printf("%d \t\t %d\n", i, d[i]);
}
void djikstra(int n)
{
	int count;
	for(count=1;count<n;count++)
	{
		int u = mindist(d,short1);
		short1[u]=1;
		for(int v=1;v<=n;v++)
		{
			
			if (!short1[v] && cost[u][v] && d[u] !=infinity
                                       && d[u]+cost[u][v] < d[v])
            		d[v] = d[u] + cost[u][v];
		}
	}
	printSolution();
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
	printf("enter the source node:\n");
	scanf("%d",&source);
	
	printf("\n");
	for(i=1;i<=n;i++)
	{
		d[i]=infinity;
		short1[i]=0;
	}
	d[source]=0;
	djikstra(n);
	return 0;
}
