#include<graphics.h>
#include<conio.h>
int main()
{
	initgraph(640, 480);
	setbkcolor(WHITE);//���ñ���Ϊ��ɫ
	cleardevice();//�ñ���ɫ�����Ļ
	int san[] = { 80,5,10,100,100,100 };
	int san1[] = { 80,30,70,40,60,80,40,90 };
	setfillcolor(RED);//������ɫ
	setlinecolor(GREEN);//�߿����ɫ����ɫ
	fillpolygon((POINT*)san, 3);//�б߿�������������
	clearpolygon((POINT*)san1, 4);//��ղ������ı���
	_getch();
	closegraph();//�رմ���
	return 0;
}
