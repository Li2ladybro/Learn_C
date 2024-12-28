
// 显示输出结果到编辑框中Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "显示输出结果到编辑框中.h"
#include "显示输出结果到编辑框中Dlg.h"
#include "afxdialogex.h"
#include <string>     //string头文件
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C显示输出结果到编辑框中Dlg 对话框



C显示输出结果到编辑框中Dlg::C显示输出结果到编辑框中Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, file_output_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C显示输出结果到编辑框中Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, file_output_str);
	DDX_Control(pDX, IDC_EDIT2, file_resulet_print_edit);
}

BEGIN_MESSAGE_MAP(C显示输出结果到编辑框中Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C显示输出结果到编辑框中Dlg 消息处理程序

BOOL C显示输出结果到编辑框中Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C显示输出结果到编辑框中Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C显示输出结果到编辑框中Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C显示输出结果到编辑框中Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C显示输出结果到编辑框中Dlg::write_result_to_edit()
{
	int all_count = 10;
	int start = 1;
	string arr[] =
	{
		"基于单片机的智能天然气检测与报警系统设计",
		"基于单片机的智能晾衣控制系统的设计",
		"中、小型企业高速局域网方案设计	",
		"图书馆座位预定系统的设计",
		"《C语言程序设计》课程网站的设计与实现",
		"基于校园网络SAN存储系统设计",
		"基于Java的医院挂号诊疗系统的设计与实现",
		"基于STC89C52单片机的多功能智能床头小夜灯设计",
		 "一种家庭智能药箱系统的设计",
		"田间监控管理系统的设计与实现",
		"数字跳棋游戏的设计与实现",
		"学生考勤系统的设计与实现",
		"基于Java的健身俱乐部管理系统的设计与实现",
		"基于单片机的多功能衣柜设计",
		"基于Java的ATM机管理信息系统的分析与设计"
	};
	CDialogEx m_CDialogEx;
	while (start <= all_count)
	{


		/*std::string str = "xiao";
		CString cstr(str.c_str());*/

		// CString转化为string
		/*string str_img_path = 
			(LPCSTR)(CStringA)(m_str_new);*/

		file_resulet_print_edit = (arr[start].c_str());
		file_resulet_print_edit.Set(file_output_str);
		start++;
	}

}


