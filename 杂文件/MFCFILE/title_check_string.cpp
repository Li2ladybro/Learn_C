#include"title_check_string.h"

//��������wstring_to_string
//������wstring
//�������ͣ�string
//Function��wstring->string��ͬ�ַ�������ת��
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

//��������string_to_wstring
//������string 
//�������ͣ�wstring
//Function��string->wstring��ͬ�ַ�������ת��
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

//��������pwchart_to_pchar 
//������wchar_t*
//�������ͣ�char*
//Function��wchar_t* ->char* ����ת��
char* pwchart_to_pchar(wchar_t* pwcstr)
{
	int size = WideCharToMultiByte(CP_OEMCP, 0, pwcstr, wcslen(pwcstr), NULL, 0, NULL, NULL);	//��һ�ε���ȷ��ת�����ֽ��ַ����ĳ��ȣ����ڿ��ٿռ�
	char* pcstr = new char[size + 1];
	WideCharToMultiByte(CP_OEMCP, 0, pwcstr, wcslen(pwcstr), pcstr, size, NULL, NULL);	        //�ڶ��ε��ý�˫�ֽ��ַ���ת���ɵ��ֽ��ַ���
	pcstr[size] = '\0';
	return pcstr;	                                                                            //string pKey = pCStrKey;����ת��Ϊstring�ַ���
}


