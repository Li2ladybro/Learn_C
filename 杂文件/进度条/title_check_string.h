#pragma once
#include <iostream>
#include<string>
#include <windows.h>  //���ͷ�ļ��������
#include <iomanip>
#include <fstream>
using namespace std;
/************************************************************************
//��������wstring_To_string
//������wstring
//�������ͣ�string
//Function��wstring->string��ͬ�ַ�������ת��
************************************************************************/
string wstring_To_string(wstring wstr);

/************************************************************************
//��������stringTowstring
//������string
//�������ͣ�wstring
//Function��string->wstring��ͬ�ַ�������ת��
************************************************************************/
wstring string_To_wstring(string str);

/************************************************************************
//��������wstring_To_wchar_t
//������wstring
//�������ͣ�wchar_t
//Function��wstring->wchar_t ����ת��
************************************************************************/
wchar_t* wstring_To_wchar_t(wstring str);