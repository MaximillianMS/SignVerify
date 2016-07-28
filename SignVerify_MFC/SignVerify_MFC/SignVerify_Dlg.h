
// SignVerify_MFCDlg.h : ���� ���������
//

#pragma once
#include <vector>
#include "afxwin.h"
#include "afxcmn.h"
#include "tcolortext.h"
#include "SuperCryptoAPI.h"
//#include "afxeditbrowsectrl.h"
struct BytesParam
{
	BOOL BASE64;
	BOOL HEX;
	BOOL BIN;
	BOOL OTHER;
	BYTE* pBytes;
	DWORD Length;
};


// ���������� ���� CSignVerify_MFCDlg
class CSignVerify_MFCDlg : public CDialogEx
{
// ��������
public:
	CSignVerify_MFCDlg(CWnd* pParent = NULL);	// ����������� �����������
	~CSignVerify_MFCDlg()	// ����������, ������������� ���������� ������
	{
		DestroyUsedMemory();
	}
// ������ ����������� ����
	enum { IDD = IDD_SIGNVERIFY_MAIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

// ������� � ����������, ������������ � ������ ���������
protected:
// �������������� ������
	BOOL CryptoProviderChosen;
// ������ ����� ������� ����������� �� ���������
	BOOL CertFromStoreSelected;
// ������� �������
	BOOL LocationChosen;
// ��������� �������
	BOOL StoreChosen;
// ���������� ������
	BOOL CertChosen;
// ������ ����� ������� ����������� �� �����
	BOOL CertFromFileSelected;
// ���� ����������� ������
	BOOL CertFileChosen;
// ������ ����� ������� ���������� �����
	BOOL PubKeyInputSelected;
// ��������� ���� ������
	BOOL PubKeyEntered;
// ������ ����� �� ���� ����������
	BOOL SearchAllStoresSelected;
// ������ ����� �� ���� ������������ � ���������
	BOOL SearchAllCertsSelected;
// ������� ������� �� �����
	BOOL SignFromFile;
// ������ ���� �������
	BOOL SignFromString;
// ������� � ������� PEM
	BOOL ExtraSignFormat_PEM;
// ������ ������� 0=
	DWORD ExtraSignFormat_Radio;
// ������� ������ �� �����
	BOOL DataFromFile;
// ������ ���� ������
	BOOL DataFromString;
	BOOL ProccessIsStarted;
	BOOL ProccessIsDone;
	BOOL SignVerified;
	HCRYPTPROV hMyProv;
	HCERTSTORE  hMyStore;
	HCRYPTKEY hMyKey;
	HCRYPTHASH hMyHash;
	CERT_CONTEXT MyCert;
	BYTE * pBinSign;
	DWORD  pcbBinary;
	byte *File;
	DWORD FileLen;
	BYTE* PubKey;
	DWORD nPubKeyLen;
	std::vector <SuperCryptoAPI::ProviderInfo> aProviders;
	std::vector<SuperCryptoAPI::Location> aLocations;
	std::vector <SuperCryptoAPI::AlgInfo> aAlgs;
	std::vector <CERT_CONTEXT> aCerts;
	int iProv;
	int iLoc;
	int iStore;
	int iCert;
	DWORD LastCert;
	int HashAlg;
	void UpdateCerts();
	void UpdateStores();
	void UpdateLocations();
	void UpdateProviders();
	void UpdateExtraBOOLs(BytesParam ExtraSignParam);
	BOOL VerifySign();
	void AddToLog(_bstr_t msg);
	BYTE* ConvertBytes(BYTE* pBuffer, DWORD dwBuffLen, DWORD &OutBufferLen, int ConvertMode);
	void InitBOOLs()
	{
		CryptoProviderChosen=FALSE;
		CertFromStoreSelected=TRUE;
		LocationChosen=FALSE;
		StoreChosen=FALSE;
		CertChosen=FALSE;
		CertFromFileSelected=FALSE;
		CertFileChosen=FALSE;
		PubKeyInputSelected=FALSE;
		PubKeyEntered=FALSE;
		SearchAllStoresSelected=FALSE;
		SearchAllCertsSelected=FALSE;
		SignFromFile=FALSE;
		SignFromString=FALSE;
		ExtraSignFormat_PEM=FALSE;
		DataFromFile=FALSE;
		DataFromString=FALSE;
		ProccessIsStarted=FALSE;
		ProccessIsDone=FALSE;
		SignVerified=FALSE;
		UpdateFieldsLighting();
	}
	void UpdateFieldsLighting();
	BYTE* ReadFile(CString sPath, DWORD &ullFileLen);
	BytesParam TryDeterCoding(BYTE* str, DWORD nStrLen);
	void MyProgramInit();
	void DestroyUsedMemory()
	{
		aProviders.clear();
		aLocations.clear();
		aAlgs.clear();
		aCerts.clear();
		if(hMyHash!=NULL)
		{
			CryptDestroyHash(hMyHash);
			hMyHash=NULL;
		}
		if(hMyKey!=NULL)
		{
			CryptDestroyKey(hMyKey);
			hMyKey=NULL;
		}
		if(hMyStore!=NULL)
		{
			CertCloseStore(hMyStore, NULL);
			hMyStore=NULL;
		}
		if(hMyProv!=NULL)
		{
			CryptReleaseContext(hMyProv, NULL);
			hMyProv=NULL;
		}
		if(pBinSign!=NULL)
		{
			delete [] pBinSign;
		}
		if(File!=NULL)
		{
			delete [] File;
		}
		if(PubKey!=NULL)
		{
			delete [] PubKey;
		}
	}
// �������� ���� � �������
public:
	afx_msg void OnCbnSelchangeCombo1();
	TColorText ���������������;
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox �������;
	CComboBox ���������;
	CComboBox �����������;
	CButton ���������_���_���������;
	CButton ���������_���_�����������_�_���������;
	TColorText �������_���������;
	TColorText ���������;
	TColorText ����������;
	int iCertFrom;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
	CButton HelpButton;
	TColorText ��������_����������_��;
	TColorText �������_�����;
	TColorText ���_������_������;
	CComboBox ����������������;
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnEnChangeMfceditbrowse4();
	CMFCEditBrowseCtrl �����������;
	afx_msg void OnEnChangeEdit1();
	CEdit �������;
	afx_msg void OnEnChangeEdit3();
	CEdit ������;
	CButton ��������_�������_������_�_������;
	CButton ��������_������_�_�����_�����;
	//afx_msg void OnBnClickedCheck4();
	CEdit ���;
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio6();
	TColorText SignFromFile_label;
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeMfceditbrowse5();
	TColorText DataFromFile_Label;
};
