#include<stdio.h>
#include<windows.h>//gotoxy
#include<conio.h>//getch
#include<string.h>//strcmp
#define ROW 14
#define COL 14

void gotoxy(int x, int y)//�β�
{
	HANDLE hOut;
	COORD pos = { x,y };
	// ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
	//printf("��λ���λ������(%d,%d)\n",pos.X,pos.Y);
}

void paintWindow()       //�û���¼����
{
	int startX = 6;
	int startY = 5;
	int width = 20;
	int height = 20;
	int i = 0;
	//��ӡ����   
	//��궨λ �ҹ��� ��  �� �� �� �� ��
	//���� y���� x �ڱ� (x-x+w)
	gotoxy(startX, startY);
	printf("��");
	for (i = 0; i < width - 2; i++)  //����ѭ������width-2��
	{
		printf("�� ");
	}
	printf("��");
	//��� x���� y�ڱ� (y��y+height)
	for (i = 1; i <= height - 2; i++)
	{
		gotoxy(startX, startY + i);
		printf("��");
	}

	//�ұ� x���� =startx+width-1  y�ڱ� y �� y+height
	for (i = 1; i <= height - 2; i++)
	{
		gotoxy(startX + width * 2 - 3, startY + i);
		printf("��");
	}
	//�ײ� x�ڱ仯    y���� ��x��x+width�� �� 
	gotoxy(startX, startY + height - 1);
	printf("��");
	for (i = 0; i < width - 2; i++)
	{
		printf("�� ");
	}
	printf("��");

	gotoxy(startX, startX + height);
}

void login()     //�û���¼����
{
	char ch = 0;
	int i = 0;
	char name[9] = { 0 };//�ַ����鲿�ֳ�ʼ��
	char pwd[9] = { 0 };//�ַ����鲿�ֳ�ʼ��
	//����һ������
	paintWindow();
	//���Ʊ��� ��ǩ
	gotoxy(21, 9);
	printf("��¼����");

	gotoxy(6 + 5, 12);
	printf("�˺ţ�");

	gotoxy(6 + 5, 16);
	printf("���룺");

	gotoxy(18, 12);//��궨λ���û��������λ��
	//�û��������� �洢
	while (1)
	{
		ch = _getch();
		if (ch == '\r' && i == 0)  //�κ����ݶ�û��
		{
			continue;
		}
		if (ch == '\r' && i > 0 || i == 8)  //��������λ
		{
			break;
		}
		if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			_putch(ch);
			name[i] = ch;
			++i;
		}
	}

	gotoxy(18, 16); //��궨λ�����������λ��
	i = 0;//ʹ��ͬһ�������� ��Ҫ����
	//�������� �洢
	while (1)
	{
		ch = _getch();
		if (ch == '\r' && i == 0)  //�κ����ݶ�û��
		{
			continue;
		}
		if (ch == '\r' && i > 0 || i == 8)  //��������λ
		{
			break;
		}
		if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			_putch('*');
			pwd[i] = ch;
			++i;
		}
	}

	gotoxy(15, 18);  //��ʾ��¼�ɹ� ��¼ʧ��
	if (strcmp(name, "admin") == 0 && strcmp(pwd, "123456") == 0)
	{
		printf("��¼�ɹ�\n");
	}
	else
	{
		printf("��¼ʧ��\n");
	}

	gotoxy(0, 27);

	//��¼��֤  admin 123456
}

int main()
{
	login();
	return 0;
}