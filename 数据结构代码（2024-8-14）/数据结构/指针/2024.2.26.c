#include<stdio.h>
int main()
{
	int a = 0;
	//char* (*pf)(char*, const char*)=0;
	char* (*pf[4])(char*, const char*) = { 0 };
	//printf("%d", pf);
	for (a = 0; a < 4; a++)
	{
		printf("%d", pf[a]);
	}
	return 0;
}