#pragma once
#include "stdafx.h"
#include "TColorText.h"


void TColorText::SetTextColor( COLORREF AColor )
{
	MTextColor = AColor;
	Invalidate( );
}

BEGIN_MESSAGE_MAP( TColorText, CStatic )
	ON_WM_CTLCOLOR_REFLECT( )
END_MESSAGE_MAP( )

HBRUSH TColorText::CtlColor( CDC* pDC, UINT nCtlColor )
{
	pDC->SetTextColor( MTextColor );
	pDC->SetBkMode( TRANSPARENT );  // we do not want to draw background when drawing text. 
	// background color comes from drawing the control background.
	if( MTransparent )
		return (HBRUSH)GetStockObject(NULL_BRUSH);  // return nullptr to indicate that the parent object 
	// should supply the brush. it has the appropriate background color.
	else
		return (HBRUSH) CreateSolidBrush( MBackgroundColor );  // color for the empty area of the control
}