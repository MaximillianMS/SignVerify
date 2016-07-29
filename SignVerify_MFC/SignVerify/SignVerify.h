/************************************************************************
* SignVerify.h : главный файл заголовка для приложения              *
* Автор: Максим Нестеров                                                *
/***********************************************************************/
#pragma once

#ifndef __AFXWIN_H__
#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSignVerifyApp:
// О реализации данного класса см. SignVerify_MFC.cpp
//
class CSignVerifyApp : public CWinApp
{
public:
	CSignVerifyApp();

	// Переопределение
public:
	virtual BOOL InitInstance();

	// Реализация

	DECLARE_MESSAGE_MAP()

	
};

extern CSignVerifyApp theApp;