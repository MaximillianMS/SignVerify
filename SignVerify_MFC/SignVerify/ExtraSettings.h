/************************************************************************
* ExtraSettings.h : ������������ ���� ���� � ����������� �������        *
* �����: ������ ��������                                                *
/***********************************************************************/
#pragma once
#include "afxwin.h"
#include "resource.h"
#include "SuperCryptoAPI.h"
#include <vector>
// ���������� ���� ExtraSettings

class ExtraSettings : public CDialogEx
{
	DECLARE_DYNAMIC(ExtraSettings)

public:
	ExtraSettings(BOOL ExtraSignFormatPEM, int ExtraSignFormat_Radio, std::vector <SuperCryptoAPI::AlgInfo> HashAlgs, DWORD HashId, std::vector <TCHAR> AlgParams, CWnd* pParent = NULL);   // ����������� �����������
	BOOL OnInitDialog();
	virtual ~ExtraSettings();
// ������ ����������� ����
	enum { IDD = IDD_DIALOG_EXTRA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
// ������ ������
	int SignFormat_Radio;
// ������ PEM
	BOOL SignFormat_PEM;
// ��������� ��������� �������
	CString SignParams;
// ���������� ����� ���-���������
	int HashIndex;
// ������ ���������� �� ���-����������
	std::vector <SuperCryptoAPI::AlgInfo> aHashAlgs;
// ������ ���������� �� ���� ����������
	std::vector <TCHAR> aAlgParams;
	CComboBox HashAlgs_combo;
	CEdit SignParams_edit;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedRadio5();
};
