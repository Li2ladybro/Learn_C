#include"title_check_string.h"

//函数名：wstring_to_string
//参数：wstring
//返回类型：string
//Function：wstring->string不同字符集类型转化
string wstring_to_string(wstring wstr)
{
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
	if (len == 0)
	{
		return string("");
	}
	char* psz = new char[len];
	if (!psz)
	{
		return string("");
	}
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, psz, len, NULL, NULL);
	string str(psz);
	delete[] psz;
	psz = NULL;
	return str;
}

//函数名：string_to_wstring
//参数：string 
//返回类型：wstring
//Function：string->wstring不同字符集类型转化
wstring string_to_wstring(string str)
{
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	if (len == 0)
	{
		return wstring(L"");
	}
	wchar_t* wct = new wchar_t[len];
	if (!wct)
	{
		return std::wstring(L"");
	}
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wct, len);
	wstring wstr(wct);
	delete[] wct;
	wct = NULL;
	return wstr;
}

//函数名：pwchart_to_pchar 
//参数：wchar_t*
//返回类型：char*
//Function：wchar_t* ->char* 类型转化
char* pwchart_to_pchar(wchar_t* pwcstr)
{
	int size = WideCharToMultiByte(CP_OEMCP, 0, pwcstr, wcslen(pwcstr), NULL, 0, NULL, NULL);	//第一次调用确认转换后单字节字符串的长度，用于开辟空间
	char* pcstr = new char[size + 1];
	WideCharToMultiByte(CP_OEMCP, 0, pwcstr, wcslen(pwcstr), pcstr, size, NULL, NULL);	        //第二次调用将双字节字符串转换成单字节字符串
	pcstr[size] = '\0';
	return pcstr;	                                                                            //string pKey = pCStrKey;可以转换为string字符串
}


