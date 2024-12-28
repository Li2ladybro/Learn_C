#pragma once
#include "afxdialogex.h"


// CWIN1 对话框

class CWIN1 : public CDialogEx
{
	DECLARE_DYNAMIC(CWIN1)

public:
	CWIN1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CWIN1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WIN1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
