#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")//已导入静态库，可写可不写
using namespace std;
int main()
{
	int flag = 0;

	cout << "==========[C++音乐播放器]==========" << endl;

	cout << "按下1键播放音乐，按下2键停止播放，按下3退出程序" << endl;

	while (cin >> flag)
	{
		switch (flag)
		{
		case 1://播放音乐
			cout << "正在播放音乐" << endl;
			mciSendString(_T("open res\\淤泥里的花.mp3 alias bkmusic"), NULL, 0, NULL);//播放音乐
			mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);//循环播放
			break;
		case 2://停止音乐
			cout << "音乐播放已停止" << endl;
			mciSendString(_T("close bkmusic"), NULL, 0, NULL);//停止播放
			break;
		case 3:
			break;
		}
		if (flag == 3)
		{
			cout << "程序运行结束" << endl;
			break;
		}
	}
	return 0;
}