#include<windows.h>
#include <graphics.h>
//��������file_add_over_flag
//������void
//�������ͣ�int
//Function�������Ŀ�ļ����ʧ�ܷ���1����ӳɹ�����0
int file_add_over_flag()
{
	int file_add_over_flag = 0;
	file_add_over_flag = 
		MessageBox(GetForegroundWindow(),
		L"�Ƿ񽫾���Ŀ�ļ�������Ŀ�ļ������˳��������ļ��У�",
		L"��ܰ��ʾ", 4);
	//printf("%d\n", file_add_over_flag);
	if (file_add_over_flag == 7)
	{
		MessageBox(GetForegroundWindow(),
			L"�뽫����Ŀ�ļ�������Ŀ�ļ������˳��������ļ���",
			L"�����ж�", MB_ICONEXCLAMATION);
		MessageBox(GetForegroundWindow(),
			L"�˳�����",
			L"�����ж�", MB_ICONEXCLAMATION);
		return 1;
	}
	else
	{
		return 0;
	}

}
//�������� acqure_max_repetition
//������void
//�������ͣ�int
//Function����������ظ���
int  acqure_max_repetition()
{
	//�����ַ������������������û�����
	wchar_t conversion[10];    //wchar_t�����ַ�
	InputBox(conversion,10, L"����������ظ��ʣ�1....100��������");
	// ���û�����ת��Ϊ����
	int max_repetition = _wtoi(conversion);
	while (max_repetition >100|| max_repetition <= 0)
	{
		MessageBox(GetForegroundWindow(),
			L"�������",
			L"              ", MB_ICONWARNING);
		InputBox(conversion, 10, L"����������뾶");
		max_repetition = _wtoi(conversion);
	}
	return max_repetition;
}





int main() 
{
	int file_add_over_flag=0;
	file_add_over_flag = MessageBox(GetForegroundWindow(),
		L"�Ƿ񽫾���Ŀ�ļ�������Ŀ�ļ������˳��������ļ��У�",
		L"��ܰ��ʾ", 4);
	//printf("%d\n", file_add_over_flag);
	if (file_add_over_flag == 7)
	{
		MessageBox(GetForegroundWindow(),
			L"�뽫����Ŀ�ļ�������Ŀ�ļ������˳��������ļ���",
			L"�����ж�", MB_ICONEXCLAMATION);
		MessageBox(GetForegroundWindow(),
			L"�˳�����",
			L"�����ж�", MB_ICONEXCLAMATION);
		exit(1);
	}
	else
	{
		return 0;
	}

	////x = MessageBox(GetForegroundWindow(), L"�����⡿",L"��Ҫ˵�Ļ���", 2);
	//printf("%d\n", x);
	///*x = MessageBox(GetForegroundWindow(), "�����⡿", "��Ҫ˵�Ļ���", 3);
	//printf("%d\n", x);
	//x = MessageBox(GetForegroundWindow(), "�����⡿", "��Ҫ˵�Ļ���", 4);
	//printf("%d\n", x);
	//x = MessageBox(GetForegroundWindow(), "�����⡿", "��Ҫ˵�Ļ���", 5);
	//printf("%d\n", x);
	//x = MessageBox(GetForegroundWindow(), "�����⡿", "��Ҫ˵�Ļ���", 6);
	//printf("%d\n", x);*/
}