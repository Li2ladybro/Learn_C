#include<graphics.h>
#include<conio.h>
#include<string>
#include<Windows.h>
#include<iostream>
using namespace std;

struct Button
{
	int x1;
	int x2;
	int y1;
	int y2;
};

void setVertexAndShowButton
(
	Button btn, int x1, int x2, int y1, int y2, 
	TCHAR text[1000], int tlength, int twidth, int tsetoff,
	string tcolor, string lcolor, string fcolor
)
{
	BeginBatchDraw();//��ͣ�滭
	//���ö�������
	btn.x1 = x1;
	btn.x2 = x2;
	btn.y1 = y1;
	btn.y2 = y2;
	//���ñ߿���ɫ
	if (lcolor == "red" || lcolor == "RED")setlinecolor(RED);//���ñ߿���ɫΪ��ɫ
	else if (lcolor == "green" || lcolor == "GREEN")setlinecolor(GREEN);//���ñ߿���ɫΪ��ɫ
	else if (lcolor == "blue" || lcolor == "BLUE")setlinecolor(BLUE);//���ñ߿���ɫΪ��ɫ
	else if (lcolor == "yellow" || lcolor == "YELLOW")setlinecolor(YELLOW);//���ñ߿���ɫΪ��ɫ
	else if (lcolor == "black" || lcolor == "BLACK")setlinecolor(BLACK);//���ñ߿���ɫΪ��ɫ
	else if (lcolor == "white" || lcolor == "WHITE")setlinecolor(WHITE);//���ñ߿���ɫΪ��ɫ
	else {
		int x;
		x = MessageBox(GetForegroundWindow(), 
			TEXT("���鰴ť�߿���ɫ�Ƿ�������ȷ��Ŀǰ������ɫ������red��green��blue��yellow��black��white��"),
			TEXT("��ť�߿���ɫ���ô���"), 1);
		cout << x;
	}
	//���ư�ť�߿�
	rectangle(btn.x1, btn.y1, btn.x2, btn.y2);
	//���������ɫ
	if (fcolor == "red" || fcolor == "RED")setfillcolor(RED);//���������ɫΪ��ɫ
	else if (fcolor == "green" || fcolor == "GREEN")setfillcolor(GREEN);//���������ɫΪ��ɫ
	else if (fcolor == "blue" || fcolor == "BLUE")setfillcolor(BLUE);//���������ɫΪ��ɫ
	else if (fcolor == "yellow" || fcolor == "YELLOW")setfillcolor(YELLOW);//���������ɫΪ��ɫ
	else if (fcolor == "black" || fcolor == "BLACK")setfillcolor(BLACK);//���������ɫΪ��ɫ
	else if (fcolor == "white" || fcolor == "WHITE")setfillcolor(WHITE);//���������ɫΪ��ɫ
	else {
		int x;
		x = MessageBox(GetForegroundWindow(), TEXT("���鰴ť�����ɫ�Ƿ�������ȷ��Ŀǰ�����ɫ������red��green��blue��yellow��black��white��"), TEXT("��ť�����ɫ���ô���"), 1);
		cout << x;
	}
	fillrectangle(btn.x1, btn.y1, btn.x2, btn.y2);
	//���ð�ť����
	setbkmode(TRANSPARENT);//����͸������

	if (tcolor == "red" || tcolor == "RED")settextcolor(RED);//����������ɫΪ��ɫ
	else if (tcolor == "green" || tcolor == "GREEN")settextcolor(GREEN);//����������ɫΪ��ɫ
	else if (tcolor == "blue" || tcolor == "BLUE")settextcolor(BLUE);//����������ɫΪ��ɫ
	else if (tcolor == "yellow" || tcolor == "YELLOW")settextcolor(YELLOW);//����������ɫΪ��ɫ
	else if (tcolor == "black" || tcolor == "BLACK")settextcolor(BLACK);//����������ɫΪ��ɫ
	else if (tcolor == "white" || tcolor == "WHITE")settextcolor(WHITE);//����������ɫΪ��ɫ
	else {
		int x;
		x = MessageBox(GetForegroundWindow(), TEXT("����������ɫ�Ƿ�������ȷ��Ŀǰ������ɫ������red��green��blue��yellow��black��white��"), TEXT("������ɫ���ô���"), 1);
		cout << x;
	}
	//settextcolor(BLUE);//����������ɫ
	settextstyle(tlength, twidth, _T("����"));//���������ʽ
	outtextxy(x1 + tsetoff, y1 + tsetoff, text);//������ʾλ��


	//���ð�ť������Ӧ
	//MOUSEMSG m;// ���������Ϣ
	int change = 10;
	ExMessage m;//����һ����Ϣ����
	m = getmessage(EM_MOUSE);//��ȡ�����Ϣ
	switch (m.message)
	{
	case WM_MOUSEMOVE:
		// ����ƶ���ťʱ��ť���
		if (m.x >= btn.x1 && m.x <= btn.x2)
		{
			if (m.y >= btn.y1 && m.y <= btn.y2)
			{
				rectangle(btn.x1 - change, btn.y1 - change, btn.x2 + change, btn.y2 + change);
			}
			else
			{
				FlushBatchDraw();//��������
				//cleardevice();
			}
		}
		else
		{
			FlushBatchDraw();//��������
			//cleardevice();
		}
		break;

	case WM_LBUTTONDOWN:
		// �������ť�����ɫ
		if (m.x >= btn.x1 && m.x <= btn.x2)
		{
			if (m.y >= btn.y1 && m.y <= btn.y2)
			{
				setfillcolor(GREEN);
				fillrectangle(btn.x1, btn.y1, btn.x2, btn.y2);
				FlushBatchDraw();//��������
			}
			else
			{
				FlushBatchDraw();//��������
				//cleardevice();
			}
		}
		break;
	}

	//�ָ����ߺ������ɫ
	setlinecolor(WHITE);
	setfillcolor(WHITE);
}

int main()
{
	Button btns[3]; //��ʼ����ť�ṹ������

	initgraph(640, 480);//��ʼ������

	TCHAR tex1[1000] = _T("Entre");
	TCHAR tex2[1000] = _T("��ť2");
	TCHAR tex3[1000] = _T("��ť3");

	while (1)
	{
		setVertexAndShowButton(btns[0], 280, 360, 220, 260, tex1, 20, 10, 10, "green", "green", "red");

		setVertexAndShowButton(btns[1], 280, 360, 270, 310, tex2, 20, 10, 5, "white", "green", "red");

		setVertexAndShowButton(btns[2], 280, 360, 320, 360, tex3, 20, 10, 5, "YELLOW", "green", "red");
	}

	_getch();//�ȴ��û�����

	return 0;
}