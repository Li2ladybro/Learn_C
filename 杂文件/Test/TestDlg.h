
// TestDlg.h: 头文件
//

#pragma once
#include <initializer_list>
#include <vector>
typedef struct ControlInfo
{
	int id;      // 控件 id
	CRect rect;  // 控件大小
}ControlInfo;

// CTestDlg 对话框
class CTestDlg : public CDialogEx
{
	// 构造
public:
	CTestDlg(CWnd* pParent = nullptr);	// 标准构造函数

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_DIALOG };
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
public:
	afx_msg void OnEnChangeEdit1();
	//private: 
	//	// 主界面的编辑框
	//	CString str;
	//	CString str2;
	//public:
	//	afx_msg void OnBnClickedButton1();
	//	afx_msg void OnBnClickedButton2();

protected:
	CRect m_originalRect;              // 保存窗口的原始大小
	CArray<ControlInfo> m_controlInfo; // 保存所有控件的原始位置和大小

protected:
	afx_msg void OnSize(UINT nType, int cx, int cy);

public:
	// 声明 GetAllControlIDs 函数 
	// 获取所有组件id
	void GetAllControlIDs(std::vector<int>& controlIDs);

	afx_msg void OnCbnSelchangeCombo1();

	// 通过ComboBox获取选择的值存在comStr中
	CComboBox m_ComBoxText;
	CString comStr;     
};
