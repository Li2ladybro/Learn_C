// FileWindow.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "FileWindow.h"


// FileWindow 对话框

IMPLEMENT_DYNAMIC(FileWindow, CDialogEx)

FileWindow::FileWindow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

FileWindow::~FileWindow()
{
}

void FileWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FileWindow, CDialogEx)
END_MESSAGE_MAP()


// FileWindow 消息处理程序
