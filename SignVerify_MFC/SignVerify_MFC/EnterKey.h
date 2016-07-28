#pragma once
#include "afxwin.h"
#include "resource.h"

// диалоговое окно EnterKey

class EnterKey : public CDialogEx
{
	DECLARE_DYNAMIC(EnterKey)

public:
	EnterKey(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~EnterKey();
	CString PublicKey;
	BOOL HEXisChosen;
	BOOL Base64isChosen;
// Данные диалогового окна
	enum { IDD = IDD_DIALOGENTERKEY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	void TryDeterCoding();
	CEdit KeyInput;
	afx_msg void OnEnChangeEditKey();
	CButton Hex;
	CButton Base64;
	afx_msg void OnBnClickedOk();
};
