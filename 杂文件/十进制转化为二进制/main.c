//#include<stdio.h>
//int main()
//{
//    int num, n = 0, arr[8] = { 48,48,48,48,48,48,48,48 };
//    scanf_s("%d", &num);
//    while (num > 0)
//    {
//        arr[n++] = num % 2 + '0';
//        num /= 2;
//    }
//    for (n = 7; n > -1; n--)
//    {
//        printf("%c", arr[n]);
//    }
//    return 0;
//}

#include<stdio.h>
void main(void)
{
	int x = 1, y = 0, a = 0, b = 0;
	switch (x)
	{
	case 1:
		switch (y)
		{
		case 0:a++; break;
		case 1:b++; break;
		}
	case 2:a++; b++; break;
	case 3:a++; b++;
	}
	printf("a=%d,b=%d\n", a, b);
}
