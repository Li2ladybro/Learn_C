
// Calc_TestDlg.h: 头文件
//

#pragma once


// CCalcTestDlg 对话框
class CCalcTestDlg : public CDialogEx
{
// 构造
public:
	CCalcTestDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CString str1;             // 编辑框1中的数字
	CString str2 = L"0";      // 编辑框2中的数字
	CString tempStr = L"";    // 临时结果


public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	CFont m_Font;
	CEdit m_Contro1Edit;
};
