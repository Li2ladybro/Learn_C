//#include"title_check.h"
//
//
//
////��������out_button
////��������ť�ṹ��
////����ֵ��void
////Function�����սṹ�����������ť
//void out_button(Button btn)
//{
//	setlinecolor(btn.color_line);  // ���õ�ǰ������ɫ 
//	setfillcolor(btn.color_full);  // ���õ�ǰ�����ɫ 
//	if (!btn.r)
//	{
//		//���û�а뾶�����������ͨ������
//		if (btn.line)//����б߿�
//			fillrectangle(btn.left, btn.top, btn.right, btn.bottom);
//		else
//			solidrectangle(btn.left, btn.top, btn.right, btn.bottom);
//	}
//	else
//	{   //�����Բ�ǳ�����
//		if (btn.line)
//		{
//			//����б߿�
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
//		//��������
//		setbkmode(TRANSPARENT);//����͸������
//		if (btn.tcolor == "red" || btn.tcolor == "RED")
//		{
//			settextcolor(RED);//����������ɫΪ��ɫ
//		}
//		else if (btn.tcolor == "green" || btn.tcolor == "GREEN")
//		{
//			settextcolor(GREEN);//����������ɫΪ��ɫ
//		}
//		else if (btn.tcolor == "blue" || btn.tcolor == "BLUE")
//		{
//			settextcolor(BLUE);//����������ɫΪ��ɫ
//		}
//		else if (btn.tcolor == "yellow" || btn.tcolor == "YELLOW")
//		{
//			settextcolor(YELLOW);//����������ɫΪ��ɫ
//		}
//		else if (btn.tcolor == "black" || btn.tcolor == "BLACK")
//		{
//			settextcolor(BLACK);//����������ɫΪ��ɫ
//		}
//		else if (btn.tcolor == "white" || btn.tcolor == "WHITE")
//		{
//			settextcolor(WHITE);//����������ɫΪ��ɫ
//		}
//
//		else
//		{
//			int x;
//			x = MessageBox(GetForegroundWindow(),
//				TEXT("���鰴ť�߿���ɫ�Ƿ�������ȷ��Ŀǰ������ɫ������red��green��blue��yellow��black��white��"),
//				TEXT("��ť�߿���ɫ���ô���"), 1);
//			cout << x;
//		}
//		//���������ʽ
//		settextstyle(btn.theight, btn.twidth, _T("����"));
//		outtextxy(btn.left + btn.tsetoff, btn.top + btn.tsetoff, btn.text);//������ʾλ��
//	}
//}
//
////��������mouse
////��������ť�ṹ�壬���ΰ�ť�仯��
////����ֵ��int
////Function����������ť�򷵻�0�����򷵻�-1
//int mouse(Button btn, int change)
//{
//	//���ð�ť������Ӧ
//	ExMessage m;                        //����һ����Ϣ����Ϣ
//	m = getmessage(EM_MOUSE);           //��ȡ�����Ϣ  
//	switch (m.message)
//	{
//		//����ƶ�����ťʱ��ť���
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
//				//���ð�ť
//				int pts[] = { btn.left - change ,btn.top - change,  btn.right + change,btn.bottom + change };
//				clearrectangle(pts[0],pts[1],pts[2],pts[3]);
//				loadimage(&sart_bk, L"res\\start_bk.png", 1365, 658);  //����Դ�ļ�����ͼƬ��sart_bk
//				putimage(0, 0,&sart_bk);
//				out_button(btn);
//				clear_flag = 0;
//				return -1;
//			}
//			return -1;
//
//		}
//		//�������ť�˳�ѭ��
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
//				_T("open res\\button_sound.mp3 alias music")   //alias�Ǳ�������˼������Ϳ���ȥֱ����music������button_click _sound.mp3
//				, NULL, 0, NULL
//			);    
//			mciSendString(_T("play music"), NULL, 0, NULL);    //��������
//			return 0;
//		}
//		else
//		{
//
//			if (clear_flag == 1)
//			{
//				//���ð�ť
//				int pts[] = { btn.left - change ,btn.top - change,  btn.right + change,btn.bottom + change };
//				clearrectangle(pts[0], pts[1], pts[2], pts[3]); 
//				loadimage(&sart_bk, L"res\\start_bk.png", 1365, 658);  //����Դ�ļ�����ͼƬ��sart_bk
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
////��������file_add_over_flag
////������void
////�������ͣ�int
////Function�������Ŀ�ļ����ʧ�ܷ���1����ӳɹ�����0
//int file_add_over_flag()
//{
//	int file_add_over_flag = 0;
//	file_add_over_flag =
//		MessageBox
//		(
//			GetForegroundWindow(),
//			L"�Ƿ񽫾���Ŀ�ļ�������Ŀ�ļ������˳��������ļ��У�",
//			L"��ܰ��ʾ",
//			4
//		);
//	if (file_add_over_flag == 7)
//	{
//		MessageBox
//		(
//			GetForegroundWindow(),
//			L"�뽫����Ŀ�ļ�������Ŀ�ļ������˳��������ļ���",
//			L"�����ж�",
//			MB_ICONEXCLAMATION
//		);
//		MessageBox
//		(
//			GetForegroundWindow(),
//			L"�˳�����",
//			L"�����ж�",
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
////�������� acqure_max_repetition
////������void
////�������ͣ�int
////Function����������ظ���
//int  acqure_max_repetition()
//{
//	//�����ַ������������������û�����
//	wchar_t conversion[10];          //wchar_t�����ַ�
//	InputBox
//	(
//	    conversion,
//		10, 
//		L"����������ظ��ʣ�1....100��������"
//	);
//	// ���û�����ת��Ϊ����
//	int max_repetition = _wtoi(conversion);
//	while (max_repetition > 100 || max_repetition <= 0)
//	{
//		MessageBox
//		(
//			GetForegroundWindow(),
//			L"�������",
//			L"              ",
//			MB_ICONWARNING
//		);
//		InputBox
//		(
//			conversion, 
//			10,
//			L"����������뾶"
//		);
//		max_repetition = _wtoi(conversion);
//	}
//	return max_repetition;
//}
//
////��������Inint_File_data
////������File_data*
////�������ͣ�void 
////Function����ʼ���ļ�����
//void Inint_File_data(File_data* ps)
//{
//	ps->_breadth = 100;
//	ps->_capacity = 500;
//	ps->_titles = (char(*)[100])malloc(sizeof(char) * ps->_capacity * ps->_breadth);
//	if (ps->_titles == NULL)
//	{
//		printf("����ռ�ʧ�ܣ��˳�����\n");
//		exit(1);
//	}
//	else
//	{
//		memset(ps->_titles, 0, sizeof(char) * ps->_capacity * ps->_breadth);
//		ps->_Current_line_count = 0;
//	}
//}
//
////��������Write_File_To_Array
////��������ַ���ļ�����ַ����ŵ�ַ
////�������ͣ�int
////Function������Ŀд�����鲢�����ļ�����
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
//	printf("�ļ�һ��%d��\n", ps->_Current_line_count);
//	rewind(f);
//	if (ps->_capacity < ps->_Current_line_count++)
//	{
//		ps->_capacity *= 2;
//		realloc(ps->_titles, sizeof(char) * ps->_capacity * ps->_breadth);
//		printf("���ڴ濪�ٳɹ�\n");
//	}
//	for (rank = 0; rank < ps->_Current_line_count; rank++)
//	{
//		fgets((ps->_titles)[rank], 100, f);
//	}
//	return ps->_Current_line_count;
//}
//
////��������drawGradientBar
////������int���϶������ꣻint����������ȣ�int����������ȣ�����
////����ֵ��void
////Function�����ƽ���ɫ�Ľ�����
//void drawGradientBar(int x, int y, int width, int height, int progress)
//{
//	// ������ɫ��������
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
////����ͬһ�ļ��µ��ظ���
//// �������� se_file_caluatesimilarity
////��������Ŀ��ַ�����Σ��հ�����Ŀ�����Σ���Ŀ��Ŀ�����հ��У�
////�������ͣ�int
////Function������ͬһ�ļ��ظ���
////int se_file_caluatesimilarity(char title[M][N], int bk_count, int line_count)
////{
////	int count1 = 0;      //�����һ����Ŀ��
////	int count2 = 0;      //�ұ�һ����Ŀһһ�Ƚ�
////	int similarity = 0;
////	int sm_count = 0;
////	char reset_arry[2] = "\n";//�ĵ�����
////	for (count1 = 0; count1 < line_count; count1++)
////	{
////		if (strcmp(title[count1], reset_arry) == 0)
////			continue;          //�������Ϊ�հ���������������һ����Ŀ
////		for (count2 = 0; count2 < line_count; count2++)
////		{
////			//����������ĿҲΪ�հ�������������������һ����Ŀ||�����Ŀͬ�еĲ����Ƚ�->û����
////			if ((strcmp(title[count2], reset_arry) == 0) || (count1 == count2))
////				continue;
////			//ֻҪ�ҵ�һ����֮��ͬ����Ŀֱ���˳�ѭ����������һ����Ŀ����
////			if (strcmp(title[count1], title[count2]) == 0)
////			{
////				sm_count++;
////				break;
////			}
////		}
////	}
////	return  sm_count * 100 / (line_count - bk_count);   //һ������Ŀ/�ܵ���Ŀ��Ŀ���������հ��У�
////}
//
