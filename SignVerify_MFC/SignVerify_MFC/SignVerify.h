
// SignVerify_MFC.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSignVerify_MFCApp:
// О реализации данного класса см. SignVerify_MFC.cpp
//
class CSignVerify_MFCApp : public CWinApp
{
public:
	CSignVerify_MFCApp();

	// Переопределение
public:
	virtual BOOL InitInstance();

	// Реализация

	DECLARE_MESSAGE_MAP()

	
};

extern CSignVerify_MFCApp theApp;