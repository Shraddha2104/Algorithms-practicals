#include<stdio.h>
int a[50];
void read(int);
void quicksort(int,int);
int partition(int,int,int);
void display(int);
int main()
{
	int n;
	printf("enter the number of values\n");
	scanf("%d",&n);
	read(n);
	quicksort(0,n-1);
	display(n);
	return 0;
	}
void read(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter value:\n");
		scanf("%d",&a[i]);
	}
}
void quicksort(int lb,int ub)
{
	int j=0;
	if(lb>=ub)
	return;
	j=partition(lb,ub,j);
	quicksort(lb,j-1);
	quicksort(j+1,ub);
	
	}
int partition(int lb,int ub,int pj)
{
	int up,down,temp,x;
	x=a[lb];
	up=ub;
	down=lb;
	while(down<up)
	{
		while(a[down]<=x && down<up)
			down++;
		while(a[up]>x)
			up--;
		if(down<up)
		{
			temp=a[down];
			a[down]=a[up];
			a[up]=temp;
		}
	}
	a[lb]=a[up];
	a[up]=x;
	pj=up;
	return pj;
}
void display(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}	
	