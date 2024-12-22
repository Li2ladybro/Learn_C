//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char str[1000] = "WHERETHEREISAWILLTHEREISAWAY";
//	int longth = strlen(str);
//	int a = 0;
//	int b = 0;
//	for (b = 1; b <= longth; b++)
//	{
//		for (a = 0; a < longth - 1; a++)
//		{
//			char temp = 0;
//			if (str[a] > str[a + 1])
//			{
//				temp = str[a];
//				str[a] = str[a + 1];
//				str[a + 1] = temp;
//			}
//		}
//	}
//	printf("%s", str);
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
static int compare(const void* a, const void* b)
{
	return *(char*)a - *(char*)b;
}
int main()
{
	char str[1000] = "WHERETHEREISAWILLTHEREISAWAY";
	qsort(str, strlen(str), sizeof(str[0]), compare);
	printf("%s", str);
	return 0;
}
