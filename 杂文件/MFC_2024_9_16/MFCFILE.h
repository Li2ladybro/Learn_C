#pragma once
#include "afxdialogex.h"
#include"afxshelllistctrl.h"
#include"afxshelltreectrl.h"

// MFCFILE 对话框

class MFCFILE : public CDialogEx {
    DECLARE_DYNAMIC(MFCFILE)

public:
    MFCFILE(CWnd* pParent = nullptr); // 标准构造函数
    virtual ~MFCFILE();

    CMFCShellTreeCtrl m_ShellTreeCtrl;
    CMFCShellListCtrl m_ShellListCtrl;
    afx_msg void OnTvnSelchangedMfcshelltree1(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnNMClickMfcshelllist2(NMHDR* pNMHDR, LRESULT* pResult);
    CString& GetStr();

    // 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = MFC_FILE };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 支持

    DECLARE_MESSAGE_MAP()

private:
    CString mf_str;
};
