//#define max 1000001
//#define _CRT_SECURE_NO_DEPRECATE
//#include<stdio.h>
//int main()
//{
//	int n = 20;
//	int count = 0;
//	int num = 0;//同时出现次数
//	int flag = 0;//标记与要找的字符串
//	char arr[max] = { 0 };
//	char arr1[6] = "Alice";
//	char arr2[4] = "Bob";
//	printf("请输入一行字符串：");
//	scanf("%s", arr);
//	for (count = 0; count <max-1; count++)
//	{
//
//		////if (arr[count] == arr1[0] && arr[count + 1] == arr1[1] &&
//		//	arr[count + 2] == arr1[2] && arr[count + 3] == arr1[3] && 
//		//	arr[count + 4] == arr1[4] ||
//		//	arr[count] == arr2[0] && arr[count + 1] == arr2[1] &&
//		//	arr[count + 2] == arr2[2] 
//		//	)
//		
//		if (arr[count] == arr1[0] && arr[count + 1] == arr1[1] &&
//			arr[count + 2] == arr1[2] && arr[count + 3] == arr1[3] &&
//			arr[count + 4] == arr1[4])
//		{
//			printf("Alice");
//			flag = 0;
//			count = count + 5;
//			if (!flag)
//			{
//				for (; count < count + n; count++)
//				{
//					if (arr[count] == arr2[0] && arr[count + 1] == arr2[1] &&
//						arr[count + 2] == arr2[2])
//					{
//						printf("Bob");
//						flag = 1;
//						num += 1;
//						count = count + 3;
//						break;
//					}
//				}
//				count = count + n;
//			}
//			if (flag)
//			{
//
//				for (; count < count + n; count++)
//				{
//					if (arr[count] == arr1[0] && arr[count + 1] == arr1[1] &&
//						arr[count + 2] == arr1[2] && arr[count + 3] == arr1[3] &&
//						arr[count + 4] == arr1[4])
//					{
//						printf("Alice");
//						flag = 0;
//						num += 1;
//						count = count + 5;
//						break;
//					}
//				}
//				count = count + n;
//			}
//		}
//		else if (arr[count] == arr2[0] && arr[count + 1] == arr2[1] && arr[count + 2] == arr2[2])
//		{
//			printf("Bob");
//				count = count + 3;
//			flag = 1;
//			if (flag)
//			{
//
//				for (; count < count + n; count++)
//				{
//					if (arr[count] == arr1[0] && arr[count + 1] == arr1[1] &&
//						arr[count + 2] == arr1[2] && arr[count + 3] == arr1[3] &&
//						arr[count + 4] == arr1[4])
//					{
//						printf("Alice");
//						flag = 0;
//						num += 1;
//						break;
//					}
//				}
//				if (flag)count = count + n;
//				else count = count + 5;
//			}
//			if (!flag)
//			{
//				for (; count < count + n; count++)
//				{
//					if (arr[count] == arr2[0] && arr[count + 1] == arr2[1] &&
//						arr[count + 2] == arr2[2])
//					{
//						printf("Bob");
//						flag = 1;
//						num += 1;
//						break;
//					}
//				}
//				if (!flag)
//					count = count + n;
//				else count = count + 3;
//			}
//		}
//		else count++;
//	}
//	printf("相关性为：%d", num);
//	return 0;
//}