#include <iostream>
#include<string>
#include <windows.h>  //这个头文件必须添加
#include <iomanip>
#include <fstream>
using namespace std;
/************************************************************************
//函数名：wstringTostring
//参数：wstring
//返回类型：string
//Function：wstring->string不同字符集类型转化
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
//函数名：stringTowstring
//参数：string 
//返回类型：wstring
//Function：string->wstring不同字符集类型转化
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
//函数名：wstringTowchar_t 
//参数：wstring
//返回类型：wchar_t 
//Function：wstring->wchar_t 类型转化
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
	//wcin.imbue(std::locale("chs"));//载入中文字符输入方式
	//wcout.imbue(std::locale("chs"));//载入中文字符输入方式

	string s = "有一个强大的祖国在身后";
	wstring str= stringTowstring(s);


	//wstring str = L"有一个强大的祖国在身后";
	//wchar_t a[20] = { 0 };
	wchar_t* a= wstringTowchar_t(str);

	//int length = 0;

	//while (str[length] != '\0')
	//	length++;
	////cout << "字符串\"";
	////wcout << str;
	////cout << "\"的长度为" << length << endl;
	//for (int i = 0; i < length; i++)
	//	a[i] = str[i];
	wcout << a;
	cout << endl;
	
	system("pause");
	return 0;
}

//#include <iostream>
//#include<string>
//#include <windows.h>  //这个头文件必须添加
//#include <iomanip>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//	wcin.imbue(std::locale("chs"));//载入中文字符输入方式
//	wcout.imbue(std::locale("chs"));//载入中文字符输入方式
//
//	wstring str = L"有一个强大的祖国在身后";
//	wchar_t a[20];
//	int length = 0;
//	while (str[length] != '\0')
//		length++;
//	cout << "字符串\"";
//	wcout << str;
//	cout << "\"的长度为" << length << endl;
//	for (int i = 0; i < length; i++)
//		a[i] = str[i];
//	wcout << a;
//	cout << endl;
//	system("pause");
//	return 0;
//}

