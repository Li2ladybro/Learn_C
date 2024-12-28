
// 2024_9_1222.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CMy202491222App:
// 有关此类的实现，请参阅 2024_9_1222.cpp
//

class CMy202491222App : public CWinApp
{
public:
	CMy202491222App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy202491222App theApp;
