/************************************************************************
* TColorText.cpp : �������� ���� ������������ ������ �� CStatic         *
* �����: ������ ��������                                                *
/***********************************************************************/
#pragma once
#include "stdafx.h"
#include "TColorText.h"


void TColorText::SetTextColor( COLORREF AColor ) // ��������� ����� ������
{
	MTextColor = AColor;
	Invalidate( );
}

BEGIN_MESSAGE_MAP( TColorText, CStatic )
	ON_WM_CTLCOLOR_REFLECT( )
END_MESSAGE_MAP( )
HBRUSH TColorText::CtlColor( CDC* pDC, UINT nCtlColor ) // ��������� �����
{
	pDC->SetTextColor( MTextColor );
	pDC->SetBkMode( TRANSPARENT );  
	if( MTransparent ) // �� ��������� ������������ "���������� �����" - ����������� ���� ����
	{
		HBRUSH hBrush = CreateSolidBrush(::GetSysColor(COLOR_3DFACE)); // ���� ����
		return hBrush;
	}
	else
		return (HBRUSH) CreateSolidBrush( MBackgroundColor ); 
}