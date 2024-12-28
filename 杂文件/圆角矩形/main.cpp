#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include<stdio.h>
//BloodBarDraw自定义绘制血条函数，返回false代表死亡，血条消失，否则返回true，代表还存活
//BloodTotal //目标总血量
//NowBlood 当前目标血量
//x 血条初始x坐标
//y 血条初始y坐标
//height 血条的高度
//ellipsewidth  圆角矩形血条的圆角的椭圆宽度。
//ellipseheight  圆角矩形血条的圆角的椭圆高度。
//InitBloodBarLenth 设置血条长度
bool BloodBarDraw(int BloodTotal, int* NowBlood, int Harm, int x, int y, int height, int ellipsewidth, int ellipseheight, int InitBloodBarLenth = 200) {
	//获取当前血量
	int* nowblood = NowBlood;
	printf("当前血量：%d\n", *nowblood);
	//计算血量比
	float BloodVolumeRatio = (*nowblood - Harm) * 1.0 / BloodTotal;
	printf("更新后当前血量比：%.2f\n", BloodVolumeRatio);
	//最终血条长度
	int EndBloodBarLenth = BloodVolumeRatio * InitBloodBarLenth;
	//printf("total:%d\n", *total);
	//设置边框色
	setcolor(BLACK);
	//设置填充色
	setfillcolor(WHITE);
	//绘制外矩形，用于显示总血量
	fillroundrect(
		x, y, x + InitBloodBarLenth, y + height, ellipsewidth, ellipseheight
	);
	//绘制内矩形，用于显示当前血量
	//血量比大于等于总血量的60%
	if (BloodVolumeRatio >= 0.6) {
		setfillcolor(GREEN);
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
		);
		//更新血量
		*nowblood = *nowblood - Harm;
	}
	//血量比大于等于总血量的30%，并且小于60%
	else if (BloodVolumeRatio >= 0.3) {
		setfillcolor(RGB(255, 165, 0));
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
		);
		*nowblood = *nowblood - Harm;
	}
	//血量比大于等于总血量，并且小于30%
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
//定义玩家
typedef struct Player {
	//血量总数
	int BloodTotal = 100;
	//当前血量
	int NowBlood = 100;
};
//定义敌人野猪
typedef struct Enemy_Boar {
	//血量总数
	int BloodTotal = 30;
	//当前血量
	int NowBlood = 30;
	//野猪伤害
	int Harm = 1;
};
int main()
{
	// 创建绘图窗口，大小为 640x480 像素
	initgraph(640, 480);
	//设置背景色为白色
	setbkcolor(WHITE);
	// 用背景色清空屏幕
	cleardevice();
	int Total = 200;
	//初始化玩家
	Player player;
	//初始化敌人
	Enemy_Boar enemy_Boar;
	//模拟敌人攻击玩家，调用血条绘制函数
	while (BloodBarDraw(player.BloodTotal, &player.NowBlood, enemy_Boar.Harm, 300, 250, 30, 15, 15, 100)) {
		Sleep(100);
		cleardevice();
	};
	//清空屏幕(清除最后的两个框，一个长度为InitBloodBarLenth的外矩形血条一个长度为0的内矩形血条)
	cleardevice();
	// 按任意键继续
	_getch();
	// 关闭绘图窗口
	closegraph();
	return 0;
}