// FileWindow.cpp: 实现文件
//

#include "pch.h"
#include "TitleCheck.h"
#include "afxdialogex.h"
#include "FileWindow.h"


// FileWindow 对话框

IMPLEMENT_DYNAMIC(FileWindow, CDialogEx)

FileWindow::FileWindow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FileWindow_DIALOG, pParent)
{

}

FileWindow::~FileWindow()
{
}

void FileWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_ShellTreeCtrl);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_ShellListCtrl);
}


BEGIN_MESSAGE_MAP(FileWindow, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_MFCSHELLTREE1, &FileWindow::OnTvnSelchangedMfcshelltree1)
	ON_NOTIFY(NM_CLICK, IDC_MFCSHELLLIST1, &FileWindow::OnNMClickMfcshelllist1)
END_MESSAGE_MAP()


// FileWindow 消息处理程序

// 点击目录树
void FileWindow::OnTvnSelchangedMfcshelltree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	// 获取选择的节点
	CString str_path;												     // 树文件路径
	m_ShellTreeCtrl.GetItemPath(str_path,pNMTreeView->itemNew.hItem);	 // 获取文件路径
	m_ShellListCtrl.DisplayFolder(str_path);							 // 展示当前路径的目录列表

	*pResult = 0;
}

// 点击ShellList组件
void FileWindow::OnNMClickMfcshelllist1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	CString fileName;
	for (int start = 0; start < m_ShellListCtrl.GetItemCount(); start++) 
	{
		if (m_ShellListCtrl.GetItemState(start, LVIS_SELECTED) ==LVIS_SELECTED)
		{
			m_ShellListCtrl.GetItemPath(fileName, start); // 获取列表目录路径

			// 地址抛错误
			if (fileName.Mid(fileName.GetLength() - 4, 4) != ".txt") 
			{
				// 取末尾最后四个字符
				MessageBox(L"请选择有效的题目文件地址！");
				return;
			}
			else
			{
				fileAddress = fileName;
				MessageBox(TEXT("已经选中文件：" + fileName));
			}
		}
	}

	*pResult = 0;
}

// 返回地址
CString& FileWindow::GetFileAddess() { return fileAddress; }