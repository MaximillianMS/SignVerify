/************************************************************************
* SignVerify_Dlg.�pp : ���� ���������� �������� ���� ����������         *
* �����: ������ ��������                                                *
/***********************************************************************/

#include "stdafx.h"
#include "SignVerify_Dlg.h"


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


// ���������� ���� CSignVerify_Dlg




CSignVerify_Dlg::CSignVerify_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignVerify_Dlg::IDD, pParent)
	, iCertFrom(0)
	, DataFormat_Radio(3)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSignVerify_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	/*DDX_Radio(pDX, IDC_RADIO4, DataFormat_Radio);
	DDV_MinMaxInt(pDX, DataFormat_Radio, 0, 3);
	DDX_Radio(pDX, IDC_RADIO1, iCertFrom);
	DDV_MinMaxInt(pDX, iCertFrom, 0, 2);*/
	DDX_Control(pDX, IDC_STATIC1, ���������������);
	DDX_Control(pDX, IDC_COMBO2, �������);
	DDX_Control(pDX, IDC_COMBO3, ���������);
	DDX_Control(pDX, IDC_COMBO4, �����������);
	DDX_Control(pDX, IDC_CHECK4, ���������_���_���������);
	DDX_Control(pDX, IDC_CHECK3, ���������_���_�����������_�_���������);
	DDX_Control(pDX, IDC_STATIC2, �������_���������);
	DDX_Control(pDX, IDC_STATIC3, ���������);
	DDX_Control(pDX, IDC_STATIC4, ����������);
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
	DDX_Control(pDX, IDC_MFCEDITBROWSE3, ���������������);
	DDX_Control(pDX, IDC_MFCEDITBROWSE5, ����������);
	DDX_Control(pDX, IDC_CHECK_USINGHASH, ���������������);
}

BEGIN_MESSAGE_MAP(CSignVerify_Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSignVerify_Dlg::OnCbnSelchangeCombo1)
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CSignVerify_Dlg::OnCbnSelchangeCombo2)
	//ON_BN_CLICKED(IDOK, &CSignVerify_Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CSignVerify_Dlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CSignVerify_Dlg::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CSignVerify_Dlg::OnCbnSelchangeCombo4)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE4, &CSignVerify_Dlg::OnEnChangeMfceditbrowse4)
	ON_EN_CHANGE(IDC_EDIT1, &CSignVerify_Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CSignVerify_Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_RADIO3, &CSignVerify_Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO1, &CSignVerify_Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CSignVerify_Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSignVerify_Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE5, &CSignVerify_Dlg::OnEnChangeMfceditbrowse5)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(ID_BUTTON55, &CSignVerify_Dlg::OnBnClickedButton55)
	ON_BN_CLICKED(IDC_BUTTON3, &CSignVerify_Dlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE3, &CSignVerify_Dlg::OnEnChangeMfceditbrowse3)
	ON_BN_CLICKED(IDC_RADIO4, &CSignVerify_Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO6, &CSignVerify_Dlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CSignVerify_Dlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CSignVerify_Dlg::OnBnClickedRadio8)
END_MESSAGE_MAP()


// ����������� ��������� CSignVerify_Dlg

BOOL CSignVerify_Dlg::OnInitDialog()
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

void CSignVerify_Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSignVerify_Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������
		CRect rect;
		GetClientRect(&rect);
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		/*HBITMAP m_Bitmap=CreateCompatibleBitmap(dc, rect.Width(), rect.Height());
		auto pOldBmp=SelectObject(dc,m_Bitmap);
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
		dcMem.FillSolidRect(rect, ::GetSysColor(COLOR_3DFACE));

		dc.BitBlt(rect.left, rect.top, rect.Width(), rect.Height(),&dcMem,rect.left, rect.top, SRCCOPY);
		dcMem.SelectObject(pOldBmp);*/
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CSignVerify_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ������������� ����������, ������������ ������
void CSignVerify_Dlg::MyProgramInit() // Reset program
{

	myFont.CreateFontW( 14, 0, 0, 0, FW_NORMAL, false, false,
		0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH|FF_SWISS, _T("Courier New") );
	�������.SetFont(&myFont);
	������.SetFont(&myFont);
	InitBOOLs();
	iLoc=-1;
	iStore=-1;
	iCert=-1;
	pcbBinary=0;
	HashAlg=0;
	FileLen=0;
	nPubKeyLen=0;
	iProv=-1;
	iLoc=-1;
	iStore=-1;
	iCert=-1;
	ExtraSignFormat_Radio=0;
	HashAlg=0;
	pBinSign=NULL;
	File=NULL;
	PubKey=NULL;
	hMyProv=NULL;
	hMyStore=NULL;
	hMyKey=NULL;
	hMyHash=NULL;
	hMyCert=NULL;
	DestroyUsedMemory();
	SuperCryptoAPI::getProviders(aProviders);
	UpdateProviders();
	SuperCryptoAPI::getLocations(aLocations);
	UpdateLocations();
}
// ��������� �����
void CSignVerify_Dlg::UpdateFieldsLighting() //��������� �����
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
	/*���������������.Invalidate();
	�������_���������.Invalidate();
	���������.Invalidate();
	����������.Invalidate();
	��������_����������_��.Invalidate();
	�������_�����.Invalidate();
	���_������_������.Invalidate();
	SignFromFile_label.Invalidate();
	DataFromFile_Label.Invalidate();*/
} 
// �������� ������ �����������
void CSignVerify_Dlg::UpdateProviders()
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
void CSignVerify_Dlg::UpdateLocations()
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
void CSignVerify_Dlg::UpdateStores()
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
void CSignVerify_Dlg::UpdateCerts()
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
// ������������ �������
std::vector <BYTE> CSignVerify_Dlg::DecodeBytesWithRadioBTN(BYTE * pBinSign, DWORD pcbBinary, DWORD ExtraSignFormat_Radio)
{
	std::vector <BYTE> aSign;
	if(ExtraSignFormat_Radio==0)
	{
		DWORD outLen;
		BYTE * buffer = ConvertBytes((TCHAR*)pBinSign,pcbBinary/sizeof(TCHAR),outLen,CRYPT_STRING_BASE64);
		if(buffer!=NULL)
		{
			aSign.clear();
			for(DWORD i=0;i<outLen;i++)
			{
				aSign.push_back(buffer[i]);
			}
			delete [] buffer;
		}
	}
	if(ExtraSignFormat_Radio==1)
	{
		DWORD outLen;
		BYTE * buffer = ConvertBytes((TCHAR*)pBinSign,pcbBinary/sizeof(TCHAR),outLen,CRYPT_STRING_HEX);
		if(buffer!=NULL)
		{
			aSign.clear();
			for(DWORD i=0;i<outLen;i++)
			{
				aSign.push_back(buffer[i]);
			}
			delete [] buffer;
		}

	}
	if(ExtraSignFormat_Radio==2) //BIT STRING
	{
		aSign.clear();
		for(DWORD i=0;i<pcbBinary;i+=8*sizeof(TCHAR))
		{
			BYTE curByte=0;
			for(int j=0;j<8;j++)
			{
				curByte|=1<<j;
			}
			aSign.push_back(curByte);
		}
	}
	if(ExtraSignFormat_Radio==3) //ASCII
	{
		aSign.clear();
		for(DWORD i=0;i<pcbBinary;i+=sizeof(TCHAR))
		{
			aSign.push_back(pBinSign[i]);
		}
	}
	if(ExtraSignFormat_Radio==4) //PureCopy
	{
		aSign.clear();
		for(DWORD i=0;i<pcbBinary;i++)
		{
			aSign.push_back(pBinSign[i]);
		}
	}
	return aSign;
}
// �������� ������ � ���
void CSignVerify_Dlg::AddToLog(_bstr_t msg) // ����� ��������� � ���
{
	CString sCurLog;
	���.GetWindowTextW(sCurLog);
	CString StrToAdd((LPCTSTR)msg);
	sCurLog+=StrToAdd.GetString();
	���.SetWindowTextW(sCurLog);
	���.LineScroll(���.GetLineCount());
	���.UpdateWindow();
	���.Invalidate();
}
// ������� ������ ���������� �������� �������
void CSignVerify_Dlg::CheckResultVerifySign(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey)
{
	if(VerifySign(aSign,aData,aPublicKey))
	{
		AddToLog(_T("������� �����\r\n"));
		ProccessIsDone=TRUE;
		ProccessIsStarted=FALSE;
		return;
	}
	else
	{
		if(!ProccessIsDone)
		{
			AddToLog(_T("������� �������\r\n"));
		}
	}
}
// ������� �������� ������� � ������� ����������� � ���������
void CSignVerify_Dlg::VerifySignWithCertSearch()
{
	std::vector <BYTE> aSign;
	std::vector <BYTE> aData;
	std::vector <BYTE> aPublicKey;
	DWORD StartCert=iCert;
	aSign=DecodeBytesWithRadioBTN(pBinSign, pcbBinary, ExtraSignFormat_Radio);
	if(!DataFromFile)
	{
		aData=DecodeBytesWithRadioBTN(File, FileLen, DataFormat_Radio);
	}
	else
	{
		aData=DecodeBytesWithRadioBTN(File, FileLen, 4);
	}
	do
	{
		ShowCertInfo();
		MakeMagicWithSignAndCheck(aSign,aData,aPublicKey);
		if(iCert==aCerts.size()-1)
		{
			iCert=0;
		}
		else
		{
			iCert++;
		}
	}
	while((iCert!=StartCert)|(!ProccessIsDone));
	AddToLog(_T("������� ��������.\r\n"));
}
// ������� �������� ������� ��� ������ �����������
void CSignVerify_Dlg::VerifySignWithoutCertSearch()
{
	std::vector <BYTE> aSign;
	aSign=DecodeBytesWithRadioBTN(pBinSign, pcbBinary, ExtraSignFormat_Radio);
	std::vector <BYTE> aData;
	if(!DataFromFile)
	{
		aData=DecodeBytesWithRadioBTN(File, FileLen, DataFormat_Radio);
	}
	else
	{
		aData=DecodeBytesWithRadioBTN(File, FileLen, 4);
	}
	std::vector <BYTE> aPublicKey;
	if(PubKeyInputSelected&PubKeyEntered)
	{
		for(DWORD i=0;i<nPubKeyLen;i++)
		{
			aPublicKey.push_back(PubKey[i]);
		}
	}
	MakeMagicWithSignAndCheck(aSign,aData,aPublicKey);
}
// �������, �������������� �������� ������� � ��������� �������� ������ ������� �������
void CSignVerify_Dlg::MakeMagicWithSignAndCheck(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey)
{
	CheckResultVerifySign(aSign,aData,aPublicKey);
	if((��������_�������_������_�_������.GetCheck())&(!ExtraSignFormat_PEM)&!ProccessIsDone)
	{
		AddToLog(_T("����� ������� ������...\r\n"));
		std::vector <BYTE> SignBuff;
		SignBuff.clear();
		for(DWORD i=0;i<aSign.size();i++)
		{
			SignBuff.push_back(aSign[aSign.size()-1-i]);
		}
		CheckResultVerifySign(SignBuff,aData,aPublicKey);
	}
	if((��������_������_�_�����_�����.GetCheck())&(!ExtraSignFormat_PEM)&!ProccessIsDone)
	{
		AddToLog(_T("����� ������ � ����� �����...\r\n"));
		std::vector <BYTE> SignBuff;
		SignBuff.clear();
		for(DWORD i=0;i<aSign.size();i++)
		{
			if(i<aSign.size()/2)
			{
				SignBuff.push_back(aSign[aSign.size()/2+i]);
			}
			else
			{
				SignBuff.push_back(aSign[i-aSign.size()/2]);
			}
		}
		CheckResultVerifySign(SignBuff,aData,aPublicKey);
	}
}
// ������� ������ ����������� � ���
void CSignVerify_Dlg::ShowCertInfo()
{
	if(CertChosen)
	{
		TCHAR pszNameString[256];
		CERT_CONTEXT curCert=aCerts.at(iCert);
		CertGetNameString(
			&curCert,
			CERT_NAME_SIMPLE_DISPLAY_TYPE,
			0,
			NULL,
			pszNameString,
			128);
		AddToLog(_T("�������:\r\n\""));
		AddToLog(aLocations.at(iLoc).sName.c_str());
		AddToLog(_T("\"\r\n���������:\r\n\""));
		AddToLog(aLocations.at(iLoc).aStores.at(iStore).c_str());
		AddToLog(_T("\"\r\n����������:\r\n\""));
		AddToLog(pszNameString);
		AddToLog(_T("\"\r\n"));	
	}
}
// ��������� ������� (������)
void CSignVerify_Dlg::OnBnClickedButton55()
{
	ProccessIsDone=FALSE;
	ProccessIsStarted=TRUE;
	if(!(SignFromFile|SignFromString))
	{
		AddToLog(_T("������� ��� �������� �����������\r\n"));
	}
	if(!(DataFromFile|DataFromString))
	{
		AddToLog(_T("������ ��� �������� �����������\r\n"));
	}
	if((SignFromFile|SignFromString)&(DataFromFile|DataFromString))
	{

		if(CertFromStoreSelected & StoreChosen & ���������_���_�����������_�_���������.GetCheck())
		{
			VerifySignWithCertSearch();
		}
		else
		{
			if((((CertFileChosen&CertFromFileSelected)|(CertFromStoreSelected & CertChosen))|(PubKeyInputSelected&PubKeyEntered)))
			{
				VerifySignWithoutCertSearch();
			}
			else
			{
				AddToLog(_T("�� ������ ���������� ��� ��������� ����\r\n"));
			}
		}
	}
	ProccessIsDone=TRUE;
	ProccessIsStarted=FALSE;
}
// ������� �������� ������� � ������� ��������� ������������
BOOL CSignVerify_Dlg::VerifySignWithCurCert(std::vector <BYTE> &aSign, std::vector <BYTE> &aData)
{
	if(hMyKey!=NULL)
	{
		CryptDestroyKey(hMyKey);
		hMyKey=NULL;
	}
	CERT_PUBLIC_KEY_INFO info;
	if(CertFromStoreSelected)
	{
		info=aCerts.at(iCert).pCertInfo->SubjectPublicKeyInfo;
	}
	else
	{
		info=hMyCert->pCertInfo->SubjectPublicKeyInfo;
	}
	if(CryptImportPublicKeyInfo(hMyProv,X509_ASN_ENCODING|PKCS_7_ASN_ENCODING,&info,&hMyKey))
	{

		if(hMyHash!=NULL)
		{
			CryptDestroyHash(hMyHash);
			hMyHash=NULL;
		}
		if(!CryptCreateHash(hMyProv, aHashAlgs.at(HashAlg).dwAlgId, 0, 0, &hMyHash))
		{
			AddToLog(_T("������ �������� ���-�������.\r\n"));
			ProccessIsDone=TRUE;
			return FALSE;
		}
		if(hMyHash!=NULL)
		{
			const BYTE* pData=&aData[0];
			if(���������������.GetCheck())
			{
				DWORD HashLen=0;
				if(!CryptGetHashParam(
					hMyHash,
					HP_HASHSIZE,
					NULL,
					&HashLen,
					0
					))
				{
					AddToLog(_T("������ ��������� ���������� ���-�������\r\n"));
					ProccessIsDone;
					return FALSE;
				}
				if((HashLen==aData.size()))
				{
					if(!CryptSetHashParam(hMyHash,HP_HASHVAL,pData,0))
					{
						AddToLog(_T("������ �������� ���� � ���-������\r\n"));
						ProccessIsDone;
						return FALSE;
					}
				}
				else
				{
					AddToLog(_T("����� ���� �� ������������� ����� ���� � ������������ ���������\r\n"));
					ProccessIsDone;
					return FALSE;
				}
			}
			else
			{
				if(!CryptHashData(hMyHash,pData,aData.size(),NULL))
				{
					AddToLog(_T("������ ���������� ���-������� �������.\r\n"));
					ProccessIsDone=TRUE;
					return FALSE;
				}
			}
				const BYTE* pSign=&aSign[0];
				if(CryptVerifySignature(hMyHash,pSign,aSign.size(),hMyKey,NULL,NULL))
				{
					return TRUE;
				}
				else
				{
					return FALSE;

				}
		}
	}
	return FALSE;
}
// ������� �������� ������� � �������� ��������� �����
BOOL CSignVerify_Dlg::VerifySignWithPubKey(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> aPublicKey)
{
	if(hMyKey!=NULL)
	{
		CryptDestroyKey(hMyKey);
		hMyKey=NULL;
	}
	CERT_PUBLIC_KEY_INFO KeyInfo;
	KeyInfo.PublicKey.cbData=aPublicKey.size()+2;
	KeyInfo.PublicKey.cUnusedBits=0;
	aPublicKey.insert(aPublicKey.begin(), 0x40); // OCTET STRING 0440
	aPublicKey.insert(aPublicKey.begin(),0x04);
	KeyInfo.PublicKey.pbData=&aPublicKey[0];
	PCCRYPT_OID_INFO pOIDInfo=NULL;
	for(DWORD i=0;i<aAlgs.size();i++)
	{
		if(aAlgs.at(i).sType=="Signature")
		{
			pOIDInfo = CryptFindOIDInfo(CRYPT_OID_INFO_ALGID_KEY,&aAlgs.at(i).dwAlgId,0);
			break;
		}
	}
	if(pOIDInfo!=NULL)
	{
		KeyInfo.Algorithm.pszObjId=(LPSTR)pOIDInfo->pszOID;
		KeyInfo.Algorithm.Parameters.pbData=NULL;
		KeyInfo.Algorithm.Parameters.cbData=0;
		std::vector<BYTE> pbData;
		if(AlgParams.size()>0)
		{
			KeyInfo.Algorithm.Parameters.pbData=ConvertBytes(&AlgParams[0],AlgParams.size(),KeyInfo.Algorithm.Parameters.cbData,CRYPT_STRING_HEX);
			if(KeyInfo.Algorithm.Parameters.pbData!=NULL)
			{
				for(DWORD i=0;i<KeyInfo.Algorithm.Parameters.cbData;i++)
				{
					pbData.push_back(KeyInfo.Algorithm.Parameters.pbData[i]);
				}
				delete [] KeyInfo.Algorithm.Parameters.pbData;
				KeyInfo.Algorithm.Parameters.pbData=&pbData[0];
			}
		}
		if(!CryptImportPublicKeyInfo(hMyProv,X509_ASN_ENCODING|PKCS_7_ASN_ENCODING,&KeyInfo,&hMyKey))
		{
			AddToLog(_T("������ ������� ���������� �����.\r\n"));
			ProccessIsDone=TRUE;
			return FALSE;
		}
		if(hMyKey!=NULL)
		{
			if(hMyHash!=NULL)
			{
				CryptDestroyHash(hMyHash);
				hMyHash=NULL;
			}
			if(!CryptCreateHash(hMyProv, aHashAlgs.at(HashAlg).dwAlgId, 0, 0, &hMyHash))
			{
				AddToLog(_T("������ �������� ���-�������.\r\n"));
				ProccessIsDone=TRUE;
				return FALSE;
			}
			if(hMyHash!=NULL)
			{
				const BYTE* pData=&aData[0];
				if(���������������.GetCheck())
				{
					DWORD HashLen=0;
					if(!CryptGetHashParam(
						hMyHash,
						HP_HASHSIZE,
						NULL,
						&HashLen,
						0
						))
					{
						AddToLog(_T("������ ��������� ���������� ���-�������\r\n"));
						ProccessIsDone;
						return FALSE;
					}
					if((HashLen==aData.size()))
					{
						if(!CryptSetHashParam(hMyHash,HP_HASHVAL,pData,0))
						{
							AddToLog(_T("������ �������� ���� � ���-������\r\n"));
							ProccessIsDone;
							return FALSE;
						}
					}
					else
					{
						AddToLog(_T("����� ���� �� ������������� ����� ���� � ������������ ���������\r\n"));
						ProccessIsDone;
						return FALSE;
					}
				}
				else
				{
					if(!CryptHashData(hMyHash,pData,aData.size(),NULL))
					{
						AddToLog(_T("������ ���������� ���-������� �������.\r\n"));
						ProccessIsDone=TRUE;
						return FALSE;
					}
				}

					const BYTE* pSign=&aSign[0];
					if(CryptVerifySignature(hMyHash,pSign,aSign.size(),hMyKey,NULL,NULL))
					{
						return TRUE;
					}
					else
					{
						return FALSE;

					}
			}
		}
		else
		{
			AddToLog(_T("������ ������� ���������� �����.\r\n��������� ��������� ������� ������ �������.\r\n"));
			ProccessIsDone=TRUE;
			return FALSE;
		}
	}
	AddToLog(_T("�� ������ �������� ������� � ����������������\r\n"));
	ProccessIsDone=TRUE;
	return FALSE;
}
// ������� �������� ������������� �������
BOOL CSignVerify_Dlg::VerifyDetachedSign(std::vector <BYTE> &aSign, std::vector <BYTE> &aData)
{
	CRYPT_DATA_BLOB myPemSign;
	myPemSign.cbData=aSign.size();
	myPemSign.pbData=&aSign[0];
	CRYPT_DATA_BLOB * pSignedMessageBlob=&myPemSign;
	CRYPT_VERIFY_MESSAGE_PARA VerifyParams;
	//����� ��������� "�������� �������"
	VerifyParams.cbSize = sizeof(CRYPT_VERIFY_MESSAGE_PARA);
	VerifyParams.dwMsgAndCertEncodingType = PKCS_7_ASN_ENCODING | X509_ASN_ENCODING;
	VerifyParams.hCryptProv = hMyProv;
	VerifyParams.pvGetArg = NULL;
	const BYTE* lpData[]={&aData[0]};
	DWORD DataSize[1];
	DataSize[0]=aData.size();
	//����� ������� ������� ���������� �������� �����������
	//����� CryptGetSignerCertificateCallback()
	//��� �� �������� ���� ������ �� ������� 
	VerifyParams.pfnGetSignerCertificate = NULL;
	//�������� ����� ������ ��� �������� ��������������� ���������
	if(���������������.GetCheck())
	{

		AddToLog(_T("������: ����� ���� �� ����� ���� ����������� ��� �������� ������������� �������.\r\n"));
		AddToLog(_T("� �������� ������ ��������� ���� ������, � �� �� ���.\r\n"));
		ProccessIsDone=TRUE;
		return FALSE;
	}
	if( CryptVerifyDetachedMessageSignature(&VerifyParams,
		0,pSignedMessageBlob->pbData,
		pSignedMessageBlob->cbData, 
		1,
		lpData,
		DataSize,
		NULL))
	{
		return TRUE;

	}
	else
	{
		return FALSE;
	}
}
// ������� ������ ������� �������� �������
BOOL CSignVerify_Dlg::VerifySign(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey) //�������� �������
{
	if((CryptoProviderChosen)&(CertChosen|CertFileChosen|PubKeyEntered)&(SignFromString|SignFromFile)&(DataFromString|DataFromFile)) // ������ ������
	{
		if(hMyProv!=NULL)
		{
			CryptReleaseContext(hMyProv, NULL);
			hMyProv=NULL;
		}
		if(!CryptAcquireContext(&hMyProv, NULL, aProviders.at(iProv).sName.c_str(), aProviders.at(iProv).dwType, CRYPT_VERIFYCONTEXT))
		{
			AddToLog(_T("������ ��������� ��������� ����������������\r\n"));
			ProccessIsDone=TRUE;
			return FALSE;
		}
		//��������� ���� �� �����������
		if(hMyProv!=NULL)
		{
			if(!ExtraSignFormat_PEM) // ������� �� � ������� PEM
			{

				if(CertFromStoreSelected&CertChosen|CertFromFileSelected&CertFileChosen)
				{
					return VerifySignWithCurCert(aSign,aData);
				}
				if(PubKeyInputSelected&PubKeyEntered)
				{
					return VerifySignWithPubKey(aSign,aData,aPublicKey);
				}
			}
			else // Detached Message
			{

				return VerifyDetachedSign(aSign,aData);
			}
		}
	}
	return FALSE;
}
// �������������� ������ ������
BYTE* CSignVerify_Dlg::ConvertBytes(TCHAR* pBuffer, DWORD dwBuffLen, DWORD &OutBufferLen, int ConvertMode = 0)
{
	switch(ConvertMode)
	{
	case CRYPT_STRING_HEX:
		{
			if(CryptStringToBinary(pBuffer,dwBuffLen,CRYPT_STRING_HEX,NULL,&OutBufferLen,NULL,NULL))
			{
				BYTE* pOutBuffer=new BYTE[OutBufferLen];
				if(CryptStringToBinary(pBuffer,dwBuffLen,CRYPT_STRING_HEX,pOutBuffer,&OutBufferLen,NULL,NULL))
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
	case CRYPT_STRING_BASE64HEADER: //ASCII
		{
			if(CryptStringToBinaryA((CHAR*)pBuffer,dwBuffLen,CRYPT_STRING_BASE64HEADER,NULL,&OutBufferLen,NULL,NULL))
			{
				BYTE* pOutBuffer=new BYTE[OutBufferLen];
				if(CryptStringToBinaryA((CHAR*)pBuffer,dwBuffLen,CRYPT_STRING_BASE64HEADER,pOutBuffer,&OutBufferLen,NULL,NULL))
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
BYTE* CSignVerify_Dlg::ReadFile(CString sPath, DWORD &ullFileLen)
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
BytesParam CSignVerify_Dlg::TryDeterCoding(TCHAR* str, DWORD nStrLen)
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
				if(!((str[i]==_T('0'))|(str[i]==_T('1'))))
				{
					params.BIN=FALSE;
					params.HEX=TRUE;
				}
			}
			if(!params.BIN)
			{
				if(params.HEX)
				{
					if(!((str[i]>=_T('0'))&(str[i]<=_T('9'))))
					{
						if((str[i]>=_T('a'))&(str[i]<=_T('z')))
						{
							LowCase=TRUE;
						}
						if((str[i]>=_T('A'))&(str[i]<=_T('Z')))
						{
							UpperCase=TRUE;
						}
						if((LowCase&UpperCase)|(!(((str[i]>=_T('a'))&(str[i]<=_T('z')))|((str[i]>=_T('A'))&(str[i]<=_T('Z'))))))
						{
							params.HEX=FALSE;
							params.BASE64=TRUE;
						}
					}
				}
				if(!params.HEX)
				{
					if(!(((str[i]>=_T('0'))&(str[i]<=_T('9')))|
						((str[i]>=_T('A'))&(str[i]<=_T('Z')))|
						((str[i]>=_T('a'))&(str[i]<=_T('z')))|
						(str[i]==_T('='))|
						(str[i]==_T('/'))|
						(str[i]==_T('+'))))
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
void CSignVerify_Dlg::UpdateExtraBOOLs(BytesParam ExtraSignParam)
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
				if(!CryptStringToBinary((TCHAR*)ExtraSignParam.pBytes,ExtraSignParam.Length,CRYPT_STRING_BASE64,NULL,&len,NULL,NULL))
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
void CSignVerify_Dlg::OnCbnSelchangeCombo1()
{
	iProv=����������������.GetCurSel();
	if(iProv>0)
	{
		CryptoProviderChosen=TRUE;
		if(CryptAcquireContext(&hMyProv, NULL, aProviders.at((DWORD)(iProv-1)).sName.c_str(), aProviders.at((DWORD)(iProv-1)).dwType, CRYPT_VERIFYCONTEXT))
		{
			aAlgs=SuperCryptoAPI::getAlgs(hMyProv);
			aHashAlgs.clear();
			for(DWORD i=0;i<aAlgs.size();i++)
			{
				if(aAlgs.at(i).sType=="Hash")
				{
					aHashAlgs.push_back(aAlgs[i]);
				}
			}
			if(aProviders.at((DWORD)(iProv-1)).sName==_T("Crypto-Pro GOST R 34.10-2001 Cryptographic Service Provider\0"))
			{
				CString standart_hex=_T("301206072A85030202230106072A850302021E01");
				AlgParams.clear();
				for(int i=0;i<standart_hex.GetLength();i++)
				{
					AlgParams.push_back(standart_hex[i]);
				}
			}
			if(aProviders.at((DWORD)(iProv-1)).sName==_T("Crypto-Pro GOST R 34.10-2012 Strong Cryptographic Service Provider"))
			{
				
				CString standart_hex=_T("30 15 06 09 2A 85 03 07 01 02 01 02 01 06 08 2A 85 03 07 01 01 02 03");
				standart_hex.Remove(_T(' '));
				AlgParams.clear();
				for(int i=0;i<standart_hex.GetLength();i++)
				{
					AlgParams.push_back(standart_hex[i]);
				}
			}
		}
		else
		{
				AddToLog(_T("������ ��������� ��������� ����������������\r\n"));
		}
	}
	else
	{
		CryptoProviderChosen=FALSE;
	}
	UpdateFieldsLighting();
	iProv--;
}
// ������� ������� (���������)
void CSignVerify_Dlg::OnCbnSelchangeCombo2()
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
void CSignVerify_Dlg::OnCbnSelchangeCombo3()
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
void CSignVerify_Dlg::OnCbnSelchangeCombo4()
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
// � ��������� (������)
void CSignVerify_Dlg::OnBnClickedButton2()
{
	CAboutDlg About;
	About.DoModal();
	// TODO: �������� ���� ��� ����������� �����������
}
// ������������� (������)
void CSignVerify_Dlg::OnBnClickedButton1()
{
	USES_CONVERSION;
	ExtraSettings ExtraDlg(ExtraSignFormat_PEM,ExtraSignFormat_Radio,aHashAlgs,HashAlg,AlgParams);
	INT_PTR nResponse=ExtraDlg.DoModal();
	if(nResponse==IDOK)
	{
		ExtraSignFormat_Radio=ExtraDlg.SignFormat_Radio;
		ExtraSignFormat_PEM=ExtraDlg.SignFormat_PEM;
		HashAlg=ExtraDlg.HashIndex;
		AlgParams.clear();
		for(DWORD i=0;i<(DWORD)ExtraDlg.SignParams.GetLength();i++)
		{
			AlgParams.push_back(ExtraDlg.SignParams[i]);
		}
	}
}
// ������� ���� ������� (������)
void CSignVerify_Dlg::OnEnChangeMfceditbrowse4()
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
			CStringA Sign;
			for(DWORD i=0;i<pcbBinary;i++)
			{
				Sign+=pBinSign[i];
			}
			Sign.Remove(_T(' '));
			Sign.Remove(_T('\t'));
			Sign.Remove(_T('\r'));
			Sign.Remove(_T('\n'));
			CString Sign_TCHAR(Sign);
			delete [] pBinSign;
			pcbBinary=Sign_TCHAR.GetLength()*sizeof(TCHAR);
			pBinSign=new BYTE[pcbBinary];
			memcpy(pBinSign, (VOID*)LPCTSTR(Sign_TCHAR), pcbBinary);
			UpdateExtraBOOLs(TryDeterCoding((TCHAR*)(pBinSign),Sign_TCHAR.GetLength()));

		}
		else
		{
			SignFromFile=FALSE;
		}
	}
	UpdateFieldsLighting();
}
// ������� ���� � ������� (������)
void CSignVerify_Dlg::OnEnChangeMfceditbrowse5()
{
	CString sPath;
	����������.GetWindowTextW(sPath);
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
			UpdateFieldsLighting();
			return;
		}
	}
	DataFromFile=FALSE;
	UpdateFieldsLighting();
}
// ������ ������� (���������)
void CSignVerify_Dlg::OnEnChangeEdit1()
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
		UpdateExtraBOOLs(TryDeterCoding((TCHAR*)((LPCTSTR)sign),sign.GetLength()));
		{
			if(pBinSign!=NULL)
			{
				delete [] pBinSign;
				pBinSign=NULL;
			}
			pcbBinary=sign.GetLength()*sizeof(TCHAR);
			pBinSign = new BYTE[pcbBinary];
			memcpy(pBinSign, (VOID*)LPCTSTR(sign), sign.GetLength()*sizeof(TCHAR));


		}
	}
	else
	{
		SignFromString=FALSE;
	}
	UpdateFieldsLighting();
}
// ������ ������ (���������)
void CSignVerify_Dlg::OnEnChangeEdit3()
{
	CString data;
	������.GetWindowText(data);
	if(data.GetLength()>0)
	{
		if(File!=NULL)
		{
			free(File);
			File=NULL;
		}
		FileLen=data.GetLength()*sizeof(TCHAR);
		if(FileLen>0)
		{
			File=new BYTE[FileLen];
			DataFromString=TRUE;
			DataFromFile=FALSE;

			memcpy(File, (VOID*)LPCTSTR(data), FileLen);
		}
		else
		{
			DataFromString=FALSE;
		}
	}

	UpdateFieldsLighting();
}
// ������� ���������� (�����������)
void CSignVerify_Dlg::OnBnClickedRadio1()
{
	iCertFrom=0;
	CertFromStoreSelected=TRUE;
	CertFromFileSelected=FALSE;
	PubKeyInputSelected=FALSE;
	PubKeyEntered=FALSE;
	UpdateFieldsLighting();
}
//������� ���� � ������������ (�����������)
void CSignVerify_Dlg::OnBnClickedRadio2()
{
	iCertFrom=1;
	CertFromStoreSelected=FALSE;
	CertFromFileSelected=TRUE;
	PubKeyInputSelected=FALSE;
	UpdateFieldsLighting();
}
// ������ ���� (�����������)
void CSignVerify_Dlg::OnBnClickedRadio3()
{
	iCertFrom=2;
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
		TCHAR * pStr = (TCHAR*)&EnterKeyDlg.PublicKey.GetString()[0];
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
					PubKey=ConvertBytes((TCHAR*)pBuffer,nBuffSize,nPubKeyLen,CRYPT_STRING_HEX);
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
// ����������� ������� ��������
BOOL CSignVerify_Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	return CDialogEx::OnEraseBkgnd(pDC);
	return TRUE;
}
// �������� ��� (������)
void CSignVerify_Dlg::OnBnClickedButton3()
{
	���.SetWindowTextW(_T(""));
	���.UpdateData();
}

// ������� ���� ����������� (������ ������ �����)
void CSignVerify_Dlg::OnEnChangeMfceditbrowse3()
{
	OnBnClickedRadio2();
	((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
	CString sPath;
	���������������.GetWindowTextW(sPath);
	if(sPath.GetLength()>2)
	{
		DWORD nCerFileLen=0;
		BYTE* CerFile=NULL;
		CerFile=ReadFile(sPath,nCerFileLen);
		if(CerFile!=NULL)
		{

			if(hMyCert!=NULL)
			{
				CertFreeCertificateContext(hMyCert);
				hMyCert=NULL;
			}
			std::vector <BYTE> CerFileEncoded;
			DWORD nCerFileEncodedLen;
			BYTE* pCerFileEncoded=ConvertBytes((TCHAR*)CerFile, nCerFileLen, nCerFileEncodedLen, CRYPT_STRING_BASE64HEADER);
			if(pCerFileEncoded!=NULL)
			{
				hMyCert=CertCreateCertificateContext(X509_ASN_ENCODING|PKCS_7_ASN_ENCODING,pCerFileEncoded,nCerFileEncodedLen);
				if(hMyCert!=NULL)
				{
					CertFileChosen=TRUE;
					delete [] pCerFileEncoded;
					delete [] CerFile;
					UpdateFieldsLighting();
					return;
				}
				delete [] pCerFileEncoded;
				pCerFileEncoded=NULL;
			}
		}
		if(CerFile!=NULL)
		{
			delete [] CerFile;
			CerFile=NULL;
		}
	}
	CertFileChosen=FALSE;
	
	UpdateFieldsLighting();
}

// ������ � ������� Base64 (�����������)
void CSignVerify_Dlg::OnBnClickedRadio4()
{
	DataFormat_Radio=0;
}

// ������ � ������� Hex (�����������)
void CSignVerify_Dlg::OnBnClickedRadio6()
{
	DataFormat_Radio=1;
}
// ������ � ������� BIT STRING (�����������)
void CSignVerify_Dlg::OnBnClickedRadio7()
{
	DataFormat_Radio=2;
}
// ������ � ������� ASCII (�����������)
void CSignVerify_Dlg::OnBnClickedRadio8()
{
	DataFormat_Radio=3;
}
