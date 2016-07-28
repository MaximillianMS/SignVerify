// EnterKey.cpp: файл реализации
//
#pragma once
#include "stdafx.h"
//#include "SignVerify.h"
#include "EnterKey.h"
#include "afxdialogex.h"


// диалоговое окно EnterKey

IMPLEMENT_DYNAMIC(EnterKey, CDialogEx)

	EnterKey::EnterKey(CWnd* pParent /*=NULL*/)
	: CDialogEx(EnterKey::IDD, pParent)
{

}

EnterKey::~EnterKey()
{
}

void EnterKey::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_KEY, KeyInput);
	DDX_Control(pDX, IDC_CHECK_HEX, Hex);
	DDX_Control(pDX, IDC_CHECK_BASE64, Base64);
}


BEGIN_MESSAGE_MAP(EnterKey, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_KEY, &EnterKey::OnEnChangeEditKey)
	ON_BN_CLICKED(IDOK, &EnterKey::OnBnClickedOk)
END_MESSAGE_MAP()

void EnterKey::TryDeterCoding()
{
	Hex.SetCheck(FALSE);
	Base64.SetCheck(FALSE);
	if(PublicKey.GetLength()>0)
	{
		Base64isChosen=FALSE;
		HEXisChosen=TRUE;
		BOOL UpperCase=FALSE;
		BOOL LowCase=FALSE;
		for(DWORD i=0;i<(DWORD)PublicKey.GetLength();i++)
		{
			if(HEXisChosen)
			{
				if(!((PublicKey[i]>='0')&(PublicKey[i]<='9')))
				{
					if((PublicKey[i]>='a')&(PublicKey[i]<='z'))
					{
						LowCase=TRUE;
					}
					if((PublicKey[i]>='A')&(PublicKey[i]<='Z'))
					{
						UpperCase=TRUE;
					}
					if((LowCase&UpperCase)|(!(((PublicKey[i]>='a')&(PublicKey[i]<='z'))|((PublicKey[i]>='A')&(PublicKey[i]<='Z')))))
					{
						HEXisChosen=FALSE;
						Base64isChosen=TRUE;
					}
				}
			}
			if(!HEXisChosen)
			{
				if(!(((PublicKey[i]>='0')&(PublicKey[i]<='9'))|
					((PublicKey[i]>='A')&(PublicKey[i]<='Z'))|
					((PublicKey[i]>='a')&(PublicKey[i]<='z'))|
					(PublicKey[i]=='=')|
					(PublicKey[i]=='/')|
					(PublicKey[i]=='+')))
				{
					Base64isChosen=FALSE;
					break;
				}
			}
		}
		if(HEXisChosen)
		{
			Hex.SetCheck(TRUE);
			Base64.SetCheck(FALSE);
		}
		if(Base64isChosen)
		{
			Hex.SetCheck(FALSE);
			Base64.SetCheck(TRUE);
		}
		HEXisChosen=FALSE;
		Base64isChosen=FALSE;
	}
}

// обработчики сообщений EnterKey

void EnterKey::OnEnChangeEditKey()
{
	PublicKey.Empty();
	KeyInput.GetWindowTextW(PublicKey);
	PublicKey.Remove(_T(' '));
	PublicKey.Remove(_T('\t'));
	PublicKey.Remove(_T('\r'));
	PublicKey.Remove(_T('\n'));
	TryDeterCoding();
}


void EnterKey::OnBnClickedOk()
{
	if(Hex.GetCheck())
	{
		HEXisChosen=TRUE;
	}
	else
	{
		HEXisChosen=FALSE;
	}
	if(Base64.GetCheck())
	{
		Base64isChosen=TRUE;
	}
	else
	{
		Base64isChosen=FALSE;
	}
	CDialogEx::OnOK();
}
