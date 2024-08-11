#pragma once

#include "CommonTypes.h"

namespace blocki
{
enum class Direction
{
	LTR,
	RTL,
	Count
};

enum class Display
{
	Block,
	Inline,
	InlineBlock,
	ListItem,
	Table,
	InlineTable,
	None,
	Count
	// todo: additional table types
};

enum class Position
{
	Static,
	Relative,
	Absolute,
	Fixed,
	Count
};

enum class Float
{
	Left,
	Right,
	None,
	Inherit
};

enum class Overflow
{
	Visible,
	Hidden,
	None,
	Count
};

enum class BorderStyle
{
	None,
	Hidden,
	Dotted,
	Dashed,
	Solid,
	Double,
	Groove,
	Ridge,
	Inset,
	Outset,
	Inherit,
	Count
};

class Length
{
public:
	static Length CreatePx(float value);
	static Length CreatePercent(float value);
private:
	enum class Type
	{
		Px,
		Percent,
		Count
	};

	Length(Type type, float value);

	Type m_Type;
	float m_Value;
};

class Distance
{
public:
	static Distance CreateAuto();
	static Distance CreateInherit();
	static Distance CreateLength(const Length& length);
private:
	enum class Type
	{
		Length,
		Auto,
		Inherit,
		Count
	};

	Distance(Type type);
	Distance(const Length& length);

	Type m_Type;
	Length m_Legth;
};

class BorderWidth
{
public:
	static BorderWidth CreateThin();
	static BorderWidth CreateMedium();
	static BorderWidth CreateThick();
	static BorderWidth CreateLength(const Length& length);
private:
	enum class Type
	{
		Thin,
		Medium,
		Thick,
		Length,
		Count
	};

	BorderWidth(Type type);
	BorderWidth(const Length& length);

	Type m_Type;
	Length m_Legth;
};

class RGBA
{
public:
	RGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

private:
	Uint8 m_R;
	Uint8 m_G;
	Uint8 m_B;
	Uint8 m_A;
};

class Color
{
public:
	// https://www.w3.org/TR/css-color-3/#transparent
	// Fully transparent. This keyword can be considered a shorthand for transparent black, rgba(0,0,0,0), which is its computed value.
	static Color CreateTransparent();
	static Color CreateBlack();
	static Color CreateRGBA(const RGBA& rgba);
private:
	Color(const RGBA& rgba);

	RGBA m_RGBA;
};

class BorderColor
{
public:
	static BorderColor CreateInherit();
	static BorderColor CreateColor(const Color& color);

private:
	enum class Type
	{
		Color,
		Inherit,
		Count
	};

	BorderColor(Type type);
	BorderColor(const Color& color);

	Type m_Type;
	Color m_Color;
};
}