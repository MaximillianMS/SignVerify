
// SignVerify_MFC.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CSignVerify_MFCApp:
// � ���������� ������� ������ ��. SignVerify_MFC.cpp
//
class CSignVerify_MFCApp : public CWinApp
{
public:
	CSignVerify_MFCApp();

	// ���������������
public:
	virtual BOOL InitInstance();

	// ����������

	DECLARE_MESSAGE_MAP()

	
};

extern CSignVerify_MFCApp theApp;