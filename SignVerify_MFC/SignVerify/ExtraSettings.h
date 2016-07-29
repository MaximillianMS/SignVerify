/************************************************************************
* ExtraSettings.h : заголовочный файл окна с параметрами подписи        *
* Автор: Максим Нестеров                                                *
/***********************************************************************/
#pragma once
#include "afxwin.h"
#include "resource.h"
#include "SuperCryptoAPI.h"
#include <vector>
// диалоговое окно ExtraSettings

class ExtraSettings : public CDialogEx
{
	DECLARE_DYNAMIC(ExtraSettings)

public:
	ExtraSettings(BOOL ExtraSignFormatPEM, int ExtraSignFormat_Radio, std::vector <SuperCryptoAPI::AlgInfo> HashAlgs, DWORD HashId, std::vector <TCHAR> AlgParams, CWnd* pParent = NULL);   // стандартный конструктор
	BOOL OnInitDialog();
	virtual ~ExtraSettings();
// Данные диалогового окна
	enum { IDD = IDD_DIALOG_EXTRA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
// Формат данных
	int SignFormat_Radio;
// Формат PEM
	BOOL SignFormat_PEM;
// Параметры алгоритма подписи
	CString SignParams;
// Порядковый номер хеш-алгоритма
	int HashIndex;
// Массив информации об хеш-алгоритмах
	std::vector <SuperCryptoAPI::AlgInfo> aHashAlgs;
// Массив информации об всех алгоритмах
	std::vector <TCHAR> aAlgParams;
	CComboBox HashAlgs_combo;
	CEdit SignParams_edit;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedRadio5();
};
