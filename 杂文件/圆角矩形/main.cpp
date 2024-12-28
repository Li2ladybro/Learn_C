#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<stdio.h>
//BloodBarDraw�Զ������Ѫ������������false����������Ѫ����ʧ�����򷵻�true���������
//BloodTotal //Ŀ����Ѫ��
//NowBlood ��ǰĿ��Ѫ��
//x Ѫ����ʼx����
//y Ѫ����ʼy����
//height Ѫ���ĸ߶�
//ellipsewidth  Բ�Ǿ���Ѫ����Բ�ǵ���Բ��ȡ�
//ellipseheight  Բ�Ǿ���Ѫ����Բ�ǵ���Բ�߶ȡ�
//InitBloodBarLenth ����Ѫ������
bool BloodBarDraw(int BloodTotal, int* NowBlood, int Harm, int x, int y, int height, int ellipsewidth, int ellipseheight, int InitBloodBarLenth = 200) {
	//��ȡ��ǰѪ��
	int* nowblood = NowBlood;
	printf("��ǰѪ����%d\n", *nowblood);
	//����Ѫ����
	float BloodVolumeRatio = (*nowblood - Harm) * 1.0 / BloodTotal;
	printf("���º�ǰѪ���ȣ�%.2f\n", BloodVolumeRatio);
	//����Ѫ������
	int EndBloodBarLenth = BloodVolumeRatio * InitBloodBarLenth;
	//printf("total:%d\n", *total);
	//���ñ߿�ɫ
	setcolor(BLACK);
	//�������ɫ
	setfillcolor(WHITE);
	//��������Σ�������ʾ��Ѫ��
	fillroundrect(
		x, y, x + InitBloodBarLenth, y + height, ellipsewidth, ellipseheight
	);
	//�����ھ��Σ�������ʾ��ǰѪ��
	//Ѫ���ȴ��ڵ�����Ѫ����60%
	if (BloodVolumeRatio >= 0.6) {
		setfillcolor(GREEN);
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
		);
		//����Ѫ��
		*nowblood = *nowblood - Harm;
	}
	//Ѫ���ȴ��ڵ�����Ѫ����30%������С��60%
	else if (BloodVolumeRatio >= 0.3) {
		setfillcolor(RGB(255, 165, 0));
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
		);
		*nowblood = *nowblood - Harm;
	}
	//Ѫ���ȴ��ڵ�����Ѫ��������С��30%
	else if (BloodVolumeRatio >= 0) {
		setfillcolor(RED);
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
		);
		*nowblood = *nowblood - Harm;
	}
	else {
		return false;
	}
	return true;
}
//�������
typedef struct Player {
	//Ѫ������
	int BloodTotal = 100;
	//��ǰѪ��
	int NowBlood = 100;
};
//�������Ұ��
typedef struct Enemy_Boar {
	//Ѫ������
	int BloodTotal = 30;
	//��ǰѪ��
	int NowBlood = 30;
	//Ұ���˺�
	int Harm = 1;
};
int main()
{
	// ������ͼ���ڣ���СΪ 640x480 ����
	initgraph(640, 480);
	//���ñ���ɫΪ��ɫ
	setbkcolor(WHITE);
	// �ñ���ɫ�����Ļ
	cleardevice();
	int Total = 200;
	//��ʼ�����
	Player player;
	//��ʼ������
	Enemy_Boar enemy_Boar;
	//ģ����˹�����ң�����Ѫ�����ƺ���
	while (BloodBarDraw(player.BloodTotal, &player.NowBlood, enemy_Boar.Harm, 300, 250, 30, 15, 15, 100)) {
		Sleep(100);
		cleardevice();
	};
	//�����Ļ(�������������һ������ΪInitBloodBarLenth�������Ѫ��һ������Ϊ0���ھ���Ѫ��)
	cleardevice();
	// �����������
	_getch();
	// �رջ�ͼ����
	closegraph();
	return 0;
}