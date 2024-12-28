/*###############################################################################
1.第一个成员在与结构体变量偏移量为0的地址处。
2.其他成员变量要对齐到某个数字(对齐数)的整数倍的地址处。
   对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
VS中默认的值为8     #pragma pack(4）可以设置默认对齐数为4
3.结构体总大小为最大对齐数(每个成员变量都有一个对齐数)的整数倍。
4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
结构体的整体大小就是所有最大对齐数(含嵌套结构体的对齐数)的整数信
*/
//#include <stdio.h>
//#include<stddef.h>
//
//

//
//int main()
//{
//	
//	STUDENT Li_ming;
//	printf("%d\n", offsetof(STUDENT, num));
//	printf("%d\n", offsetof(STUDENT, name));
//	printf("%d\n", offsetof(STUDENT, age));
//	printf("%d\n", offsetof(STUDENT, addr));
//	printf("%d\n", sizeof(STUDENT));
//	return 0;
//}

#include <stdio.h>
typedef struct student
{
	char num;
	char name[10];
	int age;
	char addr[10];
}STUDENT;
#define OFFSETOF(type,member) ((int)&(((type*)0)->member))
int main()
{
		printf("%d\n", OFFSETOF(STUDENT, num));
		printf("%d\n", OFFSETOF(STUDENT, name));
		printf("%d\n", OFFSETOF(STUDENT, age));
		printf("%d\n", OFFSETOF(STUDENT, addr));
		printf("%d\n", sizeof(STUDENT));
	return 0;
}