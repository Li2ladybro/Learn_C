
// TestDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Test.h"
#include "TestDlg.h"
#include "afxdialogex.h"

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


// CTestDlg 对话框



CTestDlg::CTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	/*DDX_Text(pDX, IDC_EDIT1,str);
	DDX_Text(pDX, IDC_EDIT2,str2);*/

	DDX_Control(pDX, IDC_COMBO1, m_ComBoxText);
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_EN_CHANGE(IDC_EDIT1, &CTestDlg::OnEnChangeEdit1)
	ON_WM_SIZE()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CTestDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CTestDlg 消息处理程序

BOOL CTestDlg::OnInitDialog()
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

	// 获取所有控件的 ID
	std::vector<int> controlIDs;
	GetAllControlIDs(controlIDs);

	// 输出所有控件的 ID
	for (int id : controlIDs)
	{
		TRACE(_T("Control ID: %d\n"), id);
	}

	// 保存窗口的原始大小
	GetClientRect(&m_originalRect);                  // 获取窗口屏幕坐标

	// 保存所有控件的原始位置和大小
	m_controlInfo.RemoveAll();

	for (int id:
	    {
		IDC_EDIT1, IDC_EDIT2, IDC_BUTTON1,
		IDC_BUTTON2,IDC_BUTTON3
	    }
		) // 替换为你的控件ID
	{
		ControlInfo info;
		info.id = id;                                 //传入id
		GetDlgItem(id)->GetWindowRect(&info.rect);    // 获取控件窗口屏幕坐标
		ScreenToClient(&info.rect);                   // 窗口坐标转化为客户区坐标               
		m_controlInfo.Add(info);                      // 存储控件基本信息
	}

	//添加显示内容
	//m_ComBoxText.AddString(TEXT("C++"));
	//m_ComBoxText.AddString(TEXT("JAVA"));

	//设置默认选项
	m_ComBoxText.SetCurSel(1);

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

//  如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestDlg::OnPaint()
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
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);  // 把框中的内容放到了str中
	//str = str + _T("abc");
	UpdateData(FALSE);
}



void CTestDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// 获取窗口的当前大小
	CRect rect;
	GetClientRect(&rect);

	// 计算缩放比例
	double scaleX = (double)rect.Width() / m_originalRect.Width();
	double scaleY = (double)rect.Height() / m_originalRect.Height();

	// 遍历所有控件并调整它们的大小和位置
	for (int i = 0; i < m_controlInfo.GetSize(); i++)
	{
		ControlInfo& info = m_controlInfo[i];
		CWnd* pWnd = GetDlgItem(info.id);
		if (pWnd != nullptr)
		{
			CRect newRect;
			newRect.left = (int)(info.rect.left * scaleX);
			newRect.top = (int)(info.rect.top * scaleY);
			newRect.right = (int)(info.rect.right * scaleX);
			newRect.bottom = (int)(info.rect.bottom * scaleY);
			pWnd->MoveWindow(newRect);
		}
	}
}

// 获取所有控件id
void CTestDlg::GetAllControlIDs(std::vector<int>& controlIDs)
{
	// 获取对话框的第一个子窗口
	CWnd* pWnd = GetWindow(GW_CHILD);

	// 遍历所有子窗口
	while (pWnd != nullptr)
	{
		// 获取子窗口的控件 ID
		int id = pWnd->GetDlgCtrlID();
		if (id != 0)
		{
			// 将控件 ID 添加到容器中
			controlIDs.push_back(id);
		}

		// 获取下一个子窗口
		pWnd = pWnd->GetWindow(GW_HWNDNEXT);
	}
}

void CTestDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 获取当前索引
	int index = m_ComBoxText.GetCurSel();

	// 获取对应值
	m_ComBoxText.GetLBText(index, comStr);

}
