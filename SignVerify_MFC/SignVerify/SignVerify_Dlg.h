/************************************************************************
* SignVerify_Dlg.h : ���� ��������� �������� ���� ����������            *
* �����: ������ ��������                                                *
/***********************************************************************/
#pragma once
#include "stdafx.h"
#include "afxwin.h"
#include "afxcmn.h"

#include "afxeditbrowsectrl.h"
struct BytesParam
{
	BOOL BASE64;
	BOOL HEX;
	BOOL BIN;
	BOOL OTHER;
	TCHAR* pBytes;
	DWORD Length;
};


// ���������� ���� CSignVerify_Dlg
class CSignVerify_Dlg : public CDialogEx
{
// ��������
public:
	CSignVerify_Dlg(CWnd* pParent = NULL);	// ����������� �����������
	~CSignVerify_Dlg()	// ����������, ������������� ���������� ������
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
// ��������� ����� ��� CEdit
	CFont myFont;
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
// ������ ������� 0=BASE64 1=HEX 2=BIN 3=NONE
	DWORD ExtraSignFormat_Radio;
// ������� ������ �� �����
	BOOL DataFromFile;
// ������ ���� ������
	BOOL DataFromString;
// ������� �������� ������� �����
	BOOL ProccessIsStarted;
// ������� �������� ������� ��������
	BOOL ProccessIsDone;
// ������� �����
	BOOL SignVerified;
// ���������� ����������������
	HCRYPTPROV hMyProv;
// ���������� ���������
	HCERTSTORE  hMyStore;
// ���������� �����
	HCRYPTKEY hMyKey;
// ���������� ����
	HCRYPTHASH hMyHash;
// �������� �����������
	PCCERT_CONTEXT hMyCert;
// ��������� �� ������� � ���� ������� ������
	BYTE * pBinSign;
// ������ ������� ������ pBinSign
	DWORD  pcbBinary;
// ��������� �� ������ � ���� ������� ������
	byte *File;
// ������ ������� ������ File
	DWORD FileLen;
// ��������� �� �������� ���� � ���� ������� ������
	BYTE* PubKey;
// ������ ������� ������ PubKey
	DWORD nPubKeyLen;
// ������ ���������� � �����������������
	std::vector <SuperCryptoAPI::ProviderInfo> aProviders;
// ������ ���������� � ��������
	std::vector <SuperCryptoAPI::Location> aLocations;
// ������ ���������� �� ����������
	std::vector <SuperCryptoAPI::AlgInfo> aAlgs;
// ������ ���������� ������ �� ���������� ���� "Hash"
	std::vector <SuperCryptoAPI::AlgInfo> aHashAlgs;
// ������ ���������� ������������
	std::vector <CERT_CONTEXT> aCerts;
// ��������� �������, ������������, ��� ������� ��������� �����.
	std::vector <TCHAR> AlgParams;
// ���������� ����� ���������� ���������� � ������� aProviders
	int iProv;
// ���������� ����� ��������� ������� � ������� aLocations
	int iLoc;
// ���������� ����� ���������� ��������� � ��������� �������
	int iStore;
// ���������� ����� ���������� ����������� � ��������� ���������
	int iCert;
// ���������� ����� ���������� ���-���������, �� ��������� - ������
	int HashAlg;
// ������� ���������� ������ ������������
	void UpdateCerts();
// ������� ���������� ������ ��������
	void UpdateStores();
// ������� ���������� ������ �������
	void UpdateLocations();
// ������� ���������� ������ �����������������
	void UpdateProviders();
// ������� ������������� ������� � ������
	std::vector <BYTE> DecodeBytesWithRadioBTN(BYTE * pBinSign, DWORD pcbBinary, DWORD ExtraSignFormat_Radio);
// ������� ���������� �������������� ����������, ���������� �� �������������� �������
	void UpdateExtraBOOLs(BytesParam ExtraSignParam);
// ������� �������� �������
	BOOL VerifySign(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey);
// ������� ���������� ���������� � ���
	void AddToLog(_bstr_t msg);
// ������� ����������� �� ������ � ������ ������ ��� ������� HEX, Base64
	BYTE* ConvertBytes(TCHAR* pBuffer, DWORD dwBuffLen, DWORD &OutBufferLen, int ConvertMode);
// ������������� ����������
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
// ������� ��������� �����
	void UpdateFieldsLighting();
// ������� ������ �����
	BYTE* ReadFile(CString sPath, DWORD &ullFileLen);
// �������, ������������ ����������� ������ ��������
	BytesParam TryDeterCoding(TCHAR* str, DWORD nStrLen);
// ������� ������������� � ������������ ������ (Reset)
	void MyProgramInit();
// ������� ������������ ������
	void DestroyUsedMemory()
	{
		aProviders.clear();
		aLocations.clear();
		aAlgs.clear();
		aCerts.clear();
		AlgParams.clear();
		aHashAlgs.clear();
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
		if(hMyCert!=NULL)
		{
			CertFreeCertificateContext(hMyCert);
			hMyCert=NULL;
		}
		if(pBinSign!=NULL)
		{
			delete [] pBinSign;
			pBinSign=NULL;
		}
		if(File!=NULL)
		{
			delete [] File;
			File=NULL;
		}
		if(PubKey!=NULL)
		{
			delete [] PubKey;
			PubKey=NULL;
		}
	}
// ������� ������ ���������� �� ����������� � ���
    void ShowCertInfo();
// ������� �������� ������� � ������� ��������� ������������
	BOOL VerifySignWithCurCert(std::vector <BYTE> &aSign, std::vector <BYTE> &aData);
// ������� �������� ������������� �������
	BOOL VerifyDetachedSign(std::vector <BYTE> &aSign, std::vector <BYTE> &aData);
// ������� �������� ������� � �������� ��������� �����
	BOOL VerifySignWithPubKey(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey);
// ������� ������ ���������� �������� �������
	void CheckResultVerifySign(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey);
// ������� �������� ������� � ������� ����������� � ���������
	void VerifySignWithCertSearch();
// ������� �������� ������� ��� ������ �����������
	void VerifySignWithoutCertSearch();
// �������, �������������� �������� ������� � ��������� �������� ������ ������� �������
	void MakeMagicWithSignAndCheck(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey);
// �������� ���� � �����������
public:
	TColorText ���������������;
	TColorText �������_���������;
	TColorText ���������;
	TColorText ����������;
	TColorText ��������_����������_��;
	TColorText �������_�����;
	TColorText ���_������_������;
	TColorText SignFromFile_label;
	TColorText DataFromFile_Label;
	CComboBox �������;
	CComboBox ���������;
	CComboBox �����������;
	CComboBox ����������������;
	CButton ���������_���_���������;
	CButton ���������_���_�����������_�_���������;
	CButton HelpButton;
	CButton ��������_�������_������_�_������;
	CButton ��������_������_�_�����_�����;
	CEdit �������;
	CEdit ������;
	CEdit ���;
	// �������� ���������� �����
	int iCertFrom;
	int DataFormat_Radio;
	CMFCEditBrowseCtrl �����������;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo4();
	//afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnEnChangeMfceditbrowse4();
	afx_msg void OnEnChangeMfceditbrowse5();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedButton55();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeMfceditbrowse3();
	CMFCEditBrowseCtrl ���������������;
	CMFCEditBrowseCtrl ����������;
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	CButton ���������������;
};
