// ExtraSettings.cpp: файл реализации
//
#pragma once
#include "stdafx.h"
//#include "SignVerify_MFC.h"
#include "ExtraSettings.h"
#include "afxdialogex.h"


// диалоговое окно ExtraSettings

IMPLEMENT_DYNAMIC(ExtraSettings, CDialogEx)

ExtraSettings::ExtraSettings(BOOL ExtraSignFormatPEM, int ExtraSignFormat_Radio, CWnd* pParent /*=NULL*/)
	: CDialogEx(ExtraSettings::IDD, pParent)
	, SignFormat_Radio(ExtraSignFormat_Radio)
	, SignFormat_PEM(ExtraSignFormatPEM)
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
}


BEGIN_MESSAGE_MAP(ExtraSettings, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений ExtraSettings

