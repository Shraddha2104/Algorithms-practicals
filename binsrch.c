#include<stdio.h>
int n,m,a[10],c;
int binary(int a[10],int low,int high)
{
	int mid;

     if(low<=high){
          mid=(low+high)/2;
          if(m==a[mid]){
		c=1;
              return mid;
          }
          else if(m<a[mid]){
               binary(a,low,mid-1);
          }
          else
              binary(a,mid+1,high);
     }
     
}
int main()
{
	int low,mid,high,i,d;

	printf("Enter the size of an array: ");
    scanf("%d",&n);

    printf("Enter the elements of the array: " );
    for(i=0;i<n;i++)
	{
         scanf("%d",&a[i]);
    }

    printf("Enter the number to be search: ");
    scanf("%d",&m);
	low=0,high=n-1;
	d=binary(a,low,high);
    if(c==1)
         printf("Number is  found at %d",d+1);
    else
         printf("Number is not found.");

    return 0;
 }

	
	
