// 将 Python 与C语言文件操作性能测试

#include <stdio.h>
#include <time.h>

int main()
{
	FILE* writeFile = fopen("test.txt", "w");

	if (writeFile == NULL)
	{
		printf("文件打开失败\n");
		exit(1);
	}

	long begin = clock();

	long end_count = 1000000;

	for (int i = 0; i < end_count; i++)
	{
		fprintf(writeFile, "我是你爸爸\n");
	}

	long end = clock();
	printf("写入一共耗时%ld ms\n", end - begin);
	fclose(writeFile);

	return 0;
}