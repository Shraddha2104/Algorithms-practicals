#include <stdio.h>
int wt[10],val[10],n,M;
int max(int a, int b)
{ 
    return (a > b)? a : b; 
}
int knapsack()
{
	int knp[n+1][M+1],i,w;
	 for (i = 0; i <= n; i++)
    {
	    for (w = 0; w <= M; w++)
	    {
		    if (i==0 || w==0)
			    knp[i][w] = 0;
		    else if (wt[i-1] <= w)
			    knp[i][w] = max(val[i-1] + knp[i-1][w-wt[i-1]], knp[i-1][w]);
		    else
			    knp[i][w] = knp[i-1][w];
	    }
    }
	return knp[n][M];
}
int main()
{
	
	
	int i;
	printf("enter the number of items\n");
	scanf("%d",&n);
	printf("enter the max weight\n");
	scanf("%d",&M);
	for(i=0;i<n;i++)
	{
		printf("enter the weights and the benefits\n");
		scanf("%d",&wt[i]);
		scanf("%d",&val[i]);
	}
	
	printf("MAX VALUE IN THE KNAPSACK IS %d", knapsack());
	return 0;
}


	