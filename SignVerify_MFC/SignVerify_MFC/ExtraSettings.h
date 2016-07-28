#pragma once
#include "afxwin.h"
#include "resource.h"

// диалоговое окно ExtraSettings

class ExtraSettings : public CDialogEx
{
	DECLARE_DYNAMIC(ExtraSettings)

public:
	ExtraSettings(BOOL ExtraSignFormatPEM, int ExtraSignFormat_Radio, CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~ExtraSettings();
// Данные диалогового окна
	enum { IDD = IDD_DIALOG_EXTRA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int SignFormat_Radio;
	BOOL SignFormat_PEM;
};
