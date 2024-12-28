#pragma once
#include <iostream>
#include<string>
#include <windows.h>  //这个头文件必须添加
#include <iomanip>
#include <fstream>
using namespace std;
/************************************************************************
//函数名：wstring_To_string
//参数：wstring
//返回类型：string
//Function：wstring->string不同字符集类型转化
************************************************************************/
string wstring_To_string(wstring wstr);

/************************************************************************
//函数名：stringTowstring
//参数：string
//返回类型：wstring
//Function：string->wstring不同字符集类型转化
************************************************************************/
wstring string_To_wstring(string str);

/************************************************************************
//函数名：wstring_To_wchar_t
//参数：wstring
//返回类型：wchar_t
//Function：wstring->wchar_t 类型转化
************************************************************************/
wchar_t* wstring_To_wchar_t(wstring str);