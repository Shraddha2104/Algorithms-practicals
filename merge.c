#include<stdio.h>
int n;



void merge(int a[],int low,int mid,int high)
{
		int i,j,k;
		int b[30];
		k=0;
		i=low;
		j=mid+1;
		while(i<=mid &&j<=high)
		{
			if(a[j]>a[i])
			{
				b[k]=a[i];
				i++;
			}
			else 
			{
				b[k]=a[j];
				j++;
			}
		k++;
		}
		while(i<=mid)
		{
			b[k]=a[i];
			k++;
			i++;
		}
		while(j<=high)
		{
			b[k]=a[j];
			k++;
			j++;
		}
		for(i=low,j=0;i<=high;i++,j++)
			a[i]=b[j];
}

void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	int i,a[30];
	printf("enter the number of elements:\t");
	scanf("%d",&n);
	printf("enter  elements:");
	 for(i=0;i<n;i++)
	 {
	  scanf("%d",&a[i]);
	 }
	mergesort(a,0,n-1);
	for(i=0;i<n;i++)
	 {
	  printf("%d\t",a[i]);
	 }
	return 0;
}
			
			
			
	