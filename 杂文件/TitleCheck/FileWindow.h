#pragma once
#include "afxdialogex.h"


// FileWindow 对话框

class FileWindow : public CDialogEx
{
	DECLARE_DYNAMIC(FileWindow)

public:
	FileWindow(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~FileWindow();
	afx_msg void OnTvnSelchangedMfcshelltree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMClickMfcshelllist1(NMHDR* pNMHDR, LRESULT* pResult);
	CString& FileWindow::GetFileAddess();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FileWindow_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
 
private:
	CMFCShellTreeCtrl m_ShellTreeCtrl;
	CMFCShellListCtrl m_ShellListCtrl;
	CString fileAddress;
};
