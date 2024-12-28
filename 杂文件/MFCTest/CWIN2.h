#pragma once
#include "afxdialogex.h"


// CWIN2 对话框

class CWIN2 : public CDialogEx
{
	DECLARE_DYNAMIC(CWIN2)

public:
	CWIN2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CWIN2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WIN2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
