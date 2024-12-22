#include<stdio.h>
int main()
{
	int arr[12 * 31][9] = { 0 };
	int arr1[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i = 0,j = 0,m=1;
	for (i = 1; i <= 12; i++)
	{
		for (j = 1; j <= arr1[i]; j++)
		{
				arr[m][1] = 2;
				arr[m][2] = 0;
				arr[m][3] = 2;
				arr[m][4] = 2;
				arr[m][5] = i/10;
				arr[m][6] = i%10;
				arr[m][7] = j/10;
				arr[m][8] = j % 10; 
				m++;
	    }
	}
	int sum = 0;
	while (m)
	{
		for (i = 6; i <= 7; i++)
		{
			/*if (arr[m][i] == 0||arr[m][i - 1] ==0|| arr[m][i + 1]==0)
			{
				continue;
			}*/
			if ((arr[m][i] - arr[m][i - 1] == 1)&&(arr[m][i + 1]- arr[m][i] == 1))
			{
				sum++;
				break;
			}
		}
		m--;
	}
	printf("%d",sum);
	return 0;
}