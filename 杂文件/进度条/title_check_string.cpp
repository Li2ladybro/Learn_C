#include"title_check_string.h"
//函数名：wstring_To_string
//参数：wstring
//返回类型：string
//Function：wstring->string不同字符集类型转化
string wstring_To_string(wstring wstr)
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

//函数名：string_To_wstring
//参数：string 
//返回类型：wstring
//Function：string->wstring不同字符集类型转化
wstring string_To_wstring(string str)
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

//函数名：wstring_To_wchar_t 
//参数：wstring
//返回类型：wchar_t 
//Function：wstring->wchar_t 类型转化
wchar_t* wstring_To_wchar_t(wstring str)
{

	int length = 0;
	while (str[length] != '\0')
		length++;
	wchar_t* ps = (wchar_t*)malloc(sizeof(wchar_t) * length);
	if (ps == NULL)
	{
		printf("wstring_To_wchar_t失败\n");
		exit(1);
	}
	for (int i = 0; i < length; i++)
		ps[i] = str[i];
	return ps;
}
#include"title_check_string.h"
//函数名：wstring_To_string
//参数：wstring
//返回类型：string
//Function：wstring->string不同字符集类型转化
string wstring_To_string(wstring wstr)
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

//函数名：string_To_wstring
//参数：string 
//返回类型：wstring
//Function：string->wstring不同字符集类型转化
wstring string_To_wstring(string str)
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

//函数名：wstring_To_wchar_t 
//参数：wstring
//返回类型：wchar_t 
//Function：wstring->wchar_t 类型转化
wchar_t* wstring_To_wchar_t(wstring str)
{

	int length = 0;
	while (str[length] != '\0')
		length++;
	wchar_t* ps = (wchar_t*)malloc(sizeof(wchar_t) * length);
	if (ps == NULL)
	{
		printf("wstring_To_wchar_t失败\n");
		exit(1);
	}
	for (int i = 0; i < length; i++)
		ps[i] = str[i];
	return ps;
}
