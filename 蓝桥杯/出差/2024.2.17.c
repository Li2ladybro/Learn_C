//(1) 若A去，则C和D中要去一人。
//(2) B和C不能都去。
//(3) C去则D要留下。
#include<stdio.h>
int c = 1;
int result(int data[4]);
int a[3] = {0};
int main()
{
	int count = 1;
	int data[4] = { 0 };
    for (count = 1; count <= 3; count++)
	{
		for (c = 0; c< 4; c++)
		{
			data[c] = 0;
		}
		data[0] = 1;
		data[count] = 1;
		if (result(data))
		{
			if (data[0] == 1)
				printf("A ");
			if (data[1] == 1)
				printf("B ");
			if (data[2] == 1)
				printf("C ");
			if (data[3] == 1)
				printf("D ");
			printf("\n");
		}
		//printf("##########################\n");
	}
		//int data[4] = { 0 };
		for (count = 2; count <= 3; count++)
		{
			for (c = 0; c < 4; c++)
			{
				data[c] = 0;
			}
			data[1] = 1;
			data[count] = 1;
			if (result(data))
			{
				if (data[0] == 1)
					printf("A ");
				if (data[1] == 1)
					printf("B ");
				if (data[2] == 1)
					printf("C ");
				if (data[3] == 1)
					printf("D ");
				printf("\n");
			}
			//printf("##########################\n");
		}
		for (c = 0; c < 4; c++)
		{
			data[c] = 0;
		}
		data[2] = 1;
		data[3] = 1;
		if (result(data))
		{
			if (data[0] == 1)
				printf("A ");
			if (data[1] == 1)
				printf("B ");
			if (data[2] == 1)
				printf("C ");
			if (data[3] == 1)
				printf("D ");
			printf("\n");
			
		}
	//	printf("##########################\n");
		return 0;
}
int result(int data[4])
{
	for (c = 0; c < 4; c++)
	{
		//printf("%d\n", data[c]);
	}
	for (c = 0; c <3; c++)
	{
		a[c]=1;
	}
	if (data[0] == 1)
	{
		if(data[2] == 1 || data[3] == 1)
			a[0] = 1;
		else a[0] = 0;
	}
	//else a[0] = 0;
	if (data[1] == 1 && data[2] == 1)
		a[1] = 0;
	else a[1] = 1;
	if (data[2] == 1)
	{
		if (data[3] == 0)
			a[2] = 1;
		else a[2] = 0;
	}
   // else a[2] = 0;
	if (a[0] == 1 && a[1] == 1 && a[2] == 1)
		return 1;
	else return 0;
}
//
//
//#include <stdio.h>
//#include <stdlib.h>

//int main(int argc, char* argv[])
//{
//    // 请在此输入您的代码
//    char ch;
//    for (ch = 'A'; ch <= 'D'; ch++)
//    {
//        if (ch == 'A')
//        {
//            printf("%c %c\n", ch, 'C');
//            printf("%c %c\n", ch, 'D');
//        }
//        if (ch == 'B')
//        {
//            printf("%c %c\n", ch, 'D');
//        }
//    }
//
//    return 0;
//}
