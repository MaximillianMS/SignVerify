#pragma once
#include "afxwin.h"
#include "resource.h"

// ���������� ���� EnterKey

class EnterKey : public CDialogEx
{
	DECLARE_DYNAMIC(EnterKey)

public:
	EnterKey(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~EnterKey();
	CString PublicKey;
	BOOL HEXisChosen;
	BOOL Base64isChosen;
// ������ ����������� ����
	enum { IDD = IDD_DIALOGENTERKEY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	void TryDeterCoding();
	CEdit KeyInput;
	afx_msg void OnEnChangeEditKey();
	CButton Hex;
	CButton Base64;
	afx_msg void OnBnClickedOk();
};
