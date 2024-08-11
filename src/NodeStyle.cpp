#include "NodeStyle.h"

namespace blocki
{

// Defaults are listed in the following locations
// https://www.w3.org/TR/2011/REC-CSS2-20110607/box.html
// https://www.w3.org/TR/2011/REC-CSS2-20110607/visuren.html
// https://www.w3.org/TR/css-color-4/
// https://www.w3.org/TR/2011/REC-CSS2-20110607/visufx.html
NodeStyle::NodeStyle()
	// todo: black is deliberately simple, make it correct in the future
	: m_Color(Color::CreateBlack())
	, m_Display(Display::Inline)
	, m_Position(Position::Static)
	, m_Float(Float::None)
	, m_OverflowX(Overflow::Visible)
	, m_OverflowY(Overflow::Visible)
	, m_MarginTop(Distance::CreateLength(Length::CreatePx(0)))
	, m_MarginLeft(Distance::CreateLength(Length::CreatePx(0)))
	, m_MarginBottom(Distance::CreateLength(Length::CreatePx(0)))
	, m_MarginRight(Distance::CreateLength(Length::CreatePx(0)))
	, m_PaddingTop(Length::CreatePx(0))
	, m_PaddingLeft(Length::CreatePx(0))
	, m_PaddingBottom(Length::CreatePx(0))
	, m_PaddingRight(Length::CreatePx(0))
	, m_BorderTopWidth(BorderWidth::CreateMedium())
	, m_BorderLeftWidth(BorderWidth::CreateMedium())
	, m_BorderBottomWidth(BorderWidth::CreateMedium())
	, m_BorderRightWidth(BorderWidth::CreateMedium())
	, m_BorderTopColor(BorderColor::CreateColor(m_Color))
	, m_BorderLeftColor(BorderColor::CreateColor(m_Color))
	, m_BorderBottomColor(BorderColor::CreateColor(m_Color))
	, m_BorderRightColor(BorderColor::CreateColor(m_Color))
	, m_BorderTopStyle(BorderStyle::None)
	, m_BorderLeftStyle(BorderStyle::None)
	, m_BorderBottomStyle(BorderStyle::None)
	, m_BorderRightStyle(BorderStyle::None)
	, m_Top(Distance::CreateAuto())
	, m_Left(Distance::CreateAuto())
	, m_Bottom(Distance::CreateAuto())
	, m_Right(Distance::CreateAuto())
{
}
}