#include<stdio.h>
int n,sum;
int w[10],x[10];
void subset(int s,int k,int r)
{
	int i=0;
	x[k]=1;
	if(s+w[k]==sum)
	{
		for(i=1;i<=k;i++)
			printf("%d\t",x[i]);
	}
	else if(s+w[k]+w[k+1]<sum)
		subset(s+w[k],k+1,r-w[k]);
	
	if ((s +r-w[k]) >= sum && (s+w[k+1] <= sum))//dont select kth elemnt
	{ 
            x[k] = 0;
            subset(s, k + 1, r - w[k]);
    }
}
		
int main()
{
	printf("enter the number of elements:\n");
	scanf("%d",&n);
	int total=0,i;
	printf("enter the elements\n");
	for( i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		total=total+w[i];
	}
	printf("enter the sum to be obtained\n");
	scanf("%d",&sum);
	if(total<sum)
		printf("subset is not possible\n");
	
	subset(0,1,total);
	return 0;
}
output:
enter the number of elements:
6
enter the elements
1
2
3
4
6
9
enter the sum to be obtained
8
0       1       0       0       1

	