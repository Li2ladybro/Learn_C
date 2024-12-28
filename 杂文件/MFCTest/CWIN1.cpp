// CWIN1.cpp: 实现文件
//

#include "pch.h"
#include "MFCTest.h"
#include "afxdialogex.h"
#include "CWIN1.h"


// CWIN1 对话框

IMPLEMENT_DYNAMIC(CWIN1, CDialogEx)

CWIN1::CWIN1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WIN1, pParent)
{

}

CWIN1::~CWIN1()
{
}

void CWIN1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWIN1, CDialogEx)
END_MESSAGE_MAP()


// CWIN1 消息处理程序
