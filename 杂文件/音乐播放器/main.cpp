#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")//�ѵ��뾲̬�⣬��д�ɲ�д
using namespace std;
int main()
{
	int flag = 0;

	cout << "==========[C++���ֲ�����]==========" << endl;

	cout << "����1���������֣�����2��ֹͣ���ţ�����3�˳�����" << endl;

	while (cin >> flag)
	{
		switch (flag)
		{
		case 1://��������
			cout << "���ڲ�������" << endl;
			mciSendString(_T("open res\\������Ļ�.mp3 alias bkmusic"), NULL, 0, NULL);//��������
			mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);//ѭ������
			break;
		case 2://ֹͣ����
			cout << "���ֲ�����ֹͣ" << endl;
			mciSendString(_T("close bkmusic"), NULL, 0, NULL);//ֹͣ����
			break;
		case 3:
			break;
		}
		if (flag == 3)
		{
			cout << "�������н���" << endl;
			break;
		}
	}
	return 0;
}