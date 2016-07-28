
// SignVerify_MFCDlg.cpp : файл реализации
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
// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	// Реализация
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


// диалоговое окно CSignVerify_MFCDlg




CSignVerify_MFCDlg::CSignVerify_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignVerify_MFCDlg::IDD, pParent)
	, iCertFrom(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSignVerify_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, Криптопровайдер);
	DDX_Control(pDX, IDC_COMBO2, Локации);
	DDX_Control(pDX, IDC_COMBO3, Хранилища);
	DDX_Control(pDX, IDC_COMBO4, Сертификаты);
	DDX_Control(pDX, IDC_CHECK4, Перебрать_все_хранилища);
	DDX_Control(pDX, IDC_CHECK3, Перебрать_все_сертификаты_в_хранилище);
	DDX_Control(pDX, IDC_STATIC2, Локация_хранилища);
	DDX_Control(pDX, IDC_STATIC3, Хранилище);
	DDX_Control(pDX, IDC_STATIC4, Сертификат);
	DDX_Radio(pDX, IDC_RADIO1, iCertFrom);
	DDX_Control(pDX, IDC_BUTTON2, HelpButton);
	DDX_Control(pDX, IDC_STATIC5, Получить_сертификат_из);
	DDX_Control(pDX, IDC_STATIC8, Подпись_метка);
	DDX_Control(pDX, IDC_STATIC12, Или_ввести_данные);
	DDX_Control(pDX, IDC_COMBO1, Криптопровайдеры);
	DDX_Control(pDX, IDC_MFCEDITBROWSE4, ФайлПодписи);
	DDX_Control(pDX, IDC_EDIT1, Подпись);
	DDX_Control(pDX, IDC_EDIT3, Данные);
	DDX_Control(pDX, IDC_CHECK2, Поменять_порядок_байтов_в_частях);
	DDX_Control(pDX, IDC_CHECK1, Поменять_правую_и_левую_части);
	DDX_Control(pDX, IDC_EDIT2, Лог);
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


// обработчики сообщений CSignVerify_MFCDlg

BOOL CSignVerify_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	MyProgramInit();

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CSignVerify_MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CSignVerify_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Инициализация переменных, освобождение памяти
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
// Подсветка меток
void CSignVerify_MFCDlg::UpdateFieldsLighting() //Подсветка полей
{
	if(CryptoProviderChosen)
	{
		Криптопровайдер.SetTextColor(green);
	}
	else
	{
		Криптопровайдер.SetTextColor(red);
	}

	if(CertFromStoreSelected)
	{
		Получить_сертификат_из.SetTextColor(yellow);
		Локации.EnableWindow(TRUE);
		Хранилища.EnableWindow(TRUE);
		Сертификаты.EnableWindow(TRUE);
		Перебрать_все_хранилища.EnableWindow(TRUE);
		Перебрать_все_сертификаты_в_хранилище.EnableWindow(TRUE);

		if(LocationChosen)
		{
			Локация_хранилища.SetTextColor(green);
			if(StoreChosen)
			{
				Хранилище.SetTextColor(green);
				if(CertChosen)
				{
					Сертификат.SetTextColor(green);
					Получить_сертификат_из.SetTextColor(green);
				}
				else
				{
					Сертификат.SetTextColor(red);
				}
			}
			else
			{
				Хранилище.SetTextColor(red);
				Сертификат.SetTextColor(black);
				Сертификаты.EnableWindow(FALSE);
			}
		}
		else
		{
			Локация_хранилища.SetTextColor(red);
			Хранилище.SetTextColor(black);
			Сертификат.SetTextColor(black);
			Хранилища.EnableWindow(FALSE);
			Сертификаты.EnableWindow(FALSE);
		}

	}
	else
	{
		Локация_хранилища.SetTextColor(gray);
		Хранилище.SetTextColor(gray);
		Сертификат.SetTextColor(gray);
		Локации.EnableWindow(FALSE);
		Хранилища.EnableWindow(FALSE);
		Сертификаты.EnableWindow(FALSE);
		Перебрать_все_хранилища.EnableWindow(FALSE);
		Перебрать_все_сертификаты_в_хранилище.EnableWindow(FALSE);
		Перебрать_все_хранилища.SetCheck(BST_UNCHECKED);
		Перебрать_все_сертификаты_в_хранилище.SetCheck(BST_UNCHECKED);
	}
	if(CertFromFileSelected)
	{
		if(CertFileChosen)
		{
			Получить_сертификат_из.SetTextColor(green);
		}
		else
		{
			Получить_сертификат_из.SetTextColor(yellow);
		}
	}
	if(PubKeyInputSelected)
	{
		if(PubKeyEntered)
		{
			Получить_сертификат_из.SetTextColor(green);
		}
		else
		{
			Получить_сертификат_из.SetTextColor(yellow);
		}
	}
	if(SignFromString)
	{
		Подпись_метка.SetTextColor(green);
		SignFromFile_label.SetTextColor(black);
	}
	else
	{
		if(SignFromFile)
		{
			Подпись_метка.SetTextColor(black);
			SignFromFile_label.SetTextColor(green);
		}
		else
		{
			SignFromFile_label.SetTextColor(yellow);
			Подпись_метка.SetTextColor(yellow);
		}
	}
	if(DataFromString)
	{
		Или_ввести_данные.SetTextColor(green);
		DataFromFile_Label.SetTextColor(black);
	}
	else
	{
		if(DataFromFile)
		{
			Или_ввести_данные.SetTextColor(black);
			DataFromFile_Label.SetTextColor(green);
		}
		else
		{
			Или_ввести_данные.SetTextColor(yellow);
			DataFromFile_Label.SetTextColor(yellow);
		}
	}
	Invalidate();
} 
// Обновить список провайдеров
void CSignVerify_MFCDlg::UpdateProviders()
{
	Криптопровайдеры.Clear();
	Криптопровайдеры.UpdateData();
	Криптопровайдеры.AddString(_T("-----------------------------------------"));
	for(DWORD i=0;i<aProviders.size();i++)
	{
		Криптопровайдеры.AddString(aProviders.at(i).sName.c_str());
	}
}
// Обновить список локаций
void CSignVerify_MFCDlg::UpdateLocations()
{
	iLoc=-1;
	iStore=-1;
	iCert=-1;
	Хранилища.ResetContent();
	Хранилища.UpdateData();
	Сертификаты.ResetContent();
	Сертификаты.UpdateData();
	Локации.ResetContent();
	Локации.UpdateData();
	Локации.AddString(_T("-----------------------------------------"));
	for(DWORD i=0;i<aLocations.size();i++)
	{
		Локации.AddString(aLocations.at(i).sName.c_str());
	}
}
// Обновить список хранилищ
void CSignVerify_MFCDlg::UpdateStores()
{
	iStore=-1;
	iCert=-1;
	Сертификаты.ResetContent();
	Сертификаты.UpdateData();
	Хранилища.ResetContent();
	Хранилища.UpdateData();
	Хранилища.AddString(_T("-----------------------------------------"));
	if(iLoc>=0)
	{
		for(DWORD i=0;i<aLocations.at(iLoc).aStores.size();i++)
		{
			Хранилища.AddString(aLocations.at(iLoc).aStores.at(i).c_str());
		}
	}
}
// Обновить список сертификатов
void CSignVerify_MFCDlg::UpdateCerts()
{
	iCert=-1;
	Сертификаты.ResetContent();
	Сертификаты.UpdateData();
	Сертификаты.AddString(_T("-----------------------------------------"));
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
					Сертификаты.AddString(pszNameString);

				}
			}

		}
	}
}
// Добавить строку в лог
void CSignVerify_MFCDlg::AddToLog(_bstr_t msg) // Вывод сообщения в лог
{
	CString sCurLog;
	Лог.GetWindowTextW(sCurLog);
	CString StrToAdd((LPCTSTR)msg);
	sCurLog+=StrToAdd.GetString();
	Лог.SetWindowTextW(sCurLog);
	Лог.UpdateWindow();
}
// Проверить подпись
BOOL CSignVerify_MFCDlg::VerifySign() //Проверка подписи
{
	if((CryptoProviderChosen)&(CertChosen|CertFileChosen|PubKeyEntered)&(SignFromString|SignFromFile)&(DataFromString|DataFromFile)) // Логика работы
	{
		if(hMyProv!=NULL)
		{
			CryptReleaseContext(hMyProv, NULL);
			hMyProv=NULL;
		}
		CryptAcquireContext(&hMyProv, NULL, aProviders.at(iProv).sName.c_str(), aProviders.at(iProv).dwType, CRYPT_VERIFYCONTEXT);
		//Публичный ключ из сертификата
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
// Конвертировать массив байтов
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
// Считать файл
BYTE* CSignVerify_MFCDlg::ReadFile(CString sPath, DWORD &ullFileLen)
{
	CFile TheFile;
	CFileException fileException;
	if(!TheFile.Open((LPCTSTR)sPath,CFile::modeRead,&fileException))
	{
		AddToLog(_T("Ошибка открытия файла: "));
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

// Попытаться определить кодирование данных подписи
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
// Обновить переменные кодирования на основе функции TryDeterCoding
void CSignVerify_MFCDlg::UpdateExtraBOOLs(BytesParam ExtraSignParam)
{
	AddToLog(_T("Определяю формат подписи...\r\n"));
	if(ExtraSignParam.OTHER)
	{
		ExtraSignFormat_PEM=TRUE;
		ExtraSignFormat_Radio=3; // No dencoding
		AddToLog(_T("Подпись определена в формате PEM. Кодирование отсутствует.\r\n"));
	}
	else
	{
		if(ExtraSignParam.BASE64|ExtraSignParam.HEX|ExtraSignParam.BIN)
		{
			DWORD len=0;
			if(ExtraSignParam.BASE64)
			{
				ExtraSignFormat_Radio=0;
				AddToLog(_T("Будет использоваться декодирование подписи из формата BASE64.\r\n"));
				if(!CryptStringToBinaryA((CHAR*)ExtraSignParam.pBytes,ExtraSignParam.Length,CRYPT_STRING_BASE64,NULL,&len,NULL,NULL))
				{
					AddToLog(_T("Ошибка декодирования формата BASE64.\r\n"));
				}
			}
			if(ExtraSignParam.HEX)
			{
				ExtraSignFormat_Radio=1;
				AddToLog(_T("Будет использоваться декодирование подписи из формата HEX.\r\n"));
				len=ExtraSignParam.Length/2;
			}
			if(ExtraSignParam.BIN)
			{
				ExtraSignFormat_Radio=2;
				AddToLog(_T("Будет использоваться декодирование подписи из формата BIN.\r\n"));
				len=ExtraSignParam.Length/8;
			}
			len=len*8;
			if((len!=512)&(len!=1024)&(len!=2048))
			{
				ExtraSignFormat_PEM=TRUE;
				AddToLog(_T("Подпись определена в формате PEM.\r\n"));
			}
			else
			{
				ExtraSignFormat_PEM=FALSE;
				AddToLog(_T("Подпись определена в формате \"сырой\" подписи.\r\n"));
				AddToLog(_T("Длина подписи в битах: "));
				CString keylen;
				keylen.Format(_T("%d"),len);
				AddToLog(keylen+"\r\n");

			}
		}
		else
		{
			ExtraSignFormat_PEM=FALSE;
			ExtraSignFormat_Radio=3; // No dencoding
			AddToLog(_T("Подпись определена в формате \"сырых\" данных. Кодирование отсутствует.\r\n"));
		}
	}
}

// Выбрать крипторовайдер (комбобокс)
void CSignVerify_MFCDlg::OnCbnSelchangeCombo1()
{

	// TODO: добавьте свой код обработчика уведомлений
	iProv=Криптопровайдеры.GetCurSel();
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
// Выбрать Локацию (комбобокс)
void CSignVerify_MFCDlg::OnCbnSelchangeCombo2()
{
	// TODO: добавьте свой код обработчика уведомлений
	StoreChosen=FALSE;
	CertChosen=FALSE;
	iLoc=Локации.GetCurSel();
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
// Выбрать Хранилище (комбобокс)
void CSignVerify_MFCDlg::OnCbnSelchangeCombo3()
{
	// TODO: добавьте свой код обработчика уведомлений
	CertChosen=FALSE;
	iStore=Хранилища.GetCurSel();
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
// Выбрать Сертификат (комбобокс)
void CSignVerify_MFCDlg::OnCbnSelchangeCombo4()
{
	// TODO: добавьте свой код обработчика уведомлений
	iCert=Сертификаты.GetCurSel();
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
// Проверить подпись (кнопка)
void CSignVerify_MFCDlg::OnBnClickedOk()
{
	HashAlg=CALG_GR3411;
	ProccessIsDone=FALSE;
	ProccessIsStarted=TRUE;
	if(CertChosen & Перебрать_все_сертификаты_в_хранилище.GetCheck())
	{
		LastCert=iCert;
		do
		{
			if(VerifySign())
			{
				AddToLog(_T("Подпись верна\r\n"));
				Лог.Invalidate();
				ProccessIsDone=TRUE;
				ProccessIsStarted=FALSE;
				return;
			}
			else
			{
				AddToLog(_T("Подпись неверна\r\n"));
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
		AddToLog(_T("Ни один сертификат не подошел.\r\nПеребор закончен.\r\n"));
	}
	else
	{
		if(VerifySign())
		{
			AddToLog(_T("Подпись верна\r\n"));
			Лог.Invalidate();
			ProccessIsDone=TRUE;
			ProccessIsStarted=FALSE;
			return;
		}
		else
		{
			AddToLog(_T("Подпись неверна\r\n"));
		}
	}
	ProccessIsDone=TRUE;
	ProccessIsStarted=FALSE;
}
// О программе (кнопка)
void CSignVerify_MFCDlg::OnBnClickedButton2()
{
	CAboutDlg About;
	About.DoModal();
	// TODO: добавьте свой код обработчика уведомлений
}
// Дополнительно (кнопка)
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
// Выбрать файл подписи (кнопка)
void CSignVerify_MFCDlg::OnEnChangeMfceditbrowse4()
{
	CString sPath;
	ФайлПодписи.GetWindowTextW(sPath);
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
			Подпись.Clear();
			Подпись.UpdateData();
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
// Открыть файл с данными (кнопка)
void CSignVerify_MFCDlg::OnEnChangeMfceditbrowse5()
{
	CString sPath;
	ФайлПодписи.GetWindowTextW(sPath);
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
// Ввести подпись (текстбокс)
void CSignVerify_MFCDlg::OnEnChangeEdit1()
{
	CString sign;
	Подпись.GetWindowText(sign);
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
// Ввести данные (текстбокс)
void CSignVerify_MFCDlg::OnEnChangeEdit3()
{
	CString data;
	Данные.GetWindowText(data);
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

// Выбрать сертификат (радиокнопка)
void CSignVerify_MFCDlg::OnBnClickedRadio1()
{
	CertFromStoreSelected=TRUE;
	CertFromFileSelected=FALSE;
	PubKeyInputSelected=FALSE;
	PubKeyEntered=FALSE;
	UpdateFieldsLighting();
}
//Открыть файл с сертификатом (радиокнопка)
void CSignVerify_MFCDlg::OnBnClickedRadio2()
{

}
// Ввести ключ (радиокнопка)
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
						AddToLog(_T("Неверный ключ. Ошибка конвертации HEX.\r\n"));
						PubKeyEntered=FALSE;
					}
					else
					{
						AddToLog(_T("Длина ключа в байтах: "));
						CString keylen;
						keylen.Format(_T("%d"),nPubKeyLen);
						AddToLog(keylen+"\r\n");
						PubKeyEntered=TRUE;
					}
					delete [] pBuffer;
				}
				else
				{
					AddToLog(_T("Длина ключа в байтах: "));
					CString keylen;
					keylen.Format(_T("%d"),nPubKeyLen);
					AddToLog(keylen+"\r\n");
					PubKeyEntered=TRUE;
				}
			}
			else
			{
				nPubKeyLen=0;
				AddToLog(_T("Неверный ключ. Ошибка конвертации Base64.\r\n"));
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
					AddToLog(_T("Неверный ключ. Ошибка конвертации HEX.\r\n"));
					PubKeyEntered=FALSE;
				}
				else
				{
					AddToLog(_T("Длина ключа в байтах: "));
					CString keylen;
					keylen.Format(_T("%d"),nPubKeyLen);
					AddToLog(keylen+"\r\n");
					PubKeyEntered=TRUE;
				}
			}
			else
			{
				PubKey=ConvertBytes(pStr,nStrLen,nPubKeyLen);
				AddToLog(_T("Не выбрана конвертация ключа. Возможен некорректный ввод.\r\n"));
			}
		}
	}
	else
	{
		PubKeyEntered=FALSE;
	}
	UpdateFieldsLighting();
}
//  (радиокнопка)
void CSignVerify_MFCDlg::OnBnClickedRadio6()
{
	// TODO: добавьте свой код обработчика уведомлений
}

