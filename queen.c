#include<stdio.h>
#include<math.h>
int board[10],count=0;
int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  //checking column and digonal conflicts
	  if(board[i]==column)
	   return 0;
	  else if(abs(board[i]-column)==abs(i-row))
	   return 0;
 }
 
 return 1; //no conflicts
}
void print(int n)
{
	printf("\n\nSolution %d:\n\n",++count);
	for(int i=1;i<=n;i++)
	{
		printf("\n");
		for(int j=1;j<=n;j++)
		{
			if(board[i]==j)
				printf("\tQ"); //queen at i,j position
			else
				printf("\t-");
		}
	}
}	
void nqueen(int row,int n)
{
	int column;
	for(column=1;column<=n;++column)
	{
		if(place(row,column))
		{
			board[row]=column;
			if(row==n)
				print(n);
			else
				nqueen(row+1,n);
		}
	}
}

int main()
{
	int n;
	printf("enter the value of n \n");
	scanf("%d",&n);
	nqueen(1,n);
	return 0;
}