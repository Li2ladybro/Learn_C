#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")         //�ѵ��뾲̬�⣬��д�ɲ�д
using namespace std;
//��ť����
typedef struct Button
{
	int left;
	int top;
	int right;
	int bottom;                //�������ҵ������
	bool line;                 //�Ƿ����ñ߿� 
	COLORREF color_full;       //���ɫ 
	COLORREF color_line;       //�߿���ɫ 
	string tcolor;             //������ɫ 
	unsigned int r;            //Բ�뾶��0��ʱ����Բ��
	bool T_flag;               //�Ƿ���ʾ����
	TCHAR text[1000];          //��ť����
	int theight;               //����߶�
	int twidth;                //������
	int tsetoff;               //ƫ����
}Button;
//��꽻��
int mouse(Button btn, int change);
//������ť
void out_long(Button btn);
//��ʼ����
IMAGE sart_bk,middle_bk;
//����Ƿ���Ҫˢ��
int clear_flag = 0;  
int main()
{
	initgraph(1365, 658);
	setbkcolor(BLUE);
	cleardevice();                  //������
	loadimage(&sart_bk,L"res\\start_bk.png", 1365, 658);//����Դ�ļ�����ͼƬ��sart_bk
	putimage(0, 0, &sart_bk);
	TCHAR tex1[1000] = _T("Entre");
	//���߿�,������ڲ���ɫ�������˱߿�ɫ,�����˱߽ǵİ뾶,Enter
	Button btn = { 280,400,550,480,0,RGB(215,232,250),GREEN,"blue",20,1,_T("Entre"),40,20,20};
	out_long(btn);
	while (1)
	{
		
		if (!(mouse(btn, 10)))
		{
			break;
		}
		else
			continue;
	}

	loadimage(&middle_bk, L"res\\middle_bk.jpg", 1920, 1440);    //����Դ�ļ�����ͼƬ��middle_bk
	putimage(0, 0, &middle_bk);

	system("pause");
	closegraph();
	return 0;
}
int mouse(Button btn, int change)
{
	//���ð�ť������Ӧ
	ExMessage m;                        //����һ����Ϣ����Ϣ
	m = getmessage(EM_MOUSE);           //��ȡ�����Ϣ  
	switch (m.message)
	{
    //����ƶ�����ťʱ��ť���
	case WM_MOUSEMOVE:
		if (m.x >= btn.left && m.x <= btn.right && m.y >= btn.top && m.y <= btn.bottom)
		{
			clear_flag = 1;
			btn.left = btn.left - change;
			btn.top -= change;
			btn.right += change;
			btn.bottom += change;
			out_long(btn);
			return -1;
		}
		else
		{
			if (clear_flag == 1)
			{
				int pts[] = { btn.left - change ,btn.top - change,  btn.right + change,btn.bottom + change };
				clearpolygon((POINT*)pts, 4);
				//cleardevice();
				//loadimage(&sart_bk, L"res\\start_bk.png", 1365, 658);//����Դ�ļ�����ͼƬ��bk
				putimage(0, 0, &sart_bk);
				out_long(btn);
				clear_flag = 0;
				return -1;
			}
			return -1;

		}
    //�������ť�˳�ѭ��
	case WM_LBUTTONDOWN:
		if (m.x >= btn.left && m.x <= btn.right && m.y >= btn.top && m.y <= btn.bottom)
		{
			clear_flag = 1;
			btn.left   = btn.left - change;
			btn.top    -= change;
			btn.right   += change;
			btn.bottom  += change;
			out_long(btn);
			mciSendString(_T("open res\\button_click _sound.mp3 alias music"), NULL, 0, NULL);     //alias�Ǳ�������˼������Ϳ���ȥֱ����music������kk.mp3
			mciSendString(_T("play music"), NULL, 0, NULL);          //��������
			return 0;
		}
		else
		{

			if (clear_flag == 1)
			{
				int pts[] = { btn.left - change ,btn.top- change,  btn.right+ change,btn.bottom+ change  };
				clearpolygon((POINT*)pts, 4);
				//cleardevice();
				//loadimage(&sart_bk, L"res\\start_bk.png", 1365, 658);//����Դ�ļ�����ͼƬ��bk
				putimage(0, 0, &sart_bk);
				out_long(btn);
				clear_flag = 0;
				return -1;
			}
			return -1;
		}
	}
}
void out_long(Button btn)
{
	setlinecolor(btn.color_line);  // ���õ�ǰ������ɫ 
	setfillcolor(btn.color_full);  // ���õ�ǰ�����ɫ 
	if (!btn.r)
	{
		//���û�а뾶�����������ͨ������
		if (btn.line)//����б߿�
			fillrectangle(btn.left, btn.top, btn.right, btn.bottom);
		else
			solidrectangle(btn.left, btn.top, btn.right, btn.bottom);
	}
	else
	{   //�����Բ�ǳ�����
		if (btn.line)
		{
			//����б߿�
			fillcircle(btn.left + btn.r, btn.top + btn.r, btn.r);
			fillcircle(btn.left + btn.r, btn.bottom - btn.r, btn.r);
			fillcircle(btn.right - btn.r, btn.top + btn.r, btn.r);
			fillcircle(btn.right - btn.r, btn.bottom - btn.r, btn.r);
			solidrectangle(btn.left, btn.top + btn.r, btn.right, btn.bottom - btn.r);
			solidrectangle(btn.left + btn.r, btn.top, btn.right - btn.r, btn.bottom);
			::line(btn.left + btn.r, btn.top, btn.right - btn.r, btn.top);
			::line(btn.left + btn.r, btn.bottom, btn.right - btn.r, btn.bottom);
			::line(btn.left, btn.top + btn.r, btn.left, btn.bottom - btn.r);
			::line(btn.right, btn.top + btn.r, btn.right, btn.bottom - btn.r);
		}
		else
		{
			solidrectangle(btn.left, btn.top + btn.r, btn.right, btn.bottom - btn.r);
			solidrectangle(btn.left + btn.r, btn.top, btn.right - btn.r, btn.bottom);
			solidcircle(btn.left + btn.r, btn.top + btn.r, btn.r);
			solidcircle(btn.left + btn.r, btn.bottom - btn.r, btn.r);
			solidcircle(btn.right - btn.r, btn.top + btn.r, btn.r);
			solidcircle(btn.right - btn.r, btn.bottom - btn.r, btn.r);
		}
	}
	if (btn.T_flag == 1)
	{
		//��������
		setbkmode(TRANSPARENT);//����͸������
		if (btn.tcolor == "red" || btn.tcolor == "RED")
		{
			settextcolor(RED);//����������ɫΪ��ɫ
		}
		else if (btn.tcolor == "green" || btn.tcolor == "GREEN")
		{
			settextcolor(GREEN);//����������ɫΪ��ɫ
		}
		else if (btn.tcolor == "blue" || btn.tcolor == "BLUE")
		{
			settextcolor(BLUE);//����������ɫΪ��ɫ
		}
		else if (btn.tcolor == "yellow" || btn.tcolor == "YELLOW")
		{
			settextcolor(YELLOW);//����������ɫΪ��ɫ
		}
		else if (btn.tcolor == "black" || btn.tcolor == "BLACK")
		{
			settextcolor(BLACK);//����������ɫΪ��ɫ
		}
		else if (btn.tcolor == "white" || btn.tcolor == "WHITE")
		{
			settextcolor(WHITE);//����������ɫΪ��ɫ
		}

		else
		{
			int x;
			x = MessageBox(GetForegroundWindow(),
				TEXT("���鰴ť�߿���ɫ�Ƿ�������ȷ��Ŀǰ������ɫ������red��green��blue��yellow��black��white��"),
				TEXT("��ť�߿���ɫ���ô���"), 1);
			cout << x;
		}
		//���������ʽ
		settextstyle(btn.theight, btn.twidth, _T("����"));
		outtextxy(btn.left + btn.tsetoff, btn.top + btn.tsetoff, btn.text);//������ʾλ��
	}
}