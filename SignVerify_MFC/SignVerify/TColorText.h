/************************************************************************
* TColorText.h : Заголовочный файл производного класса от CStatic       *
* Автор: Максим Нестеров                                                *
/***********************************************************************/
#pragma once
#include "stdafx.h"
class TColorText : public CStatic	// Класс для статического текста, обеспечивающий изменение цвета
{
protected:
	DECLARE_MESSAGE_MAP( )

public:
	// Функция установки прозрачности
	void setTransparent( bool ATransparent = true );
	// Функция установки цвета фона
	void SetBackgroundColor( COLORREF );
	// Функция установки цвета текста
	void SetTextColor( COLORREF AColor);
	TColorText():CStatic() // Параметры по умолчанию
	{
		MTextColor = RGB( 0, 0, 0 );
		MBackgroundColor = RGB( 255, 255, 255 );
		MTransparent = true;
	}
protected:
	HBRUSH CtlColor( CDC* pDC, UINT nCtlColor );
private:
	bool MTransparent;
	COLORREF MBackgroundColor;  // Цвет фона
	COLORREF MTextColor;  // Цвет текста
};