/************************************************************************
* TColorText.cpp : Исходный файл производного класса от CStatic         *
* Автор: Максим Нестеров                                                *
/***********************************************************************/
#pragma once
#include "stdafx.h"
#include "TColorText.h"


void TColorText::SetTextColor( COLORREF AColor ) // Установка цвета текста
{
	MTextColor = AColor;
	Invalidate( );
}

BEGIN_MESSAGE_MAP( TColorText, CStatic )
	ON_WM_CTLCOLOR_REFLECT( )
END_MESSAGE_MAP( )
HBRUSH TColorText::CtlColor( CDC* pDC, UINT nCtlColor ) // Отрисовка цвета
{
	pDC->SetTextColor( MTextColor );
	pDC->SetBkMode( TRANSPARENT );  
	if( MTransparent ) // По умолчанию используется "прозрачный режим" - стандартный цвет окна
	{
		HBRUSH hBrush = CreateSolidBrush(::GetSysColor(COLOR_3DFACE)); // цвет окна
		return hBrush;
	}
	else
		return (HBRUSH) CreateSolidBrush( MBackgroundColor ); 
}