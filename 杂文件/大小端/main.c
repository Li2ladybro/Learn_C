////#include<stdio.h>
////int check_sys(void);
////int main()
////{
////	int result =check_sys(10000000000000000000);
////	if (result == 1)
////	{
////		printf("Ð¡¶Ë\n");
////
////			}
////	else
////	{
////		printf("´ó¶Ë\n");
////	}
////
////	char a = ;
////	printf("%d", a);
////	/*int num = 0x11223344;
////	char* pi = (char
////		*) & num;
////	 *pi;*/
////	return 0;
////}
////
////int check_sys(void)
////{
////	int testnum = 1;
////	return *(char*) & testnum;
////}
//#include<limits.h>
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[1000];
//	for (int i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//
//	}
//	printf("%d", strlen(a));
//	return 0;
//
//}
void caluate_point_size(int[10]);
#include<stdio.h>

int main()
{
	float num = 5.5;

	// 
	int arr[10] = { 0 };

	caluate_point_size(arr);

	return 0;
}

void caluate_point_size(int arr[10])
{
	printf("%d", sizeof(arr));

}