#include <iostream>
#include<string>
#include <windows.h>  //���ͷ�ļ��������
#include <iomanip>
#include <fstream>
using namespace std;
/************************************************************************
//��������wstringTostring
//������wstring
//�������ͣ�string
//Function��wstring->string��ͬ�ַ�������ת��
************************************************************************/
string wstringTostring(wstring wstr)
{
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
	if (len == 0)
		return string("");
	char* psz = new char[len];
	if (!psz)
		return string("");
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, psz, len, NULL, NULL);
	string str(psz);
	delete[] psz;
	psz = NULL;
	return str;
}

/************************************************************************
//��������stringTowstring
//������string 
//�������ͣ�wstring
//Function��string->wstring��ͬ�ַ�������ת��
************************************************************************/
wstring stringTowstring(string str)
{
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	if (len == 0)
		return wstring(L"");
	wchar_t* wct = new wchar_t[len];
	if (!wct)
		return std::wstring(L"");

	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wct, len);
	wstring wstr(wct);
	delete[] wct;
	wct = NULL;
	return wstr;
}

/************************************************************************
//��������wstringTowchar_t 
//������wstring
//�������ͣ�wchar_t 
//Function��wstring->wchar_t ����ת��
************************************************************************/
wchar_t* wstringTowchar_t(wstring str)
{

	int length = 0;
	while (str[length] != '\0')
		length++;
	wchar_t* ps=(wchar_t*)malloc(sizeof(wchar_t) * length);
	for (int i = 0; i < length; i++)
		ps[i] = str[i];
	return ps;
}

int main()
{
	//wcin.imbue(std::locale("chs"));//���������ַ����뷽ʽ
	//wcout.imbue(std::locale("chs"));//���������ַ����뷽ʽ

	string s = "��һ��ǿ�����������";
	wstring str= stringTowstring(s);


	//wstring str = L"��һ��ǿ�����������";
	//wchar_t a[20] = { 0 };
	wchar_t* a= wstringTowchar_t(str);

	//int length = 0;

	//while (str[length] != '\0')
	//	length++;
	////cout << "�ַ���\"";
	////wcout << str;
	////cout << "\"�ĳ���Ϊ" << length << endl;
	//for (int i = 0; i < length; i++)
	//	a[i] = str[i];
	wcout << a;
	cout << endl;
	
	system("pause");
	return 0;
}

//#include <iostream>
//#include<string>
//#include <windows.h>  //���ͷ�ļ��������
//#include <iomanip>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//	wcin.imbue(std::locale("chs"));//���������ַ����뷽ʽ
//	wcout.imbue(std::locale("chs"));//���������ַ����뷽ʽ
//
//	wstring str = L"��һ��ǿ�����������";
//	wchar_t a[20];
//	int length = 0;
//	while (str[length] != '\0')
//		length++;
//	cout << "�ַ���\"";
//	wcout << str;
//	cout << "\"�ĳ���Ϊ" << length << endl;
//	for (int i = 0; i < length; i++)
//		a[i] = str[i];
//	wcout << a;
//	cout << endl;
//	system("pause");
//	return 0;
//}

