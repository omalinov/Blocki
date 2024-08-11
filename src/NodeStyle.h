#pragma once
#include "StylingTypes.h"

namespace blocki
{
class NodeStyle
{
public:
	NodeStyle();
private:
	Color m_Color;
	Display m_Display;
	Position m_Position;
	Float m_Float;
	Overflow m_OverflowX;
	Overflow m_OverflowY;
	Distance m_MarginTop;
	Distance m_MarginLeft;
	Distance m_MarginBottom;
	Distance m_MarginRight;
	Length m_PaddingTop;
	Length m_PaddingLeft;
	Length m_PaddingBottom;
	Length m_PaddingRight;
	BorderWidth m_BorderTopWidth;
	BorderWidth m_BorderLeftWidth;
	BorderWidth m_BorderBottomWidth;
	BorderWidth m_BorderRightWidth;
	BorderColor m_BorderTopColor;
	BorderColor m_BorderLeftColor;
	BorderColor m_BorderBottomColor;
	BorderColor m_BorderRightColor;
	BorderStyle m_BorderTopStyle;
	BorderStyle m_BorderLeftStyle;
	BorderStyle m_BorderBottomStyle;
	BorderStyle m_BorderRightStyle;
	Distance m_Top;
	Distance m_Left;
	Distance m_Bottom;
	Distance m_Right;
};
}