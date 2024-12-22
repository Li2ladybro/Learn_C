#include<stdio.h>
 #include<math.h>
int main()
{

	int result = 0;
	int arr[4] = { 2,2,0,2 };
	for (int i = 0; i < 4; i++)
	{
		result+=arr[i] *pow(9,i);
	}
	printf("%d", result);
	return 0;
}
//#include<stdio.h>
//
//int main()
//{
//	printf("%d",(int ) pow(2, 4));
//	return 0;
//}