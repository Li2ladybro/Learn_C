/*###############################################################################
1.��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ����
2.������Ա����Ҫ���뵽ĳ������(������)���������ĵ�ַ����
   ������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
VS��Ĭ�ϵ�ֵΪ8     #pragma pack(4����������Ĭ�϶�����Ϊ4
3.�ṹ���ܴ�СΪ��������(ÿ����Ա��������һ��������)����������
4.���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ�����������������������
�ṹ��������С����������������(��Ƕ�׽ṹ��Ķ�����)��������
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