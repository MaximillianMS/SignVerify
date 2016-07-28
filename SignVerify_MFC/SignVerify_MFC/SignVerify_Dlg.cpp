
// SignVerify_MFCDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "SignVerify.h"
#include "SignVerify_Dlg.h"
#include "afxdialogex.h"
#include "EnterKey.h"
#include "ExtraSettings.h"
#include <windows.h>
#include <atlbase.h>//?
#include <atlconv.h>//?
#include <string>
#include <cryptuiapi.h>
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "Crypt32.lib")
#include "WinCryptEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define green RGB(0,200,0)
#define red RGB(200,0,0)
#define black RGB(0,0,0)
#define gray RGB(127,127,127)
#define yellow RGB(180,180,0)
// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CSignVerify_MFCDlg




CSignVerify_MFCDlg::CSignVerify_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignVerify_MFCDlg::IDD, pParent)
	, iCertFrom(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSignVerify_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, ���������������);
	DDX_Control(pDX, IDC_COMBO2, �������);
	DDX_Control(pDX, IDC_COMBO3, ���������);
	DDX_Control(pDX, IDC_COMBO4, �����������);
	DDX_Control(pDX, IDC_CHECK4, ���������_���_���������);
	DDX_Control(pDX, IDC_CHECK3, ���������_���_�����������_�_���������);
	DDX_Control(pDX, IDC_STATIC2, �������_���������);
	DDX_Control(pDX, IDC_STATIC3, ���������);
	DDX_Control(pDX, IDC_STATIC4, ����������);
	DDX_Radio(pDX, IDC_RADIO1, iCertFrom);
	DDX_Control(pDX, IDC_BUTTON2, HelpButton);
	DDX_Control(pDX, IDC_STATIC5, ��������_����������_��);
	DDX_Control(pDX, IDC_STATIC8, �������_�����);
	DDX_Control(pDX, IDC_STATIC12, ���_������_������);
	DDX_Control(pDX, IDC_COMBO1, ����������������);
	DDX_Control(pDX, IDC_MFCEDITBROWSE4, �����������);
	DDX_Control(pDX, IDC_EDIT1, �������);
	DDX_Control(pDX, IDC_EDIT3, ������);
	DDX_Control(pDX, IDC_CHECK2, ��������_�������_������_�_������);
	DDX_Control(pDX, IDC_CHECK1, ��������_������_�_�����_�����);
	DDX_Control(pDX, IDC_EDIT2, ���);
	DDX_Control(pDX, IDC_STATIC_SIGNFROMFILE, SignFromFile_label);
	DDX_Control(pDX, IDC_STATIC21, DataFromFile_Label);
}

BEGIN_MESSAGE_MAP(CSignVerify_MFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSignVerify_MFCDlg::OnCbnSelchangeCombo1)
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CSignVerify_MFCDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDOK, &CSignVerify_MFCDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CSignVerify_MFCDlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CSignVerify_MFCDlg::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CSignVerify_MFCDlg::OnCbnSelchangeCombo4)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE4, &CSignVerify_MFCDlg::OnEnChangeMfceditbrowse4)
	ON_EN_CHANGE(IDC_EDIT1, &CSignVerify_MFCDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CSignVerify_MFCDlg::OnEnChangeEdit3)
	//ON_BN_CLICKED(IDC_CHECK4, &CSignVerify_MFCDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_RADIO3, &CSignVerify_MFCDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO1, &CSignVerify_MFCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO6, &CSignVerify_MFCDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO2, &CSignVerify_MFCDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSignVerify_MFCDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE5, &CSignVerify_MFCDlg::OnEnChangeMfceditbrowse5)
END_MESSAGE_MAP()


// ����������� ��������� CSignVerify_MFCDlg

BOOL CSignVerify_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
	MyProgramInit();

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CSignVerify_MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������. ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CSignVerify_MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CSignVerify_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ������������� ����������, ������������ ������
void CSignVerify_MFCDlg::MyProgramInit() // Reset program
{
	InitBOOLs();
	iLoc=-1;
	iStore=-1;
	iCert=-1;
	pcbBinary=0;
	HashAlg=0;
	FileLen=0;
	iProv=-1;
	iLoc=-1;
	iStore=-1;
	iCert=-1;
	LastCert=-1;
	ExtraSignFormat_Radio=0;
	pBinSign=NULL;
	File=NULL;
	PubKey=NULL;
	hMyProv=NULL;
	hMyStore=NULL;
	hMyKey=NULL;
	hMyHash=NULL;
	DestroyUsedMemory();
	SuperCryptoAPI::getProviders(aProviders);
	UpdateProviders();
	SuperCryptoAPI::getLocations(aLocations);
	UpdateLocations();
}
// ��������� �����
void CSignVerify_MFCDlg::UpdateFieldsLighting() //��������� �����
{
	if(CryptoProviderChosen)
	{
		���������������.SetTextColor(green);
	}
	else
	{
		���������������.SetTextColor(red);
	}

	if(CertFromStoreSelected)
	{
		��������_����������_��.SetTextColor(yellow);
		�������.EnableWindow(TRUE);
		���������.EnableWindow(TRUE);
		�����������.EnableWindow(TRUE);
		���������_���_���������.EnableWindow(TRUE);
		���������_���_�����������_�_���������.EnableWindow(TRUE);

		if(LocationChosen)
		{
			�������_���������.SetTextColor(green);
			if(StoreChosen)
			{
				���������.SetTextColor(green);
				if(CertChosen)
				{
					����������.SetTextColor(green);
					��������_����������_��.SetTextColor(green);
				}
				else
				{
					����������.SetTextColor(red);
				}
			}
			else
			{
				���������.SetTextColor(red);
				����������.SetTextColor(black);
				�����������.EnableWindow(FALSE);
			}
		}
		else
		{
			�������_���������.SetTextColor(red);
			���������.SetTextColor(black);
			����������.SetTextColor(black);
			���������.EnableWindow(FALSE);
			�����������.EnableWindow(FALSE);
		}

	}
	else
	{
		�������_���������.SetTextColor(gray);
		���������.SetTextColor(gray);
		����������.SetTextColor(gray);
		�������.EnableWindow(FALSE);
		���������.EnableWindow(FALSE);
		�����������.EnableWindow(FALSE);
		���������_���_���������.EnableWindow(FALSE);
		���������_���_�����������_�_���������.EnableWindow(FALSE);
		���������_���_���������.SetCheck(BST_UNCHECKED);
		���������_���_�����������_�_���������.SetCheck(BST_UNCHECKED);
	}
	if(CertFromFileSelected)
	{
		if(CertFileChosen)
		{
			��������_����������_��.SetTextColor(green);
		}
		else
		{
			��������_����������_��.SetTextColor(yellow);
		}
	}
	if(PubKeyInputSelected)
	{
		if(PubKeyEntered)
		{
			��������_����������_��.SetTextColor(green);
		}
		else
		{
			��������_����������_��.SetTextColor(yellow);
		}
	}
	if(SignFromString)
	{
		�������_�����.SetTextColor(green);
		SignFromFile_label.SetTextColor(black);
	}
	else
	{
		if(SignFromFile)
		{
			�������_�����.SetTextColor(black);
			SignFromFile_label.SetTextColor(green);
		}
		else
		{
			SignFromFile_label.SetTextColor(yellow);
			�������_�����.SetTextColor(yellow);
		}
	}
	if(DataFromString)
	{
		���_������_������.SetTextColor(green);
		DataFromFile_Label.SetTextColor(black);
	}
	else
	{
		if(DataFromFile)
		{
			���_������_������.SetTextColor(black);
			DataFromFile_Label.SetTextColor(green);
		}
		else
		{
			���_������_������.SetTextColor(yellow);
			DataFromFile_Label.SetTextColor(yellow);
		}
	}
	Invalidate();
} 
// �������� ������ �����������
void CSignVerify_MFCDlg::UpdateProviders()
{
	����������������.Clear();
	����������������.UpdateData();
	����������������.AddString(_T("-----------------------------------------"));
	for(DWORD i=0;i<aProviders.size();i++)
	{
		����������������.AddString(aProviders.at(i).sName.c_str());
	}
}
// �������� ������ �������
void CSignVerify_MFCDlg::UpdateLocations()
{
	iLoc=-1;
	iStore=-1;
	iCert=-1;
	���������.ResetContent();
	���������.UpdateData();
	�����������.ResetContent();
	�����������.UpdateData();
	�������.ResetContent();
	�������.UpdateData();
	�������.AddString(_T("-----------------------------------------"));
	for(DWORD i=0;i<aLocations.size();i++)
	{
		�������.AddString(aLocations.at(i).sName.c_str());
	}
}
// �������� ������ ��������
void CSignVerify_MFCDlg::UpdateStores()
{
	iStore=-1;
	iCert=-1;
	�����������.ResetContent();
	�����������.UpdateData();
	���������.ResetContent();
	���������.UpdateData();
	���������.AddString(_T("-----------------------------------------"));
	if(iLoc>=0)
	{
		for(DWORD i=0;i<aLocations.at(iLoc).aStores.size();i++)
		{
			���������.AddString(aLocations.at(iLoc).aStores.at(i).c_str());
		}
	}
}
// �������� ������ ������������
void CSignVerify_MFCDlg::UpdateCerts()
{
	iCert=-1;
	�����������.ResetContent();
	�����������.UpdateData();
	�����������.AddString(_T("-----------------------------------------"));
	if(iStore>=0)
	{
		if(hMyStore!=NULL)
		{
			CertCloseStore(hMyStore, NULL);
			hMyStore=NULL;
		}
		hMyStore = CertOpenStore(CERT_STORE_PROV_SYSTEM, 
			PKCS_7_ASN_ENCODING | X509_ASN_ENCODING, 
			0,
			CERT_STORE_OPEN_EXISTING_FLAG |CERT_STORE_READONLY_FLAG | (aLocations.at(iLoc).Id<<CERT_SYSTEM_STORE_LOCATION_SHIFT), 
			aLocations.at(iLoc).aStores.at(iStore).c_str());
		if(hMyStore!=NULL)
		{
			aCerts.clear();
			SuperCryptoAPI::getCerts(aCerts,hMyStore);
			for(DWORD i=0;i<aCerts.size();i++)
			{
				TCHAR pszNameString[256];
				if(CertGetNameString(
					&aCerts.at(i),
					CERT_NAME_SIMPLE_DISPLAY_TYPE,
					0,
					NULL,
					pszNameString,
					128)) 
				{
					�����������.AddString(pszNameString);

				}
			}

		}
	}
}
// �������� ������ � ���
void CSignVerify_MFCDlg::AddToLog(_bstr_t msg) // ����� ��������� � ���
{
	CString sCurLog;
	���.GetWindowTextW(sCurLog);
	CString StrToAdd((LPCTSTR)msg);
	sCurLog+=StrToAdd.GetString();
	���.SetWindowTextW(sCurLog);
	���.UpdateWindow();
}
// ��������� �������
BOOL CSignVerify_MFCDlg::VerifySign() //�������� �������
{
	if((CryptoProviderChosen)&(CertChosen|CertFileChosen|PubKeyEntered)&(SignFromString|SignFromFile)&(DataFromString|DataFromFile)) // ������ ������
	{
		if(hMyProv!=NULL)
		{
			CryptReleaseContext(hMyProv, NULL);
			hMyProv=NULL;
		}
		CryptAcquireContext(&hMyProv, NULL, aProviders.at(iProv).sName.c_str(), aProviders.at(iProv).dwType, CRYPT_VERIFYCONTEXT);
		//��������� ���� �� �����������
		if(hMyProv!=NULL)
		{

			if(CertFromStoreSelected&CertChosen)
			{
				if(hMyKey!=NULL)
				{
					CryptDestroyKey(hMyKey);
					hMyKey=NULL;
				}
				CERT_PUBLIC_KEY_INFO info=aCerts.at(iCert).pCertInfo->SubjectPublicKeyInfo;
				if(CryptImportPublicKeyInfo(hMyProv,X509_ASN_ENCODING|PKCS_7_ASN_ENCODING,&info,&hMyKey))
				{
					if(hMyHash!=NULL)
					{
						CryptDestroyHash(hMyHash);
						hMyHash=NULL;
					}
					if(CryptCreateHash(hMyProv, HashAlg, 0, 0, &hMyHash))
					{
						if(CryptHashData(hMyHash,File,FileLen,NULL))
						{

							if(CryptVerifySignature(hMyHash,pBinSign,pcbBinary,hMyKey,NULL,NULL))
							{
								return TRUE;
							}
							else
							{
								return FALSE;

							}
						}
					}
				}
			}
			if(CertFileChosen)
			{

			}
			if(PubKeyInputSelected)
			{
				if(hMyKey!=NULL)
				{
					CryptDestroyKey(hMyKey);
					hMyKey=NULL;
				}
				CERT_PUBLIC_KEY_INFO KeyInfo;
				CRYPT_BIT_BLOB BitBlob;
				BitBlob.cbData=nPubKeyLen+2;
				BitBlob.cUnusedBits=0;
				std::vector <BYTE> PublicKey;
				PublicKey.push_back(0x04);
				PublicKey.push_back(0x40);
				for(DWORD i=0;i<nPubKeyLen;i++)
				{
					PublicKey.push_back(PubKey[i]);
				}
				BitBlob.pbData=&PublicKey[0];
				KeyInfo.PublicKey=BitBlob;
				std::vector <SuperCryptoAPI::AlgInfo> aAlgs=SuperCryptoAPI::getAlgs(hMyProv);
				PCCRYPT_OID_INFO pOIDInfo;
				for(DWORD i=0;i<aAlgs.size();i++)
				{
					if(aAlgs.at(i).sType=="Signature")
					{
						pOIDInfo = CryptFindOIDInfo(CRYPT_OID_INFO_ALGID_KEY,&aAlgs.at(i).dwAlgId,0);
						break;
					}
				}
				CRYPT_ALGORITHM_IDENTIFIER AlgId;
				AlgId.pszObjId=(LPSTR)/*pOIDInfo->pszOID*/NULL;
				AlgId.Parameters.cbData=/*0x14*/0;
				BYTE standart[]={0x30, 0x12, 0x06, 0x07, 0x2A , 0x85 , 0x03 , 0x02 , 0x02  , 0x23 , 0x01 , 0x06 , 0x07 , 0x2A , 0x85 , 0x03 , 0x02
					, 0x02 , 0x1E , 0x01};
				AlgId.Parameters.pbData= /*standart*/NULL;
				KeyInfo.Algorithm=AlgId;
				CryptImportPublicKeyInfo(hMyProv,X509_ASN_ENCODING|PKCS_7_ASN_ENCODING,&KeyInfo,&hMyKey);
				DWORD error=GetLastError();
				if(hMyKey!=NULL)
				{
					BitBlob.cUnusedBits=0;
				}
			}
		}
	}
	return FALSE;
}
// �������������� ������ ������
BYTE* CSignVerify_MFCDlg::ConvertBytes(BYTE* pBuffer, DWORD dwBuffLen, DWORD &OutBufferLen, int ConvertMode = 0)
{
	switch(ConvertMode)
	{
	case CRYPT_STRING_HEX:
		{
			if(CryptStringToBinary((WCHAR*)pBuffer,dwBuffLen,CRYPT_STRING_HEX,NULL,&OutBufferLen,NULL,NULL))
			{
				BYTE* pOutBuffer=new BYTE[OutBufferLen];
				if(CryptStringToBinary((WCHAR*)pBuffer,dwBuffLen,CRYPT_STRING_HEX,pOutBuffer,&OutBufferLen,NULL,NULL))
				{
					return pOutBuffer;
				}
			}
			break;
		}
	case CRYPT_STRING_BASE64:
		{
			if(CryptStringToBinary((WCHAR*)pBuffer,dwBuffLen,CRYPT_STRING_BASE64,NULL,&OutBufferLen,NULL,NULL))
			{
				BYTE* pOutBuffer=new BYTE[OutBufferLen];
				if(CryptStringToBinary((WCHAR*)pBuffer,dwBuffLen,CRYPT_STRING_BASE64,pOutBuffer,&OutBufferLen,NULL,NULL))
				{
					return pOutBuffer;
				}
			}
			break;
		}
	default:
		{

		}
	}
	return NULL;
}
// ������� ����
BYTE* CSignVerify_MFCDlg::ReadFile(CString sPath, DWORD &ullFileLen)
{
	CFile TheFile;
	CFileException fileException;
	if(!TheFile.Open((LPCTSTR)sPath,CFile::modeRead,&fileException))
	{
		AddToLog(_T("������ �������� �����: "));
		AddToLog(sPath.GetString());
		AddToLog(_T("\r\n"));
		return NULL;
	}
	ullFileLen=(DWORD)TheFile.GetLength();
	BYTE* szBuffer=new BYTE[ullFileLen];
	TheFile.Seek(0, CFile::begin);
	TheFile.Read(szBuffer, ullFileLen); 
	TheFile.Close();
	return szBuffer;
}

// ���������� ���������� ����������� ������ �������
BytesParam CSignVerify_MFCDlg::TryDeterCoding(BYTE* str, DWORD nStrLen)
{
	BytesParam params;
	params.BASE64=FALSE;
	params.BIN=FALSE;
	params.HEX=FALSE;
	params.OTHER=FALSE;
	params.Length=nStrLen;
	params.pBytes=str;
	if(nStrLen>0)
	{
		params.BASE64=FALSE;
		params.HEX=FALSE;
		params.BIN=TRUE;
		BOOL UpperCase=FALSE;
		BOOL LowCase=FALSE;
		for(DWORD i=0;i<nStrLen;i++)
		{
			if(params.BIN)
			{
				if(!((str[i]=='0')|(str[i]=='1')))
				{
					params.BIN=FALSE;
					params.HEX=TRUE;
				}
			}
			if(!params.BIN)
			{
				if(params.HEX)
				{
					if(!((str[i]>='0')&(str[i]<='9')))
					{
						if((str[i]>='a')&(str[i]<='z'))
						{
							LowCase=TRUE;
						}
						if((str[i]>='A')&(str[i]<='Z'))
						{
							UpperCase=TRUE;
						}
						if((LowCase&UpperCase)|(!(((str[i]>='a')&(str[i]<='z'))|((str[i]>='A')&(str[i]<='Z')))))
						{
							params.HEX=FALSE;
							params.BASE64=TRUE;
						}
					}
				}
				if(!params.HEX)
				{
					if(!(((str[i]>='0')&(str[i]<='9'))|
						((str[i]>='A')&(str[i]<='Z'))|
						((str[i]>='a')&(str[i]<='z'))|
						(str[i]=='=')|
						(str[i]=='/')|
						(str[i]=='+')))
					{
						params.BASE64=FALSE;
						params.OTHER=TRUE;
						break;
					}
				}
			}
		}
	}
	return params;
}
// �������� ���������� ����������� �� ������ ������� TryDeterCoding
void CSignVerify_MFCDlg::UpdateExtraBOOLs(BytesParam ExtraSignParam)
{
	AddToLog(_T("��������� ������ �������...\r\n"));
	if(ExtraSignParam.OTHER)
	{
		ExtraSignFormat_PEM=TRUE;
		ExtraSignFormat_Radio=3; // No dencoding
		AddToLog(_T("������� ���������� � ������� PEM. ����������� �����������.\r\n"));
	}
	else
	{
		if(ExtraSignParam.BASE64|ExtraSignParam.HEX|ExtraSignParam.BIN)
		{
			DWORD len=0;
			if(ExtraSignParam.BASE64)
			{
				ExtraSignFormat_Radio=0;
				AddToLog(_T("����� �������������� ������������� ������� �� ������� BASE64.\r\n"));
				if(!CryptStringToBinaryA((CHAR*)ExtraSignParam.pBytes,ExtraSignParam.Length,CRYPT_STRING_BASE64,NULL,&len,NULL,NULL))
				{
					AddToLog(_T("������ ������������� ������� BASE64.\r\n"));
				}
			}
			if(ExtraSignParam.HEX)
			{
				ExtraSignFormat_Radio=1;
				AddToLog(_T("����� �������������� ������������� ������� �� ������� HEX.\r\n"));
				len=ExtraSignParam.Length/2;
			}
			if(ExtraSignParam.BIN)
			{
				ExtraSignFormat_Radio=2;
				AddToLog(_T("����� �������������� ������������� ������� �� ������� BIN.\r\n"));
				len=ExtraSignParam.Length/8;
			}
			len=len*8;
			if((len!=512)&(len!=1024)&(len!=2048))
			{
				ExtraSignFormat_PEM=TRUE;
				AddToLog(_T("������� ���������� � ������� PEM.\r\n"));
			}
			else
			{
				ExtraSignFormat_PEM=FALSE;
				AddToLog(_T("������� ���������� � ������� \"�����\" �������.\r\n"));
				AddToLog(_T("����� ������� � �����: "));
				CString keylen;
				keylen.Format(_T("%d"),len);
				AddToLog(keylen+"\r\n");

			}
		}
		else
		{
			ExtraSignFormat_PEM=FALSE;
			ExtraSignFormat_Radio=3; // No dencoding
			AddToLog(_T("������� ���������� � ������� \"�����\" ������. ����������� �����������.\r\n"));
		}
	}
}

// ������� �������������� (���������)
void CSignVerify_MFCDlg::OnCbnSelchangeCombo1()
{

	// TODO: �������� ���� ��� ����������� �����������
	iProv=����������������.GetCurSel();
	if(iProv>0)
	{
		CryptoProviderChosen=TRUE;
		UpdateFieldsLighting();
	}
	else
	{
		CryptoProviderChosen=FALSE;
		UpdateFieldsLighting();
	}
	iProv--;
}
// ������� ������� (���������)
void CSignVerify_MFCDlg::OnCbnSelchangeCombo2()
{
	// TODO: �������� ���� ��� ����������� �����������
	StoreChosen=FALSE;
	CertChosen=FALSE;
	iLoc=�������.GetCurSel();
	if(iLoc>0)
	{
		LocationChosen=TRUE;
	}
	else
	{
		LocationChosen=FALSE;
	}
	UpdateFieldsLighting();
	iLoc--;
	UpdateStores();
}
// ������� ��������� (���������)
void CSignVerify_MFCDlg::OnCbnSelchangeCombo3()
{
	// TODO: �������� ���� ��� ����������� �����������
	CertChosen=FALSE;
	iStore=���������.GetCurSel();
	if(iStore>0)
	{
		StoreChosen=TRUE;
	}
	else
	{
		StoreChosen=FALSE;
	}
	UpdateFieldsLighting();
	iStore--;
	UpdateCerts();
}
// ������� ���������� (���������)
void CSignVerify_MFCDlg::OnCbnSelchangeCombo4()
{
	// TODO: �������� ���� ��� ����������� �����������
	iCert=�����������.GetCurSel();
	if(iCert>0)
	{
		CertChosen=TRUE;
	}
	else
	{
		CertChosen=FALSE;
	}
	UpdateFieldsLighting();
	iCert--;
}
// ��������� ������� (������)
void CSignVerify_MFCDlg::OnBnClickedOk()
{
	HashAlg=CALG_GR3411;
	ProccessIsDone=FALSE;
	ProccessIsStarted=TRUE;
	if(CertChosen & ���������_���_�����������_�_���������.GetCheck())
	{
		LastCert=iCert;
		do
		{
			if(VerifySign())
			{
				AddToLog(_T("������� �����\r\n"));
				���.Invalidate();
				ProccessIsDone=TRUE;
				ProccessIsStarted=FALSE;
				return;
			}
			else
			{
				AddToLog(_T("������� �������\r\n"));
			}
			if(iCert==aCerts.size()-1)
			{
				iCert=0;
			}
			else
			{
				iCert++;
			}
		}
		while(iCert!=LastCert);
		AddToLog(_T("�� ���� ���������� �� �������.\r\n������� ��������.\r\n"));
	}
	else
	{
		if(VerifySign())
		{
			AddToLog(_T("������� �����\r\n"));
			���.Invalidate();
			ProccessIsDone=TRUE;
			ProccessIsStarted=FALSE;
			return;
		}
		else
		{
			AddToLog(_T("������� �������\r\n"));
		}
	}
	ProccessIsDone=TRUE;
	ProccessIsStarted=FALSE;
}
// � ��������� (������)
void CSignVerify_MFCDlg::OnBnClickedButton2()
{
	CAboutDlg About;
	About.DoModal();
	// TODO: �������� ���� ��� ����������� �����������
}
// ������������� (������)
void CSignVerify_MFCDlg::OnBnClickedButton1()
{
	ExtraSettings ExtraDlg(ExtraSignFormat_PEM,ExtraSignFormat_Radio);
	INT_PTR nResponse=ExtraDlg.DoModal();
	if(nResponse==IDOK)
	{
		ExtraSignFormat_Radio=ExtraDlg.SignFormat_Radio;
		ExtraSignFormat_PEM=ExtraDlg.SignFormat_PEM;
	}
}
// ������� ���� ������� (������)
void CSignVerify_MFCDlg::OnEnChangeMfceditbrowse4()
{
	CString sPath;
	�����������.GetWindowTextW(sPath);
	if(sPath.GetLength()>2)
	{
		if(pBinSign!=NULL)
		{
			free( pBinSign);
			pBinSign=NULL;
		}
		pBinSign=ReadFile(sPath,pcbBinary);
		if(pBinSign!=NULL)
		{
			�������.Clear();
			�������.UpdateData();
			SignFromString=FALSE;
			SignFromFile=TRUE;
			UpdateExtraBOOLs(TryDeterCoding(pBinSign,pcbBinary));

		}
		else
		{
			SignFromFile=FALSE;
		}
	}
	UpdateFieldsLighting();
}
// ������� ���� � ������� (������)
void CSignVerify_MFCDlg::OnEnChangeMfceditbrowse5()
{
	CString sPath;
	�����������.GetWindowTextW(sPath);
	if(sPath.GetLength()>2)
	{
		if(File!=NULL)
		{
			free( File);
			File=NULL;
		}
		File=ReadFile(sPath,FileLen);
		if(File!=NULL)
		{
			DataFromString=FALSE;
			DataFromFile=TRUE;
			return;
		}
	}
	DataFromFile=FALSE;
	UpdateFieldsLighting();
}
// ������ ������� (���������)
void CSignVerify_MFCDlg::OnEnChangeEdit1()
{
	CString sign;
	�������.GetWindowText(sign);
	if(sign.GetLength()>0)
	{
		sign.Remove(_T(' '));
		sign.Remove(_T('\t'));
		sign.Remove(_T('\r'));
		sign.Remove(_T('\n'));
		SignFromFile=FALSE;
		SignFromString=TRUE;
		CStringA sign_a(sign);
		UpdateExtraBOOLs(TryDeterCoding((BYTE*)sign_a.GetString(),sign_a.GetLength()));
	}
	else
	{
		SignFromString=FALSE;
	}
	UpdateFieldsLighting();
}
// ������ ������ (���������)
void CSignVerify_MFCDlg::OnEnChangeEdit3()
{
	CString data;
	������.GetWindowText(data);
	if(data.GetLength()>0)
	{
		CStringA data_a(data);
		if(File!=NULL)
		{
			free(File);
			File=NULL;
		}
		FileLen=data.GetLength();
		if(FileLen>0)
		{
			File=new BYTE[FileLen];
			DataFromString=TRUE;
			DataFromFile=FALSE;
			for(int i=0;i<data.GetLength();i++)
			{
				File[i]=data_a[i];
			}
		}
		else
		{
			DataFromString=FALSE;
		}
	}

	UpdateFieldsLighting();
}

// ������� ���������� (�����������)
void CSignVerify_MFCDlg::OnBnClickedRadio1()
{
	CertFromStoreSelected=TRUE;
	CertFromFileSelected=FALSE;
	PubKeyInputSelected=FALSE;
	PubKeyEntered=FALSE;
	UpdateFieldsLighting();
}
//������� ���� � ������������ (�����������)
void CSignVerify_MFCDlg::OnBnClickedRadio2()
{

}
// ������ ���� (�����������)
void CSignVerify_MFCDlg::OnBnClickedRadio3()
{
	CertFromStoreSelected=FALSE;
	CertFromFileSelected=FALSE;
	PubKeyInputSelected=TRUE;
	PubKeyEntered=FALSE;
	UpdateFieldsLighting();
	EnterKey EnterKeyDlg;
	INT_PTR nResponse=EnterKeyDlg.DoModal();
	if(nResponse==IDOK)
	{
		if(PubKey!=NULL)
		{
			delete [] PubKey;
			PubKey=NULL;
		}
		BYTE* pStr=(BYTE*)EnterKeyDlg.PublicKey.GetString();
		DWORD nStrLen=EnterKeyDlg.PublicKey.GetLength();
		if(EnterKeyDlg.Base64isChosen)
		{
			PubKey=ConvertBytes(pStr,nStrLen,nPubKeyLen,CRYPT_STRING_BASE64);
			if(PubKey!=NULL)
			{
				if(EnterKeyDlg.HEXisChosen)
				{
					BYTE* pBuffer=PubKey;
					DWORD nBuffSize=nPubKeyLen;
					PubKey=ConvertBytes(pBuffer,nBuffSize,nPubKeyLen,CRYPT_STRING_HEX);
					if(PubKey==NULL)
					{
						nPubKeyLen=0;
						AddToLog(_T("�������� ����. ������ ����������� HEX.\r\n"));
						PubKeyEntered=FALSE;
					}
					else
					{
						AddToLog(_T("����� ����� � ������: "));
						CString keylen;
						keylen.Format(_T("%d"),nPubKeyLen);
						AddToLog(keylen+"\r\n");
						PubKeyEntered=TRUE;
					}
					delete [] pBuffer;
				}
				else
				{
					AddToLog(_T("����� ����� � ������: "));
					CString keylen;
					keylen.Format(_T("%d"),nPubKeyLen);
					AddToLog(keylen+"\r\n");
					PubKeyEntered=TRUE;
				}
			}
			else
			{
				nPubKeyLen=0;
				AddToLog(_T("�������� ����. ������ ����������� Base64.\r\n"));
				PubKeyEntered=FALSE;
			}
		}
		else
		{
			if(EnterKeyDlg.HEXisChosen)
			{
				PubKey=ConvertBytes(pStr,nStrLen,nPubKeyLen,CRYPT_STRING_HEX);
				if(PubKey==NULL)
				{
					nPubKeyLen=0;
					AddToLog(_T("�������� ����. ������ ����������� HEX.\r\n"));
					PubKeyEntered=FALSE;
				}
				else
				{
					AddToLog(_T("����� ����� � ������: "));
					CString keylen;
					keylen.Format(_T("%d"),nPubKeyLen);
					AddToLog(keylen+"\r\n");
					PubKeyEntered=TRUE;
				}
			}
			else
			{
				PubKey=ConvertBytes(pStr,nStrLen,nPubKeyLen);
				AddToLog(_T("�� ������� ����������� �����. �������� ������������ ����.\r\n"));
			}
		}
	}
	else
	{
		PubKeyEntered=FALSE;
	}
	UpdateFieldsLighting();
}
//  (�����������)
void CSignVerify_MFCDlg::OnBnClickedRadio6()
{
	// TODO: �������� ���� ��� ����������� �����������
}

