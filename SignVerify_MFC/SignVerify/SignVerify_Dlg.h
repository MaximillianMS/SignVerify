/************************************************************************
* SignVerify_Dlg.h : файл заголовка главного окна приложения            *
* Автор: Максим Нестеров                                                *
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


// диалоговое окно CSignVerify_Dlg
class CSignVerify_Dlg : public CDialogEx
{
// Создание
public:
	CSignVerify_Dlg(CWnd* pParent = NULL);	// стандартный конструктор
	~CSignVerify_Dlg()	// Деструктор, освобождающий выделенную память
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
// Отдельный шрифт для CEdit
	CFont myFont;
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
// Формат подписи 0=BASE64 1=HEX 2=BIN 3=NONE
	DWORD ExtraSignFormat_Radio;
// Выбраны данные из файла
	BOOL DataFromFile;
// Выбран ввод данных
	BOOL DataFromString;
// Процесс проверка подписи начат
	BOOL ProccessIsStarted;
// Процесс проверка подписи завершен
	BOOL ProccessIsDone;
// Подпись верна
	BOOL SignVerified;
// Дескриптор криптопровайдера
	HCRYPTPROV hMyProv;
// Дескриптор хранилища
	HCERTSTORE  hMyStore;
// Дескриптор ключа
	HCRYPTKEY hMyKey;
// Дескриптор хеша
	HCRYPTHASH hMyHash;
// Контекст сертификата
	PCCERT_CONTEXT hMyCert;
// Указатель на подпись в виде массива байтов
	BYTE * pBinSign;
// Размер массива байтов pBinSign
	DWORD  pcbBinary;
// Указатель на данные в виде массива байтов
	byte *File;
// Размер массива байтов File
	DWORD FileLen;
// Указатель на открытый ключ в виде массива байтов
	BYTE* PubKey;
// Размер массива байтов PubKey
	DWORD nPubKeyLen;
// Массив информации о криптопровайдерах
	std::vector <SuperCryptoAPI::ProviderInfo> aProviders;
// Массив информации о локациях
	std::vector <SuperCryptoAPI::Location> aLocations;
// Массив информации об алгоритмах
	std::vector <SuperCryptoAPI::AlgInfo> aAlgs;
// Массив информации только об алгоритмах типа "Hash"
	std::vector <SuperCryptoAPI::AlgInfo> aHashAlgs;
// Массив контекстов сертификатов
	std::vector <CERT_CONTEXT> aCerts;
// Параметры подписи, используемые, при импорте открытого ключа.
	std::vector <TCHAR> AlgParams;
// Порядковый номер выбранного провайдера в массиве aProviders
	int iProv;
// Порядковый номер выбранной локации в массиве aLocations
	int iLoc;
// Порядковый номер выбранного хранилища в выбранной локации
	int iStore;
// Порядковый номер выбранного сертификата в выбранном хранилище
	int iCert;
// Порядковый номер выбранного хеш-алгоритма, по умолчанию - первый
	int HashAlg;
// Функция обновления списка сертификатов
	void UpdateCerts();
// Функция обновления списка хранилищ
	void UpdateStores();
// Функция обновления списка локаций
	void UpdateLocations();
// Функция обновления списка криптопровайдеров
	void UpdateProviders();
// Функция декодирования подписи и данных
	std::vector <BYTE> DecodeBytesWithRadioBTN(BYTE * pBinSign, DWORD pcbBinary, DWORD ExtraSignFormat_Radio);
// Функция обновления дополнительных параметров, отвечающих за форматирование подписи
	void UpdateExtraBOOLs(BytesParam ExtraSignParam);
// Функция проверки подписи
	BOOL VerifySign(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey);
// Функция добавления информации в лог
	void AddToLog(_bstr_t msg);
// Функция конвертации из строки в массив байтов для режимов HEX, Base64
	BYTE* ConvertBytes(TCHAR* pBuffer, DWORD dwBuffLen, DWORD &OutBufferLen, int ConvertMode);
// Инициализация параметров
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
// Функция подсветки меток
	void UpdateFieldsLighting();
// Функция чтения файла
	BYTE* ReadFile(CString sPath, DWORD &ullFileLen);
// Функция, определяющая кодирование строки символов
	BytesParam TryDeterCoding(TCHAR* str, DWORD nStrLen);
// Функция инициализации и освобождения памяти (Reset)
	void MyProgramInit();
// Функция освобождения памяти
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
// Функция вывода информации об сертификате в лог
    void ShowCertInfo();
// Функция проверки подписи с текущим выбранным сертификатом
	BOOL VerifySignWithCurCert(std::vector <BYTE> &aSign, std::vector <BYTE> &aData);
// Функция проверки отсоединенной подписи
	BOOL VerifyDetachedSign(std::vector <BYTE> &aSign, std::vector <BYTE> &aData);
// Функция проверки подписи с импортом открытого ключа
	BOOL VerifySignWithPubKey(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey);
// Функция вывода результата проверки подписи
	void CheckResultVerifySign(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey);
// Функция проверки подписи с поиском сертификата в хранилище
	void VerifySignWithCertSearch();
// Функция проверки подписи без поиска сертификата
	void VerifySignWithoutCertSearch();
// Функция, обеспечивающая проверку подписи с различным порядком байтов массива подписи
	void MakeMagicWithSignAndCheck(std::vector <BYTE> &aSign, std::vector <BYTE> &aData, std::vector <BYTE> &aPublicKey);
// Элементы окна и обработчики
public:
	TColorText Криптопровайдер;
	TColorText Локация_хранилища;
	TColorText Хранилище;
	TColorText Сертификат;
	TColorText Получить_сертификат_из;
	TColorText Подпись_метка;
	TColorText Или_ввести_данные;
	TColorText SignFromFile_label;
	TColorText DataFromFile_Label;
	CComboBox Локации;
	CComboBox Хранилища;
	CComboBox Сертификаты;
	CComboBox Криптопровайдеры;
	CButton Перебрать_все_хранилища;
	CButton Перебрать_все_сертификаты_в_хранилище;
	CButton HelpButton;
	CButton Поменять_порядок_байтов_в_частях;
	CButton Поменять_правую_и_левую_части;
	CEdit Подпись;
	CEdit Данные;
	CEdit Лог;
	// Источник публичного ключа
	int iCertFrom;
	int DataFormat_Radio;
	CMFCEditBrowseCtrl ФайлПодписи;
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
	CMFCEditBrowseCtrl ФайлСертификата;
	CMFCEditBrowseCtrl ФайлДанных;
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	CButton ИспользуетсяХеш;
};
