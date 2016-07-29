/************************************************************************
* TColorText.h : ������������ ���� ������������ ������ �� CStatic       *
* �����: ������ ��������                                                *
/***********************************************************************/
#pragma once
#include "stdafx.h"
class TColorText : public CStatic	// ����� ��� ������������ ������, �������������� ��������� �����
{
protected:
	DECLARE_MESSAGE_MAP( )

public:
	// ������� ��������� ������������
	void setTransparent( bool ATransparent = true );
	// ������� ��������� ����� ����
	void SetBackgroundColor( COLORREF );
	// ������� ��������� ����� ������
	void SetTextColor( COLORREF AColor);
	TColorText():CStatic() // ��������� �� ���������
	{
		MTextColor = RGB( 0, 0, 0 );
		MBackgroundColor = RGB( 255, 255, 255 );
		MTransparent = true;
	}
protected:
	HBRUSH CtlColor( CDC* pDC, UINT nCtlColor );
private:
	bool MTransparent;
	COLORREF MBackgroundColor;  // ���� ����
	COLORREF MTextColor;  // ���� ������
};