// CWIN2.cpp: 实现文件
//

#include "pch.h"
#include "MFCTest.h"
#include "afxdialogex.h"
#include "CWIN2.h"


// CWIN2 对话框

IMPLEMENT_DYNAMIC(CWIN2, CDialogEx)

CWIN2::CWIN2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WIN2, pParent)
{

}

CWIN2::~CWIN2()
{
}

void CWIN2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWIN2, CDialogEx)
END_MESSAGE_MAP()


// CWIN2 消息处理程序
