
// TitleCheckDlg.h: 头文件
//

#pragma once
#include "FileWindow.h"
#include "TypeConvert.h"
#include "TitleCheckFileOperate.h"
#include <cstdlib>
#include <filesystem>
using namespace std::filesystem;


// CTitleCheckDlg 对话框
class CTitleCheckDlg : public CDialogEx
{
// 构造
public:
	CTitleCheckDlg(CWnd* pParent = nullptr);	// 标准构造函数

	// 设置透明控件
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	// 旧题目
	afx_msg void OnBnClickedButton1();			// 浏览
	afx_msg void OnBnClickedButton2();			// 查看

	// 文件内容写入编辑框
	void CTitleCheckDlg::write_file_content_to_edit(const char* pc);

	// 新题目
	afx_msg void OnBnClickedButton3();			// 浏览
	afx_msg void OnBnClickedButton4();			// 查看

	// 选择是否进行同文件查重
	afx_msg void OnCbnSelchangeCheckCombo();

	// 开始查重
	afx_msg void OnBnClickedButton5();
	
	// 防止 enter 退出
	void CTitleCheckDlg::OnOK();


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TITLECHECK_DIALOG };
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

	FileWindow fileWindow;		// 资源管理器

	CString old_file_address;   // 旧题目文件地址
	int old_bk_count;           // 旧题目空白行
	int old_se_file_similarity; // 旧题目相似度

	CString new_file_address;   // 新题目文件地址
	int new_bk_count;           // 新题目空白行
	int new_se_file_similarity; // 新题目相似度

	// 最大重复率
	CEdit ce_max_repetition;
	CString max_repetition;

	// 是否进行自身文件查重
	// 是否进行自身文件查重
	CComboBox cc_if_self_check;
	CString if_self_check;

	// 标头
	CFont title_cfont;

	// 旧题目字体
	CFont old_path_cfont;

	// 新题目字体
	CFont new_path_cfont;

	// 最大重复率字体
	CFont max_rep_cfont;

	// 是否需要自查
	CFont check_cfont;

	// 打印窗口
	CFont print_cfont;

	// 开始
	CFont begin_cfont;
		
};
