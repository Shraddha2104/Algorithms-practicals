#include<conio.h>
#include<stdio.h>
int main()
{
	int i,min, max;
	int a[10];
	
	printf("Enter 10 numbers");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	max=min=a[0];
	for(i=1;i<10;i++)
	{
		if (a[i]<min)
			min=a[i];
		if (a[i]>max)
			max=a[i];
	}
	printf("Max = %d Min = %d",max,min);
	return 0;
}