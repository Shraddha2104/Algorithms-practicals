#include<stdio.h>
void select(int a[],int n);

int main()
{
	int i,n,a[20];
	printf("enter the number of values\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter value:\n");
		scanf("%d",&a[i]);
	}
	select(a,n);
	printf("sorted array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
return 0;
}
void select(int a[],int n)
{
	int temp,i,j;
	for(i=0;i<(n-1);i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		
	}

}
