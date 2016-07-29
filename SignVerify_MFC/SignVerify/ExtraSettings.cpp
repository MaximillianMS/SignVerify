/************************************************************************
* ExtraSettings.cpp : файл реализации окна с параметрами подписи        *
* Автор: Максим Нестеров                                                *
/***********************************************************************/
#pragma once
#include "stdafx.h"
#include "ExtraSettings.h"
#include "afxdialogex.h"


// диалоговое окно ExtraSettings

IMPLEMENT_DYNAMIC(ExtraSettings, CDialogEx)
BOOL ExtraSettings::OnInitDialog()
{
	CDialogEx::OnInitDialog();
// Инициализация параметров
	for(DWORD i=0;i<aHashAlgs.size();i++)
	{
		HashAlgs_combo.AddString(aHashAlgs[i].sAlgName.GetString());
	}
	HashAlgs_combo.SetCurSel(HashIndex);
	HashAlgs_combo.UpdateData();
	CString sBuffer;
	for(DWORD i=0;i<aAlgParams.size();i++)
	{
		sBuffer+=(TCHAR)aAlgParams[i];
	}
	SignParams_edit.SetWindowTextW(sBuffer);
	SignParams_edit.GetWindowTextW(SignParams);
	SignParams_edit.UpdateData();
	return TRUE;
}
ExtraSettings::ExtraSettings(BOOL ExtraSignFormatPEM, int ExtraSignFormat_Radio, std::vector <SuperCryptoAPI::AlgInfo> HashAlgs, DWORD HashId, std::vector <TCHAR> AlgParams, CWnd* pParent /*=NULL*/)
	: CDialogEx(ExtraSettings::IDD, pParent)
	, SignFormat_Radio(ExtraSignFormat_Radio)
	, SignFormat_PEM(ExtraSignFormatPEM)
	, HashIndex(HashId)
	, aHashAlgs(HashAlgs)
	, aAlgParams(AlgParams)
{
	
}

ExtraSettings::~ExtraSettings()
{
}

void ExtraSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, SignFormat_Radio);
	DDV_MinMaxInt(pDX, SignFormat_Radio, 0, 3);
	DDX_Check(pDX, IDC_CHECK3, SignFormat_PEM);
	DDX_Control(pDX, IDC_COMBO1, HashAlgs_combo);
	DDX_Control(pDX, IDC_EDIT2, SignParams_edit);
}


BEGIN_MESSAGE_MAP(ExtraSettings, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &ExtraSettings::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_RADIO5, &ExtraSettings::OnBnClickedRadio5)
END_MESSAGE_MAP()


// обработчики сообщений ExtraSettings


// Ввод текста
void ExtraSettings::OnEnChangeEdit2()
{
	CString params;
	SignParams_edit.GetWindowTextW(params);
	CStringA params_a(params);
	aAlgParams.clear();
	for(int i=0;i<params_a.GetLength();i++)
	{
		aAlgParams.push_back(params_a[i]);
	}
}


void ExtraSettings::OnBnClickedRadio5()
{
	// TODO: добавьте свой код обработчика уведомлений
}
