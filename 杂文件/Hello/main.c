#include<stdio.h>
int main()
{
	// �У�row ;�У�column
	for (int row = 1; row <=9; row++)
	{
		for (int column = 1; column <=row; column++)
		{
			printf("%d*%d=%2d ", row, column, row * column);
		}
		printf("\n");
	}
	return 0;
}




