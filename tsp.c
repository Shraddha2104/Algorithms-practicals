#include<stdio.h>
 
int matrix[25][25], visited_cities[10], limit, cost = 0;
 
int tsp(int c)
{
	int count, nearest_city = 999;
	int minimum = 999, temp;
	for(count = 0; count < limit; count++)
	{
		if((matrix[c][count] != 0) && (visited_cities[count] == 0))
		{
			if(matrix[c][count] < minimum)
			{
				minimum = matrix[count][0] + matrix[c][count];
			}
			temp = matrix[c][count];
			nearest_city = count;
		}
	}
	if(minimum != 999)
	{
		cost = cost + temp;
	}
	return nearest_city;
}
 
void minimum_cost(int city)
{
	int nearest_city;
	visited_cities[city] = 1;
	printf("%d ", city + 1);
	nearest_city = tsp(city);
	if(nearest_city == 999)
	{
		nearest_city = 0;
		printf("%d", nearest_city + 1);
		cost = cost + matrix[city][nearest_city];
		return;
	}
	minimum_cost(nearest_city);
}
 
int main()
{	
	int i, j;
	printf("Enter Total Number of Cities:\t");
	scanf("%d", &limit);
	printf("\nEnter Cost Matrix\n");
	for(i = 0; i < limit; i++)
	{
		printf("\nEnter %d Elements in Row[%d]\n", limit, i + 1);
		for(j = 0; j < limit; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
		visited_cities[i] = 0;
	}
	printf("\nEntered Cost Matrix\n");
	for(i = 0; i < limit; i++)
	{
		printf("\n");
		for(j = 0; j < limit; j++)
		{
			printf("%d ", matrix[i][j]);
		}
	}
	printf("\n\nPath:\t");
	minimum_cost(0);
	printf("\n\nMinimum Cost: \t");
	printf("%d\n", cost);
	return 0;
}

/*OUTPUT:
student@student-HP-ProOne-400-G1-AiO:~/Desktop$ gcc tsp.c -o tsp
student@student-HP-ProOne-400-G1-AiO:~/Desktop$ ./tsp
Enter Total Number of Cities:	4

Enter Cost Matrix

Enter 4 Elements in Row[1]
1 2 3 4

Enter 4 Elements in Row[2]
5 6 7 8

Enter 4 Elements in Row[3]
3 4 5 6

Enter 4 Elements in Row[4]
9 8 4 3

Entered Cost Matrix

1 2 3 4 
5 6 7 8 
3 4 5 6 
9 8 4 3 

Path:	1 4 3 2 1

Minimum Cost: 	17*/