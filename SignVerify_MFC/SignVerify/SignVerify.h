/************************************************************************
* SignVerify.h : ������� ���� ��������� ��� ����������              *
* �����: ������ ��������                                                *
/***********************************************************************/
#pragma once

#ifndef __AFXWIN_H__
#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CSignVerifyApp:
// � ���������� ������� ������ ��. SignVerify_MFC.cpp
//
class CSignVerifyApp : public CWinApp
{
public:
	CSignVerifyApp();

	// ���������������
public:
	virtual BOOL InitInstance();

	// ����������

	DECLARE_MESSAGE_MAP()

	
};

extern CSignVerifyApp theApp;