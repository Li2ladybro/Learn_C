#include<stdio.h>
int move[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int i = 1;
static void DFS(char arr[5][5], int nx, int ny)
{
	
	arr[nx][ny] = '#';
	for (i = 0; i < 4; ++i)
	{
		nx = nx + move[i][0];
		ny = ny + move[i][1];
		if (nx >= 5 || nx < 0|| ny >= 5 || ny < 0)
		{
			continue;
		}
		if(arr[nx][ny] = 'O')
		DFS(arr, nx, ny);
	}
}
static void solve(char arr[5][5])
{
	int row = 5, col = 5;
	int i = 0, j = 0;
	for (i = 0; i < col; ++i)
	{
		if (arr[0][i] == 'O')
		{
			DFS(arr, 0, i);
		}
		if (arr[row - 1][i] == 'O')
		{
			DFS(arr, row - 1, i);
		}
	}
	for (i = 1; i < row; ++i)
	{
		//第一列，最后一列
		if (arr[i][0] == 'O')
		{
			DFS(arr, i, 0);
		}
		if (arr[i][col - 1] == 'O')
		{
			DFS(arr, i, col - 1);
		}
	}
	//int i = 0, j = 0;
	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			if (arr[i][j] == 'O')
			{
				arr[i][j] = 'X';
			}
			if(arr[i][j] == '#')
			{
				arr[i][j] = 'O';
			}

		}
	}
}
static void print(char arr[][5])
{
	int i = 0, j = 0;
	for (i = 0; i < 5; ++i)
	{
		printf("\n");
		for (j = 0; j < 5; ++j)
		{
			printf("%c ", arr[i][j]);
		}
	}
}
int main()
{
	char arr[5][5] = { 
		               {'X','X','X','X','O'},
					   {'X','X','X','X','O'},
					   {'X','O','O','X','O'},
					   {'X','O','X','X','O'},
		               {'X','X','X','X','O'}
	                 };
	
	
	solve(arr);
	print(arr);
	return 0;
}