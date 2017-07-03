#include<stdio.h>
#include<string.h>
int l[10][10];
char x[10];
	char y[10];
	int m,n;
int max(int a, int b)
{	int c= (a > b)? a : b;
	return c;
}
int lcs(char x[10],char y[10],int m,int n)
{
	int i,j;
	for(i
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			
			
			 if(x[i-1]==y[j-1])
				l[i][j]=1+l[i-1][j-1];
			else
				l[i][j]=max(l[i-1][j], l[i][j-1]);
			
		}
	}
	return l[m][n];
}
void print(int i,int j)
{
	
	 if(x[i-1]==y[j-1])
	{
		print(i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if (l[i][j]==l[i-1][j])
         print(i-1,j);
    	else
        print(i,j-1);
}	
int main()
{
	
	printf("enter the first string:\n");
	scanf("%s",x);
	printf("enter the SECOND string:\n");
	scanf("%s",y);
	m = strlen(x);
	n = strlen(y);
	printf("Length of LCS is %d\n", lcs( x, y, m, n ) );
	print(m,n);
	return 0;
}

				

	
	