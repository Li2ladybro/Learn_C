//#include"title_check.h"
//
//
//
////函数名：out_button
////参数：按钮结构体
////返回值：void
////Function：按照结构体参数制作按钮
//void out_button(Button btn)
//{
//	setlinecolor(btn.color_line);  // 设置当前线条颜色 
//	setfillcolor(btn.color_full);  // 设置当前填充颜色 
//	if (!btn.r)
//	{
//		//如果没有半径，就是输出普通长方体
//		if (btn.line)//如果有边框
//			fillrectangle(btn.left, btn.top, btn.right, btn.bottom);
//		else
//			solidrectangle(btn.left, btn.top, btn.right, btn.bottom);
//	}
//	else
//	{   //输出带圆角长方体
//		if (btn.line)
//		{
//			//如果有边框
//			fillcircle(btn.left + btn.r, btn.top + btn.r, btn.r);
//			fillcircle(btn.left + btn.r, btn.bottom - btn.r, btn.r);
//			fillcircle(btn.right - btn.r, btn.top + btn.r, btn.r);
//			fillcircle(btn.right - btn.r, btn.bottom - btn.r, btn.r);
//			solidrectangle(btn.left, btn.top + btn.r, btn.right, btn.bottom - btn.r);
//			solidrectangle(btn.left + btn.r, btn.top, btn.right - btn.r, btn.bottom);
//			::line(btn.left + btn.r, btn.top, btn.right - btn.r, btn.top);
//			::line(btn.left + btn.r, btn.bottom, btn.right - btn.r, btn.bottom);
//			::line(btn.left, btn.top + btn.r, btn.left, btn.bottom - btn.r);
//			::line(btn.right, btn.top + btn.r, btn.right, btn.bottom - btn.r);
//		}
//		else
//		{
//			solidrectangle(btn.left, btn.top + btn.r, btn.right, btn.bottom - btn.r);
//			solidrectangle(btn.left + btn.r, btn.top, btn.right - btn.r, btn.bottom);
//			solidcircle(btn.left + btn.r, btn.top + btn.r, btn.r);
//			solidcircle(btn.left + btn.r, btn.bottom - btn.r, btn.r);
//			solidcircle(btn.right - btn.r, btn.top + btn.r, btn.r);
//			solidcircle(btn.right - btn.r, btn.bottom - btn.r, btn.r);
//		}
//	}
//	if (btn.T_flag == 1)
//	{
//		//设置字体
//		setbkmode(TRANSPARENT);//设置透明字体
//		if (btn.tcolor == "red" || btn.tcolor == "RED")
//		{
//			settextcolor(RED);//设置字体颜色为红色
//		}
//		else if (btn.tcolor == "green" || btn.tcolor == "GREEN")
//		{
//			settextcolor(GREEN);//设置字体颜色为红色
//		}
//		else if (btn.tcolor == "blue" || btn.tcolor == "BLUE")
//		{
//			settextcolor(BLUE);//设置字体颜色为红色
//		}
//		else if (btn.tcolor == "yellow" || btn.tcolor == "YELLOW")
//		{
//			settextcolor(YELLOW);//设置字体颜色为黄色
//		}
//		else if (btn.tcolor == "black" || btn.tcolor == "BLACK")
//		{
//			settextcolor(BLACK);//设置字体颜色为黑色
//		}
//		else if (btn.tcolor == "white" || btn.tcolor == "WHITE")
//		{
//			settextcolor(WHITE);//设置字体颜色为白色
//		}
//
//		else
//		{
//			int x;
//			x = MessageBox(GetForegroundWindow(),
//				TEXT("请检查按钮边框颜色是否设置正确，目前字体颜色包含：red、green、blue、yellow、black、white。"),
//				TEXT("按钮边框颜色设置错误"), 1);
//			cout << x;
//		}
//		//设置字体格式
//		settextstyle(btn.theight, btn.twidth, _T("宋体"));
//		outtextxy(btn.left + btn.tsetoff, btn.top + btn.tsetoff, btn.text);//设置显示位置
//	}
//}
//
////函数名：mouse
////参数：按钮结构体，整形按钮变化量
////返回值：int
////Function：如果点击按钮则返回0，否则返回-1
//int mouse(Button btn, int change)
//{
//	//设置按钮交互响应
//	ExMessage m;                        //定义一个消息变量息
//	m = getmessage(EM_MOUSE);           //获取鼠标消息  
//	switch (m.message)
//	{
//		//鼠标移动到按钮时按钮变大
//	    case WM_MOUSEMOVE:
//		if (m.x >= btn.left && m.x <= btn.right && m.y >= btn.top && m.y <= btn.bottom)
//		{
//			clear_flag = 1;
//			btn.left = btn.left - change;
//			btn.top -= change;
//			btn.right += change;
//			btn.bottom += change;
//			out_button(btn);
//			return -1;
//		}
//		else
//		{
//			if (clear_flag == 1)
//			{
//				//重置按钮
//				int pts[] = { btn.left - change ,btn.top - change,  btn.right + change,btn.bottom + change };
//				clearrectangle(pts[0],pts[1],pts[2],pts[3]);
//				loadimage(&sart_bk, L"res\\start_bk.png", 1365, 658);  //从资源文件载入图片到sart_bk
//				putimage(0, 0,&sart_bk);
//				out_button(btn);
//				clear_flag = 0;
//				return -1;
//			}
//			return -1;
//
//		}
//		//鼠标点击按钮退出循环
//	    case WM_LBUTTONDOWN:
//		if (m.x >= btn.left && m.x <= btn.right && m.y >= btn.top && m.y <= btn.bottom)
//		{
//			clear_flag = 1;
//			btn.left = btn.left - change;
//			btn.top -= change;
//			btn.right += change;
//			btn.bottom += change;
//			out_button(btn);
//			mciSendString
//			(
//				_T("open res\\button_sound.mp3 alias music")   //alias是别名的意思，下面就可以去直接用music来代替button_click _sound.mp3
//				, NULL, 0, NULL
//			);    
//			mciSendString(_T("play music"), NULL, 0, NULL);    //播放音乐
//			return 0;
//		}
//		else
//		{
//
//			if (clear_flag == 1)
//			{
//				//重置按钮
//				int pts[] = { btn.left - change ,btn.top - change,  btn.right + change,btn.bottom + change };
//				clearrectangle(pts[0], pts[1], pts[2], pts[3]); 
//				loadimage(&sart_bk, L"res\\start_bk.png", 1365, 658);  //从资源文件载入图片到sart_bk
//				putimage(0, 0, &sart_bk);
//				out_button(btn);
//				clear_flag = 0;
//				return -1;
//			}
//			return -1;
//		}
//	}
//}
//
////函数名：file_add_over_flag
////参数：void
////返回类型：int
////Function：如果题目文件添加失败返回1，添加成功返回0
//int file_add_over_flag()
//{
//	int file_add_over_flag = 0;
//	file_add_over_flag =
//		MessageBox
//		(
//			GetForegroundWindow(),
//			L"是否将旧题目文件和新题目文件放在了程序所在文件夹？",
//			L"温馨提示",
//			4
//		);
//	if (file_add_over_flag == 7)
//	{
//		MessageBox
//		(
//			GetForegroundWindow(),
//			L"请将旧题目文件和新题目文件放在了程序所在文件夹",
//			L"程序中断",
//			MB_ICONEXCLAMATION
//		);
//		MessageBox
//		(
//			GetForegroundWindow(),
//			L"退出程序",
//			L"程序中断",
//			MB_ICONEXCLAMATION
//		);
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//
////函数名： acqure_max_repetition
////参数：void
////返回类型：int
////Function：设置最大重复率
//int  acqure_max_repetition()
//{
//	//定义字符串缓冲区，并接收用户输入
//	wchar_t conversion[10];          //wchar_t，宽字符
//	InputBox
//	(
//	    conversion,
//		10, 
//		L"请输入最大重复率（1....100的整数）"
//	);
//	// 将用户输入转换为数字
//	int max_repetition = _wtoi(conversion);
//	while (max_repetition > 100 || max_repetition <= 0)
//	{
//		MessageBox
//		(
//			GetForegroundWindow(),
//			L"输入错误",
//			L"              ",
//			MB_ICONWARNING
//		);
//		InputBox
//		(
//			conversion, 
//			10,
//			L"请重新输入半径"
//		);
//		max_repetition = _wtoi(conversion);
//	}
//	return max_repetition;
//}
//
////函数名：Inint_File_data
////参数：File_data*
////返回类型：void 
////Function：初始化文件数据
//void Inint_File_data(File_data* ps)
//{
//	ps->_breadth = 100;
//	ps->_capacity = 500;
//	ps->_titles = (char(*)[100])malloc(sizeof(char) * ps->_capacity * ps->_breadth);
//	if (ps->_titles == NULL)
//	{
//		printf("申请空间失败，退出程序\n");
//		exit(1);
//	}
//	else
//	{
//		memset(ps->_titles, 0, sizeof(char) * ps->_capacity * ps->_breadth);
//		ps->_Current_line_count = 0;
//	}
//}
//
////函数名：Write_File_To_Array
////参数：地址：文件；地址：存放地址
////返回类型：int
////Function：将题目写入数组并返回文件行数
//int Write_File_To_Array(FILE* f, File_data* ps)
//{
//	int rank = 0;
//	int forcecasting = 0;
//	while ((forcecasting = fgetc(f)) != EOF)
//	{
//		if (forcecasting == '\n')
//		{
//			ps->_Current_line_count++;
//		}
//
//	}
//	printf("文件一共%d行\n", ps->_Current_line_count);
//	rewind(f);
//	if (ps->_capacity < ps->_Current_line_count++)
//	{
//		ps->_capacity *= 2;
//		realloc(ps->_titles, sizeof(char) * ps->_capacity * ps->_breadth);
//		printf("新内存开辟成功\n");
//	}
//	for (rank = 0; rank < ps->_Current_line_count; rank++)
//	{
//		fgets((ps->_titles)[rank], 100, f);
//	}
//	return ps->_Current_line_count;
//}
//
////函数名：drawGradientBar
////参数：int：上顶点坐标；int：进度条宽度；int：进度条宽度；增量
////返回值：void
////Function：绘制渐变色的进度条
//void drawGradientBar(int x, int y, int width, int height, int progress)
//{
//	// 定义颜色渐变数组
//	int gradientColors[] = { RGB(255, 0, 0), RGB(255, 255, 0), RGB(0, 255, 0), RGB(0, 255, 255), RGB(0, 0, 255), RGB(75, 0, 130) };
//	for (int i = 0; i < height; i++)
//	{
//		double ratio = (double)i / height;
//		COLORREF color = RGB
//		(
//			(int)(gradientColors[0] * (1 - ratio) + gradientColors[1] * ratio),
//			(int)(gradientColors[3] * (1 - ratio) + gradientColors[4] * ratio),
//			(int)(gradientColors[2] * (1 - ratio) + gradientColors[5] * ratio)
//		);
//		setfillcolor(color);
//		solidrectangle(x, y + i, x + progress, y + i + 1);
//	}
//}
//
////计算同一文件下的重复率
//// 函数名： se_file_caluatesimilarity
////参数：题目地址，整形：空白行数目，整形：题目数目（含空白行）
////返回类型：int
////Function：计算同一文件重复度
////int se_file_caluatesimilarity(char title[M][N], int bk_count, int line_count)
////{
////	int count1 = 0;      //从左边一列题目与
////	int count2 = 0;      //右边一列题目一一比较
////	int similarity = 0;
////	int sm_count = 0;
////	char reset_arry[2] = "\n";//文档空行
////	for (count1 = 0; count1 < line_count; count1++)
////	{
////		if (strcmp(title[count1], reset_arry) == 0)
////			continue;          //如果此行为空白行则跳过访问下一个题目
////		for (count2 = 0; count2 < line_count; count2++)
////		{
////			//如果对面的题目也为空白行则跳过继续访问下一个题目||与此题目同行的不做比较->没意义
////			if ((strcmp(title[count2], reset_arry) == 0) || (count1 == count2))
////				continue;
////			//只要找到一个与之相同的题目直接退出循环，进行下一个题目遍历
////			if (strcmp(title[count1], title[count2]) == 0)
////			{
////				sm_count++;
////				break;
////			}
////		}
////	}
////	return  sm_count * 100 / (line_count - bk_count);   //一样的题目/总的题目数目（不包含空白行）
////}
//
