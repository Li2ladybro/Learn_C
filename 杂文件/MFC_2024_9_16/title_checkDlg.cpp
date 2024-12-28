
// title_checkDlg.cpp: 实现文件
//

#define _CRT_SECURE_NO_DEPRECATE

#include "title_checkDlg.h"
#include "afxdialogex.h"
#include "framework.h"
#include "pch.h"
#include "title_check.h"
#include "type_convert.h"
#include "title_check_file.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx {
public:
    CAboutDlg();

    // 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 支持

    // 实现
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {}

void CAboutDlg::DoDataExchange(CDataExchange* pDX) {
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CMFC2024916Dlg 对话框

title_check::title_check(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_MFC_2024_9_16_DIALOG, pParent), old_file_address(_T("")),
    old_bk_count(0), old_se_file_similarity(0)

    ,
    new_bk_count(0), new_se_file_similarity(0), new_file_address(_T(""))

    ,
    max_repetition(_T("")), if_self_check(_T("")) {
    m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void title_check::DoDataExchange(CDataExchange* pDX) {
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, old_file_address);
    DDX_Text(pDX, IDC_EDIT2, new_file_address);
    DDX_Control(pDX, IDC_COMBO1, c_if_self_check);
    DDX_CBString(pDX, IDC_COMBO1, if_self_check);
    DDX_Control(pDX, IDC_EDIT6, ce_max_repetition);
    DDX_Text(pDX, IDC_EDIT6, max_repetition);
}

BEGIN_MESSAGE_MAP(title_check, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &title_check::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &title_check::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &title_check::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON4, &title_check::OnBnClickedButton4)
    ON_BN_CLICKED(IDC_BUTTON5, &title_check::OnBnClickedButton5)
    ON_CBN_SELCHANGE(IDC_COMBO1, &title_check::OnCbnSelchangeCombo1)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

// CMFC2024916Dlg 消息处理程序

BOOL title_check::OnInitDialog() {
    CDialogEx::OnInitDialog();

    // 将“关于...”菜单项添加到系统菜单中。

    // IDM_ABOUTBOX 必须在系统命令范围内。
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr) {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty()) {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
    // 执行此操作
    SetIcon(m_hIcon, TRUE);  // 设置大图标
    SetIcon(m_hIcon, FALSE); // 设置小图标

    // TODO: 在此添加额外的初始化代码

    // 标题
    CWnd* pWnd = GetDlgItem(IDHELP);
    title_cfont.CreatePointFont(200, _T("华文楷体"));
    pWnd->SetFont(&title_cfont);

    // 旧题目
    pWnd = GetDlgItem(OLD_TITLE_PATH);
    old_path_cfont.CreatePointFont(200, _T("华文楷体"));
    pWnd->SetFont(&old_path_cfont);

    // 新题目
    pWnd = GetDlgItem(NEW_TITLE_PATH);
    new_path_cfont.CreatePointFont(200, _T("华文楷体"));
    pWnd->SetFont(&new_path_cfont);

    // 最大重复率
    pWnd = GetDlgItem(MAX_REPETITION);
    max_rep_cfont.CreatePointFont(200, _T("华文楷体"));
    pWnd->SetFont(&max_rep_cfont);

    // 自查
    pWnd = GetDlgItem(SELF_CHECK);
    check_cfont.CreatePointFont(200, _T("华文楷体"));
    pWnd->SetFont(&check_cfont);

    // 打印窗口
    pWnd = GetDlgItem(IDC_EDIT3);
    print_cfont.CreatePointFont(150, _T("华文楷体"));
    pWnd->SetFont(&print_cfont);

    // 按钮开始
    pWnd = GetDlgItem(IDC_BUTTON5);
    begin_cfont.CreatePointFont(300, _T("华文楷体"));
    pWnd->SetFont(&begin_cfont);

    return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
}

void title_check::OnSysCommand(UINT nID, LPARAM lParam) {
    if ((nID & 0xFFF0) == IDM_ABOUTBOX) {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void title_check::OnPaint() {
    if (IsIconic()) {
        CPaintDC dc(this); // 用于绘制的设备上下文

        SendMessage(WM_ICONERASEBKGND,
            reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
    else {
        // CDialogEx::OnPaint();

        CPaintDC dc(this);
        CRect rect;
        GetClientRect(&rect);                  // 获取对话框长宽
        CDC dcBmp;                             // 定义并创建一个内存设备环境
        dcBmp.CreateCompatibleDC(&dc);         // 创建兼容性DC
        CBitmap bmpBackGround;                 // 背景图
        bmpBackGround.LoadBitmap(IDB_BITMAP1); // 载入资源中图片
        BITMAP m_bitmap;                       // 图片变量
        bmpBackGround.GetBitmap(&m_bitmap);    // 将图片载入位图中
        // 将位图选入临时内存设备环境
        CBitmap* pbmpOld = dcBmp.SelectObject(&bmpBackGround);
        dc.SetStretchBltMode(COLORONCOLOR);
        // 调用函数显示图片StretchBlt显示形状可变
        dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
            m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
    }
}

// 当用户拖动最小化窗口时系统调用此函数取得光标
// 显示。
HCURSOR title_check::OnQueryDragIcon() { return static_cast<HCURSOR>(m_hIcon); }

// 点击选择（只获取地址）旧题目
void title_check::OnBnClickedButton2() {
    // TODO: 在此添加控件通知处理程序代码
    mf.DoModal();
    old_file_address = mf.GetStr();
    // 刷新：将值写入编辑框
    UpdateData(0);
    return;
}

// 点击浏览（只读取文件）旧题目
void title_check::OnBnClickedButton1() {

    // TODO: 在此添加控件通知处理程序代码

    // 如果用户点击选择后再修改地址还要刷新数值，框中的数值写入变量
    UpdateData(1);

    // 地址抛错误
    if (old_file_address == L"") {
        MessageBox(L"当前旧题目文件路径为空，请选择！");
        return;
    }

    if (old_file_address.Mid(old_file_address.GetLength() - 4, 4) != ".txt") {
        // 取末尾最后四个字符
        MessageBox(L"请选择有效旧题目文件地址！");
        return;
    }

    // 清空编辑框内容
    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
    pEdit->SetWindowText(L"");

    // CString转化为char*
    USES_CONVERSION;
    char* old_pc = T2A(old_file_address);

    // 浏览旧题目内容
    // 将旧题目文件内容写入编辑框
    write_file_content_to_edit(old_pc);

    return;
}

// 点击选择（只获取地址）新题目
void title_check::OnBnClickedButton4() {
    // TODO: 在此添加控件通知处理程序代码
    mf.DoModal();
    new_file_address = mf.GetStr();
    // 刷新：将值写入编辑框
    UpdateData(0);
    return;
}

// 点击浏览（只读取文件）新题目
void title_check::OnBnClickedButton3() {
    // TODO: 在此添加控件通知处理程序代码

    // 如果用户点击选择后再修改地址还要刷新数值，框中的数值写入变量
    UpdateData(1);

    // 地址抛错误
    if (new_file_address == L"") {
        MessageBox(L"当前新题目文件路径为空，请选择！");
        return;
    }

    if (new_file_address.Mid(new_file_address.GetLength() - 4, 4) != ".txt") {
        // 取末尾最后四个字符
        MessageBox(L"请选择有效新题目文件地址！");
        return;
    }

    // 清空编辑框内容
    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
    pEdit->SetWindowText(L"");

    // CString转化为char*
    USES_CONVERSION;
    char* new_pc = T2A(new_file_address);

    // 浏览新题目
    // 将新题目文件内容写入编辑框
    write_file_content_to_edit(new_pc);

    return;
}

// 开始查重
void title_check::OnBnClickedButton5() {
    // 框中的数值写入变量
    UpdateData(1);

    // 地址抛错误
    if (old_file_address == L"") {
        MessageBox(L"当前旧题目文件路径为空，请选择！");
        return;
    }

    if (old_file_address.Mid(old_file_address.GetLength() - 4, 4) != ".txt") {
        // 取末尾最后四个字符
        MessageBox(L"请选择有效旧题目文件地址！");
        return;
    }

    if (new_file_address == L"") {
        MessageBox(L"当前新题目文件路径为空，请选择！");
        return;
    }

    if (new_file_address.Mid(new_file_address.GetLength() - 4, 4) != ".txt") {
        // 取末尾最后四个字符
        MessageBox(L"请选择有效新题目文件地址！");
        return;
    }

    // 获取最大重复率数值
    ce_max_repetition.GetWindowText(max_repetition);
    // CString转化为int

    int max_repetition_to_int = _ttoi(max_repetition);

    // 最大重复率抛错误
    if (max_repetition_to_int < 1 || max_repetition_to_int > 99) {

        MessageBox(L"请输入合理重复率!");
        ce_max_repetition.SetWindowText(L"");
        return;
    }

    // 是否需要进行本地文件查重抛错误
    if (if_self_check == L"") {
        MessageBox(L"请选择是否需要对自身新旧题目文件进行题目查重！");
        return;
    }

    // 旧题目文件容器
    file_data oldtitle;

    // 初始化old_fi
    init_file_data(&oldtitle);

    // CString转化为char*
    USES_CONVERSION;
    const char* old_pc = W2A(old_file_address);
    FILE* old_fi = fopen(old_pc, "r");

    if (old_fi == NULL) {
        MessageBox(L"旧题目文件打开失败！", L"程序中断", MB_OK | MB_ICONSTOP);
        exit(1);
    }

    // 写入数组
    write_file_to_array(old_fi, &oldtitle);

    if (fclose(old_fi) != NULL) {
        MessageBox(L"旧题目文件关闭失败!", L"程序中断", MB_OK | MB_ICONSTOP);
        exit(1);
    }
    // 计算空白行
    old_bk_count = bk_caluate(&oldtitle);

    // 新题目文件容器
    file_data newtitle;

    // 初始化new_pc
    init_file_data(&newtitle);

    // CString转化为char*
    const char* new_pc = W2A(new_file_address);
    FILE* new_fi = fopen(new_pc, "r");

    if (new_fi == NULL) {
        MessageBox(L"新题目文件打开失败！", L"程序中断", MB_OK | MB_ICONSTOP);
        exit(1);
    }

    // 写入数组
    write_file_to_array(new_fi, &newtitle);
    if (fclose(new_fi) != NULL) {
        MessageBox(L"新题目文件关闭失败!", L"程序中断", MB_OK | MB_ICONSTOP);
        exit(1);
    }
    // 计算空白行
    new_bk_count = bk_caluate(&newtitle);

    MessageBox(L"开始查重");

    if (if_self_check == L"Yes") {
        new_se_file_similarity =
            se_file_caluatesimilarity(&newtitle, new_bk_count);
        old_se_file_similarity =
            se_file_caluatesimilarity(&oldtitle, old_bk_count);
    }

    // CString转为char*

    char* if_self_check_to_char = W2A(if_self_check);

    // 获取桌面路径
    fs::path desktopPath = fs::path(getenv("USERPROFILE")) / "Desktop";

    // 输出文件路径
    fs::path outputFilePath = desktopPath / "Output_file.txt";

    // 将路径转换为 std::string
    std::string outputFilePathStr = outputFilePath.string();

    // 将 std::string 转换为 const char*
    const char* out_put_file_address = outputFilePathStr.c_str();

    // 将结果写入到Output_file中
    FILE* out_put_pi =
        fopen(out_put_file_address, "w"); // 将结果写入到Output_file中

    obtaine_check_result_and_write_to_file(
        &oldtitle, &newtitle, out_put_pi, max_repetition_to_int,
        if_self_check_to_char, old_bk_count, old_se_file_similarity,
        new_bk_count, new_se_file_similarity);

    fclose(out_put_pi); // 关闭文件

    // 获取 CEdit 控件的指针
    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
    pEdit->SetWindowText(L"");

    // 写入结果
    write_file_content_to_edit(out_put_file_address);

    MessageBox(L"查重结束请前往桌面查看！(Output_file.txt文件)");

    free(oldtitle._titles);
    free(newtitle._titles);

    return;
}

// 选择是否进行同文件查重
void title_check::OnCbnSelchangeCombo1() {
    // TODO: 在此添加控件通知处理程序代码
    // 获取当前索引
    int index = c_if_self_check.GetCurSel();

    // 获取对应值
    c_if_self_check.GetLBText(index, if_self_check);
}

// 防止 enter 退出
void title_check::OnOK() {
    // TODO: 在此添加控件通知处理程序代码
    // CDialog::OnOK();
}

// 文件内容写入编辑框
void title_check::write_file_content_to_edit(const char* pc) {
    FILE* pf = fopen(pc, "r");
    if (pf == NULL) {
        MessageBox(L"文件打失败 ");
        exit(1);
    }
    else {
        // 只要够达到换行符位置
        char* temp = (char*)malloc(sizeof(char) * 200);
        CString all_content = L"";

        while (fgets(temp, 200, pf) != NULL) {
            CString content_to_CString = char_p_convert_cstring(temp);
            content_to_CString += L"\r\n";
            all_content += content_to_CString;
        }

        CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
        pEdit->SetWindowText(all_content);
        free(temp);
    }
    // 关闭文件
    fclose(pf);

    return;
}

HBRUSH title_check::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) {
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    int ctr = pWnd->GetDlgCtrlID();

    switch (ctr) {

    case OLD_TITLE_PATH: {
        // old 路径静态文字
        pDC->SetTextColor(RGB(255, 255, 255)); // 设置静态文本框字体颜色
        pDC->SetBkMode(TRANSPARENT);           // 设置为透明
        return HBRUSH(GetStockObject(HOLLOW_BRUSH)); // 设置透明这句话不能掉
    }

    case IDC_EDIT1: {
        // old 编辑框字体颜色
        pDC->SetTextColor(RGB(0, 35, 245));    // 设置编辑框框字体颜色
        break;
    }

    case NEW_TITLE_PATH: {
        // new 路径静态文字
        pDC->SetTextColor(RGB(255, 255, 255)); // 设置静态文本框字体颜色
        pDC->SetBkMode(TRANSPARENT);           // 设置为透明
        return HBRUSH(GetStockObject(HOLLOW_BRUSH)); // 设置透明这句话不能掉
    }

    case IDC_EDIT2: {
        // new 编辑框字体颜色
        pDC->SetTextColor(RGB(0, 35, 245)); // 设置编辑框框字体颜色
        break;
    }

    case MAX_REPETITION: {
        // 最大重复率静态文字
        pDC->SetTextColor(RGB(255, 255, 255)); // 设置静态文本框字体颜色
        pDC->SetBkMode(TRANSPARENT);           // 设置为透明
        return HBRUSH(GetStockObject(HOLLOW_BRUSH)); // 设置透明这句话不能掉
    }

    case IDC_EDIT6: {
        // 最大重复率编辑框字体颜色
        pDC->SetTextColor(RGB(0, 35, 245)); // 设置编辑框框字体颜色
        break;
    }

    case SELF_CHECK: {
        // 自查静态控件
        pDC->SetTextColor(RGB(255, 255, 255)); // 设置静态文本框字体颜色
        pDC->SetBkMode(TRANSPARENT);           // 设置为透明
        return HBRUSH(GetStockObject(HOLLOW_BRUSH)); // 设置透明这句话不能掉
    }

    case IDC_COMBO1: {
        // 下拉列表字体颜色
        pDC->SetTextColor(RGB(0, 35, 245)); // 设置编辑框字体颜色
        break;
    }

    case IDHELP: {
        // 标题静态文字
        pDC->SetTextColor(RGB(255, 255, 255)); // 设置静态文本框字体颜色
        pDC->SetBkMode(TRANSPARENT);           // 设置为透明
        return HBRUSH(GetStockObject(HOLLOW_BRUSH)); // 设置透明这句话不能掉
    }

    case IDC_EDIT3: {
        // 打印输出
        pDC->SetTextColor(RGB(63, 72, 204)); // 设置静态文本框字体颜色
        // pDC->SetBkColor(RGB(63, 72, 204));
        // pDC->SetBkMode(TRANSPARENT);                 // 设置为透明
        // return HBRUSH(GetStockObject(HOLLOW_BRUSH)); // 设置透明这句话不能掉
        break;
    }
    }

    return hbr;
}
