#include "StylingTypes.h"
#include "BlockiAssert.h"

namespace blocki
{
Length Length::CreatePx(float value)
{
	return Length(Type::Px, value);
}

Length Length::CreatePercent(float value)
{
	return Length(Type::Percent, value);
}

Length::Length(Type type, float value)
	: m_Type(type)
	, m_Value(value)
{
	BLOCKI_ASSERT(type != Type::Count, "Invalid lengthtype");
}

Distance Distance::CreateAuto()
{
	return Distance(Type::Auto);
}

Distance Distance::CreateInherit()
{
	return Distance(Type::Inherit);
}

Distance Distance::CreateLength(const Length& length)
{
	return Distance(length);
}

Distance::Distance(Type type)
	: m_Type(type)
	, m_Legth(Length::CreatePx(0))
{
	BLOCKI_ASSERT(type != Type::Length && type != Type::Count, "Invalid Distance type");
}

Distance::Distance(const Length& length)
	: m_Type(Type::Length)
	, m_Legth(length)
{
}

BorderWidth BorderWidth::CreateThin()
{
	return BorderWidth(Type::Thin);
}

BorderWidth BorderWidth::CreateMedium()
{
	return BorderWidth(Type::Medium);
}

BorderWidth BorderWidth::CreateThick()
{
	return BorderWidth(Type::Thick);
}

BorderWidth BorderWidth::CreateLength(const Length& length)
{
	return BorderWidth(length);
}

BorderWidth::BorderWidth(Type type)
	: m_Type(type)
	, m_Legth(Length::CreatePx(0))
{
	BLOCKI_ASSERT(type != Type::Length && type != Type::Count, "Invalid border width type");
}

BorderWidth::BorderWidth(const Length& length)
	: m_Type(Type::Length)
	, m_Legth(length)
{
}

RGBA::RGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	: m_R(r)
	, m_G(g)
	, m_B(b)
	, m_A(a)
{
}

Color Color::CreateTransparent()
{
	return Color(RGBA(0, 0, 0, 0));
}

Color Color::CreateBlack()
{
	return Color(RGBA(0, 0, 0, 255));
}

Color Color::CreateRGBA(const RGBA& rgba)
{
	return Color(rgba);
}

Color::Color(const RGBA& rgba)
	: m_RGBA(rgba)
{
}

BorderColor BorderColor::CreateInherit()
{
	return BorderColor(Type::Inherit);
}

BorderColor BorderColor::CreateColor(const Color& color)
{
	return BorderColor(color);
}

BorderColor::BorderColor(Type type)
	: m_Type(type)
	, m_Color(Color::CreateTransparent())
{
	BLOCKI_ASSERT(type != Type::Count, "Invalid border color type");
}

BorderColor::BorderColor(const Color& color)
	: m_Type(Type::Color)
	, m_Color(color)
{
}
}