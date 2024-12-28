
// MFCFILEDlg.h: 头文件
//

#pragma once
#include "CFILEWIN.h"
//#include <vector>

//// 控件信息
//typedef struct ControlInfo
//{
//	int id;
//	CRect originalRect;     // 控件的原始位置和大小
//	CFont* originalFont;    // 控件的原始字体
//	int originalFontSize;   // 控件的原始字体大小
//}ControlInfo;

// CMFCFILEDlg 对话框
class CMFCFILEDlg : public CDialogEx
{
// 构造
public:
	CMFCFILEDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCFILE_DIALOG };
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

// 添加 CFILEWIN 类成员cf
private:
	CFILEWIN cf;  
public:
	CString m_str_old;      // 旧题目文件地址
	CEdit m_edit_old;       // 旧边框
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	//afx_msg void OnBnClickedButton3();

	CString m_str_new;    // 新题目文件地址
	CEdit m_edit_new;     // 旧边框

	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	//afx_msg void OnBnClickedButton6();
	
	// 获取最大重复率
	int max_repetition;

	// 字符类型最大重复度
	CString str_max_repetition;

	int temp;
	afx_msg void OnEnChangeEdit5();

	// 字符类型最大重复度

	afx_msg void OnEnChangeEdit6();
	// 是否对原文件进行查重
	CComboBox m_ComBoxText;
	CString com_str;
	afx_msg void OnCbnSelchangeCombo1();

	// 进度条
	CProgressCtrl progress_bar;

//public:
//	// 声明 GetAllControlIDs 函数 
//	// 获取所有组件id
//	void GetAllControlIDs(std::vector<int>& controlIDs);
//
//	CRect m_originalRect; // 保存窗口的原始大小
//	CArray<ControlInfo> m_controlInfo; // 保存所有控件的原始位置、大小和字体信息
//
//	// 通过id使得控件自适应窗体大小
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	void CMFCFILEDlg::OnDestroy();
	
	
};
