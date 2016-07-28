
// SignVerify_MFCDlg.h : файл заголовка
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


// диалоговое окно CSignVerify_MFCDlg
class CSignVerify_MFCDlg : public CDialogEx
{
// Создание
public:
	CSignVerify_MFCDlg(CWnd* pParent = NULL);	// стандартный конструктор
	~CSignVerify_MFCDlg()	// Деструктор, освобождающий выделенную память
	{
		DestroyUsedMemory();
	}
// Данные диалогового окна
	enum { IDD = IDD_SIGNVERIFY_MAIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

// Функции и переменные, используемые в работе программы
protected:
// Крипторовайдер выбран
	BOOL CryptoProviderChosen;
// Выбран режим импорта сертификата из хранилища
	BOOL CertFromStoreSelected;
// Локация выбрана
	BOOL LocationChosen;
// Хранилище выбрано
	BOOL StoreChosen;
// Сертификат выбран
	BOOL CertChosen;
// Выбран режим импорта сертификата из файла
	BOOL CertFromFileSelected;
// Файл сертификата выбран
	BOOL CertFileChosen;
// Выбран режим импорта публичного ключа
	BOOL PubKeyInputSelected;
// Публичный ключ введен
	BOOL PubKeyEntered;
// Выбран поиск по всем хранилищам
	BOOL SearchAllStoresSelected;
// Выбран поиск по всем сертификатам в хранилище
	BOOL SearchAllCertsSelected;
// Выбрана подпись из файла
	BOOL SignFromFile;
// Выбран ввод подписи
	BOOL SignFromString;
// Подпись в формате PEM
	BOOL ExtraSignFormat_PEM;
// Формат подписи 0=
	DWORD ExtraSignFormat_Radio;
// Выбраны данные из файла
	BOOL DataFromFile;
// Выбран ввод данных
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
// Элементы окна и функции
public:
	afx_msg void OnCbnSelchangeCombo1();
	TColorText Криптопровайдер;
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox Локации;
	CComboBox Хранилища;
	CComboBox Сертификаты;
	CButton Перебрать_все_хранилища;
	CButton Перебрать_все_сертификаты_в_хранилище;
	TColorText Локация_хранилища;
	TColorText Хранилище;
	TColorText Сертификат;
	int iCertFrom;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
	CButton HelpButton;
	TColorText Получить_сертификат_из;
	TColorText Подпись_метка;
	TColorText Или_ввести_данные;
	CComboBox Криптопровайдеры;
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnEnChangeMfceditbrowse4();
	CMFCEditBrowseCtrl ФайлПодписи;
	afx_msg void OnEnChangeEdit1();
	CEdit Подпись;
	afx_msg void OnEnChangeEdit3();
	CEdit Данные;
	CButton Поменять_порядок_байтов_в_частях;
	CButton Поменять_правую_и_левую_части;
	//afx_msg void OnBnClickedCheck4();
	CEdit Лог;
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio6();
	TColorText SignFromFile_label;
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeMfceditbrowse5();
	TColorText DataFromFile_Label;
};
