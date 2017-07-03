#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int calcwin(int p[],int x,int n)
{
	int w1,w2,mid;
	if(n-x > 2)
	{ 
		mid=(x+n)/2;
		w1 = calcwin(p,x,mid);
		w2 = calcwin(p,mid+1,n);   
		if(w1 < w2)
		{  
			printf("The winner between %d and %d is %d\n",w1,w2,w2);
			return w2;
		}
		else
		{  
			printf("The winner between %d and %d is %d\n",w1,w2,w1);	
			return w1;
		}
	}
	else if(x==n)
		return p[n];
	else{ 
		if(p[x] < p[n])
		{
			printf("The winner between %d and %d is %d\n",p[x],p[n],p[n]);
			return p[n];
		}
		else
		{
			printf("The winner between %d and %d is %d\n",p[x],p[n],p[x]);
			return p[x];   
		}
	}
	
}

int main()
{
		int i,win,n,p[100];
		
		printf("Enter the no of players:\n");
		scanf("%d",&n);
		for(i=0;i < n;i++)
		{	
			p[i]=rand() % 60; 
			printf("Player No %d: %d\n",i+1,p[i]);
		}
		win = calcwin(p,0,n-1);	
		printf("The winner is %d\n",win);
		return 0;
}
