#pragma once
#include "afxwin.h"
#include "resource.h"

// ���������� ���� ExtraSettings

class ExtraSettings : public CDialogEx
{
	DECLARE_DYNAMIC(ExtraSettings)

public:
	ExtraSettings(BOOL ExtraSignFormatPEM, int ExtraSignFormat_Radio, CWnd* pParent = NULL);   // ����������� �����������
	virtual ~ExtraSettings();
// ������ ����������� ����
	enum { IDD = IDD_DIALOG_EXTRA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int SignFormat_Radio;
	BOOL SignFormat_PEM;
};
