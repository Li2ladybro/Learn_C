#include<windows.h>
#include <graphics.h>
//函数名：file_add_over_flag
//参数：void
//返回类型：int
//Function：如果题目文件添加失败返回1，添加成功返回0
int file_add_over_flag()
{
	int file_add_over_flag = 0;
	file_add_over_flag = 
		MessageBox(GetForegroundWindow(),
		L"是否将旧题目文件和新题目文件放在了程序所在文件夹？",
		L"温馨提示", 4);
	//printf("%d\n", file_add_over_flag);
	if (file_add_over_flag == 7)
	{
		MessageBox(GetForegroundWindow(),
			L"请将旧题目文件和新题目文件放在了程序所在文件夹",
			L"程序中断", MB_ICONEXCLAMATION);
		MessageBox(GetForegroundWindow(),
			L"退出程序",
			L"程序中断", MB_ICONEXCLAMATION);
		return 1;
	}
	else
	{
		return 0;
	}

}
//函数名： acqure_max_repetition
//参数：void
//返回类型：int
//Function：设置最大重复率
int  acqure_max_repetition()
{
	//定义字符串缓冲区，并接收用户输入
	wchar_t conversion[10];    //wchar_t，宽字符
	InputBox(conversion,10, L"请输入最大重复率（1....100的整数）");
	// 将用户输入转换为数字
	int max_repetition = _wtoi(conversion);
	while (max_repetition >100|| max_repetition <= 0)
	{
		MessageBox(GetForegroundWindow(),
			L"输入错误",
			L"              ", MB_ICONWARNING);
		InputBox(conversion, 10, L"请重新输入半径");
		max_repetition = _wtoi(conversion);
	}
	return max_repetition;
}





int main() 
{
	int file_add_over_flag=0;
	file_add_over_flag = MessageBox(GetForegroundWindow(),
		L"是否将旧题目文件和新题目文件放在了程序所在文件夹？",
		L"温馨提示", 4);
	//printf("%d\n", file_add_over_flag);
	if (file_add_over_flag == 7)
	{
		MessageBox(GetForegroundWindow(),
			L"请将旧题目文件和新题目文件放在了程序所在文件夹",
			L"程序中断", MB_ICONEXCLAMATION);
		MessageBox(GetForegroundWindow(),
			L"退出程序",
			L"程序中断", MB_ICONEXCLAMATION);
		exit(1);
	}
	else
	{
		return 0;
	}

	////x = MessageBox(GetForegroundWindow(), L"【标题】",L"【要说的话】", 2);
	//printf("%d\n", x);
	///*x = MessageBox(GetForegroundWindow(), "【标题】", "【要说的话】", 3);
	//printf("%d\n", x);
	//x = MessageBox(GetForegroundWindow(), "【标题】", "【要说的话】", 4);
	//printf("%d\n", x);
	//x = MessageBox(GetForegroundWindow(), "【标题】", "【要说的话】", 5);
	//printf("%d\n", x);
	//x = MessageBox(GetForegroundWindow(), "【标题】", "【要说的话】", 6);
	//printf("%d\n", x);*/
}