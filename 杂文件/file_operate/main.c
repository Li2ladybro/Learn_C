// �� Python ��C�����ļ��������ܲ���

#include <stdio.h>
#include <time.h>

int main()
{
	FILE* writeFile = fopen("test.txt", "w");

	if (writeFile == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(1);
	}

	long begin = clock();

	long end_count = 1000000;

	for (int i = 0; i < end_count; i++)
	{
		fprintf(writeFile, "������ְ�\n");
	}

	long end = clock();
	printf("д��һ����ʱ%ld ms\n", end - begin);
	fclose(writeFile);

	return 0;
}