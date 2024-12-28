// CFILEWIN.cpp: 实现文件
//

#include "pch.h"
#include "MFCFILE.h"
#include "afxdialogex.h"
#include "CFILEWIN.h"


// CFILEWIN 对话框

IMPLEMENT_DYNAMIC(CFILEWIN, CDialogEx)

CFILEWIN::CFILEWIN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FILEWIN, pParent)
{

}

CFILEWIN::~CFILEWIN()
{
}

void CFILEWIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_ShellTree);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_ShellList);
}


BEGIN_MESSAGE_MAP(CFILEWIN, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_MFCSHELLTREE1, &CFILEWIN::OnTvnSelchangedMfcshelltree1)
	ON_NOTIFY(NM_CLICK, IDC_MFCSHELLLIST1, &CFILEWIN::OnNMClickMfcshelllist1)
END_MESSAGE_MAP()


// CFILEWIN 消息处理程序

// 点击目录树
void CFILEWIN::OnTvnSelchangedMfcshelltree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	// 获取选择的节点
	CString str_path;   // 树文件路径
	m_ShellTree.GetItemPath(str_path, pNMTreeView->itemNew.hItem);  // 获取文件路径
	//MessageBox(str_path);
	m_ShellList.DisplayFolder(str_path);  // 展示当前路径的目录列表
	*pResult = 0;
}

// 点击ShellList组件
void CFILEWIN::OnNMClickMfcshelllist1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString Filename;
	for (int i = 0; i < m_ShellList.GetItemCount(); i++)
	{
		if (m_ShellList.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			m_ShellList.GetItemPath(Filename, i); //获取列表目录路径
			MessageBox(Filename);
			MessageBox(TEXT("已经选中文件："+Filename+", 请退出窗口后点击选择"));
			m_filewin_str = Filename;
		}
	}
	  
	*pResult = 0;
}
