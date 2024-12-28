
// MFCFILEDlg.cpp: 实现文件
//

#define _CRT_SECURE_NO_DEPRECATE

#include "pch.h"
#include "framework.h"
#include "MFCFILE.h"
#include "MFCFILEDlg.h"
#include "afxdialogex.h"
#include "inint.h"
#include"title_check_file.h"

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

// CMFCFILEDlg 对话框
CMFCFILEDlg::CMFCFILEDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCFILE_DIALOG, pParent)
	, m_str_old(_T(""))
	, m_str_new(_T(""))
	, max_repetition(0)
	, str_max_repetition(_T(""))
	, temp(0)
	, com_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCFILEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str_old);  // 编辑框值类型的变量，自动绑定
	DDX_Control(pDX, IDC_EDIT1, m_edit_old);
	DDX_Text(pDX, IDC_EDIT2, m_str_new);
	DDX_Control(pDX, IDC_EDIT2, m_edit_new);
	DDX_Text(pDX, IDC_EDIT4, str_max_repetition);
	DDX_Text(pDX, IDC_EDIT5, temp);
	//DDX_Text(pDX, IDC_EDIT6, str_max_repetition);
	DDX_Control(pDX, IDC_COMBO1, m_ComBoxText);
	DDX_CBString(pDX, IDC_COMBO1, com_str);
	DDX_Control(pDX, IDC_PROGRESS1, progress_bar);
}

BEGIN_MESSAGE_MAP(CMFCFILEDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCFILEDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCFILEDlg::OnBnClickedButton2)
	//ON_BN_CLICKED(IDC_BUTTON3, &CMFCFILEDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCFILEDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCFILEDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCFILEDlg::OnBnClickedButton5)
	//ON_BN_CLICKED(IDC_BUTTON6, &CMFCFILEDlg::OnBnClickedButton6)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCFILEDlg::OnEnChangeEdit2)
	ON_WM_SIZE()

	ON_EN_CHANGE(IDC_EDIT5, &CMFCFILEDlg::OnEnChangeEdit5)
	//ON_EN_CHANGE(IDC_EDIT6, &CMFCFILEDlg::OnEnChangeEdit6)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCFILEDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CMFCFILEDlg 消息处理程序

BOOL CMFCFILEDlg::OnInitDialog()
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
	
	progress_bar.SetRange(0, 100);  // 设置进度条范围
	progress_bar.SetPos(0);

	//// 获取所有控件的 ID
	//std::vector<int> controlIDs;
	//GetAllControlIDs(controlIDs);
	//
	// // 保存窗口的原始大小
	//GetClientRect(&m_originalRect);

	//// 保存所有控件的原始位置、大小和字体信息
	//m_controlInfo.RemoveAll();
	//for (int id : controlIDs) // 替换为你的控件ID数组
	//{
	//	ControlInfo info;
	//	info.id = id;
	//	GetDlgItem(id)->GetWindowRect(&info.originalRect);
	//	ScreenToClient(&info.originalRect);

	//	// 获取控件的原始字体
	//	CFont* pFont = GetDlgItem(id)->GetFont();
	//	LOGFONT lf;
	//	pFont->GetLogFont(&lf);
	//	info.originalFontSize = lf.lfHeight;
	//	info.originalFont = new CFont();
	//	info.originalFont->CreateFontIndirect(&lf);

	//	m_controlInfo.Add(info);
	//}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCFILEDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCFILEDlg::OnPaint()
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
HCURSOR CMFCFILEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 旧题目
void CMFCFILEDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

// 点击浏览按钮
void CMFCFILEDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	cf.DoModal();  //打开资源管理器
}

// 选择按钮事件
void CMFCFILEDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str_old = cf.m_filewin_str;    // 获取旧题目文件地址
	//UpdateData(0);                 //  刷新：将值写入编辑框
	m_edit_old.SetWindowTextW(m_str_old);

	file_data* oldtitle = (file_data*)malloc(sizeof(file_data));  //旧文件接口,向堆区申请内存
	
	if (oldtitle == NULL)
	{
		//MessageBox(L"内存不足!", TEXT("警告")，MB_OKCANCEL | MB_ICONSTOP);
		MessageBox(_T("内存不足!"), _T("程序中断"), MB_OK | MB_ICONSTOP);
		exit(1);
	}
	// CString转化为char*
	USES_CONVERSION;
	char* old_file_address= W2A(m_str_old);

	FILE* old_fi = fopen(old_file_address, "r");                  //打开旧题目文件

	if (old_fi == NULL)
	{
		MessageBox
		(
			L"旧题目文件打开失败！",
			L"程序中断",
			MB_OK | MB_ICONSTOP
		);
		exit(1);
	}
	else
	{
		// 先初始化old_fi
		inint_file_data(oldtitle);
		// 写入数组
		write_file_to_array(old_fi, oldtitle);
	}

	if (fclose(old_fi) != NULL)
	{
		MessageBox
		(
			L"旧题目文件关闭失败!",
			L"程序中断",
			MB_OK | MB_ICONSTOP
		);
		exit(1);
	}

	////统计空白行
	//int old_bk_count = bk_caluate(oldtitle);

	//int old_se_file_similarity = se_file_caluatesimilarity(oldtitle, old_bk_count);

	free(oldtitle);       // 释放空间


	//CString cstr = _T("test")
	//	//声明标识
	//	USES_CONVERSION;
	////函数T2A和W2A均支持ATL和MFC中的字符
	//char* pFileName = T2A(cstr);
	////char * pFileName = W2A(cstr); //也可实现转换

	//注意：有时候可能还需要添加引用#include <afxpriv.h>

}

//// 打开按钮事件
//void CMFCFILEDlg::OnBnClickedButton3()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(1);    // m_str
//	// CString转化为string
//	string str_img_path = (LPCSTR)(CStringA)(m_str_old);
//	Mat image = imread(str_img_path);
//	if (image.empty())
//	{
//		MessageBox(L"图像不存在!", TEXT("提示"));
//		// 退出
//		CDialogEx::OnOK();
//	}
//	else
//	{
//		namedWindow("展示图像", WINDOW_AUTOSIZE);
//		imshow("展示图像", image);
//		waitKey(0);
//		destroyAllWindows();
//	}
//
//}

// 新题目
void CMFCFILEDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

// 点击浏览按钮
void CMFCFILEDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	cf.DoModal();
}

// 选择按钮事件
void CMFCFILEDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str_new = cf.m_filewin_str;
	//UpdateData(0);   //  刷新：将值写入编辑框
	m_edit_new.SetWindowTextW(m_str_new);

	file_data* newtitle = (file_data*)malloc(sizeof(file_data));  //旧文件接口,向堆区申请内存
	
	if (newtitle == NULL)
	{
		//MessageBox(L"内存不足!", TEXT("警告")，MB_OKCANCEL | MB_ICONSTOP);
		MessageBox(_T("内存不足!"), _T("程序中断"), MB_OK | MB_ICONSTOP);
		exit(1);
	}

	// CString转化为char*
	USES_CONVERSION;
	char* new_file_address = W2A(m_str_old);
	
	FILE* new_fi = fopen(new_file_address, "r");    //打开旧题目文件

	if (new_fi == NULL)
	{
		MessageBox
		(
			L"新题目文件打开失败！",
			L"程序中断",
			MB_OK | MB_ICONSTOP
		);
		exit(1);
	}
	else
	{
		// 先初始化new_fi
		inint_file_data(newtitle);

		// 写入数组
		write_file_to_array(new_fi, newtitle);
	}

	if (fclose(new_fi) != NULL)
	{
		MessageBox
		(
			L"新题目文件关闭失败!",
			L"程序中断",
			MB_OK | MB_ICONSTOP
		);
		exit(1);
	}

	free(newtitle);       // 释放空间
}

//// 打开按钮事件
//void CMFCFILEDlg::OnBnClickedButton6()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(1);    // m_str
//	// CString转化为string
//	string str_img_path = (LPCSTR)(CStringA)(m_str_new);
//	Mat image = imread(str_img_path);
//	if (image.empty())
//	{
//		MessageBox(L"图像不存在!", TEXT("提示"));
//		// 退出
//		CDialogEx::OnOK();
//	}
//	else
//	{
//		namedWindow("展示图像", WINDOW_AUTOSIZE);
//		imshow("展示图像", image);
//		waitKey(0);
//		destroyAllWindows();
//	}
//}

//// 获取所有控件id
//void CMFCFILEDlg::GetAllControlIDs(std::vector<int>& controlIDs)
//{
//	// 获取对话框的第一个子窗口
//	CWnd* pWnd = GetWindow(GW_CHILD);
//
//	// 遍历所有子窗口
//	while (pWnd != nullptr)
//	{
//		// 获取子窗口的控件 ID
//		int id = pWnd->GetDlgCtrlID();
//		if (id != 0)
//		{
//			// 将控件 ID 添加到容器中
//			controlIDs.push_back(id);
//		}
//
//		// 获取下一个子窗口
//		pWnd = pWnd->GetWindow(GW_HWNDNEXT);
//	}
//}

//// 修改控件大小使得他们自适应窗口大小
//void CMFCFILEDlg::OnSize(UINT nType, int cx, int cy)
//{
//	CDialogEx::OnSize(nType, cx, cy);
//
//	// TODO: 在此处添加消息处理程序代码
//	// 获取窗口的当前客户区大小
//	CRect newRect;
//	GetClientRect(&newRect);
//
//	// 计算缩放比例
//	double scaleX = static_cast<double>(newRect.Width()) / m_originalRect.Width();
//	double scaleY = static_cast<double>(newRect.Height()) / m_originalRect.Height();
//
//	// 调整所有控件的位置、大小和字体大小
//	for (int i = 0; i < m_controlInfo.GetSize(); ++i)
//	{
//		ControlInfo& info = m_controlInfo[i];
//		CRect newControlRect;
//
//		// 根据缩放比例计算新的位置和大小
//		newControlRect.left = static_cast<int>(info.originalRect.left * scaleX);
//		newControlRect.top = static_cast<int>(info.originalRect.top * scaleY);
//		newControlRect.right = static_cast<int>(info.originalRect.right * scaleX);
//		newControlRect.bottom = static_cast<int>(info.originalRect.bottom * scaleY);
//
//		// 调整控件的位置和大小
//		GetDlgItem(info.id)->MoveWindow(&newControlRect);
//
//		// 调整字体大小
//		LOGFONT lf;
//		info.originalFont->GetLogFont(&lf);
//		lf.lfHeight = static_cast<int>(info.originalFontSize * scaleY);
//		CFont newFont;
//		newFont.CreateFontIndirect(&lf);
//		GetDlgItem(info.id)->SetFont(&newFont);
//	}
//}

//// 清理保存的字体资源
//void CMFCFILEDlg::OnDestroy()
//{
//	CMFCFILEDlg::OnDestroy();
//
//	// 清理保存的字体资源
//	for (int i = 0; i < m_controlInfo.GetSize(); ++i)
//	{
//		delete m_controlInfo[i].originalFont;
//	}
//}




//void CMFCFILEDlg::OnEnUpdateEdit4()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
//	// 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//	// 
//	// 获取编辑框的指针
//	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
//	if (pEdit != nullptr)
//	{
//		// 获取编辑框的内容
//		pEdit->GetWindowText(str_max_repetition);
//
//		// 尝试将字符串转换为整数
//		int max_repetition = _ttoi(str_max_repetition);
//
//		// 检查输入的值是否在 1 到 100 之间
//		if (max_repetition < 1 || max_repetition > 100)
//		{
//			// 显示错误提示
//			AfxMessageBox(_T("请输入 1 到 100 之间的数字"));
//
//			// 清除编辑框的内容
//			pEdit->SetWindowText(_T(""));
//			// 将焦点设置回编辑框，允许用户重新输入
//			GetDlgItem(IDC_EDIT4)->SetFocus();
//			return;
//		}
//		
//	}
//}


//void CMFCFILEDlg::OnEnChangeEdit4()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//
//	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
//	if (pEdit != nullptr)
//	{
//		// 获取编辑框的内容
//		pEdit->GetWindowText(str_max_repetition);
//
//		// 尝试将字符串转换为整数
//		int max_repetition = _ttoi(str_max_repetition);
//
//		// 检查输入的值是否在 1 到 100 之间
//		if (max_repetition < 1 || max_repetition > 100)
//		{
//			// 显示错误提示
//			AfxMessageBox(_T("请输入 1 到 100 之间的数字"));
//
//			// 清除编辑框的内容
//			pEdit->SetWindowText(_T(""));
//		}
//	}
//}


//void CMFCFILEDlg::OnEnChangeEdit5()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//	 
//	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
//	// 检查输入的值是否在 1 到 100 之间
//	if (temp < 1 || temp > 100)
//	{
//		// 显示错误提示
//		AfxMessageBox(_T("请输入 1 到 100 之间的数字"));
//
//		// 清除编辑框的内容
//		//pEdit->SetWindowText(_T(""));
//	}
//	
//		/*CString csTemp;
//		GetWindowText(csTemp);
//		int intNo = _tstoi(csTemp);
//		CString sNo;
//		sNo.Format(_T("%d"), intNo);
//		if (sNo != csTemp)
//		{
//			SetWindowText(sNo);
//		}*/
//}


//void CMFCFILEDlg::OnEnChangeEdit6()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//
//	//CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT6);
//	if (pEdit != nullptr)
//	{
//		// 获取编辑框的内容
//		pEdit->GetWindowText(str_max_repetition);
//
//		// 尝试将字符串转换为整数
//		int max_repetition = _ttoi(str_max_repetition);
//
//		// 检查输入的值是否在 1 到 100 之间
//		if (max_repetition < 1 || max_repetition > 100)
//		{
//			// 显示错误提示
//			AfxMessageBox(_T("请输入 1 到 100 之间的数字"));
//
//			// 清除编辑框的内容
//			pEdit->SetWindowText(_T(""));
//			//// 将焦点设置回编辑框，允许用户重新输入
//			//GetDlgItem(IDC_EDIT4)->SetFocus();
//			return;
//		}
//	}
//}

void CMFCFILEDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_ComBoxText.GetCurSel();

	// 获取对应值
	m_ComBoxText.GetLBText(index, com_str);
}
