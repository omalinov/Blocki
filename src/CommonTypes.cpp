#include "CommonTypes.h"
#include "BlockiAssert.h"

namespace blocki
{
VectorFloat2::VectorFloat2(float x, float y)
	: m_X(x)
	, m_Y(y)
{
}

float VectorFloat2::GetX() const
{
	return m_X;
}

float VectorFloat2::GetY() const
{
	return m_Y;
}

float& VectorFloat2::ModifyX()
{
	return m_X;
}

float& VectorFloat2::ModifyY()
{
	return m_Y;
}

Rectangle Rectangle::Create(float top, float left, float bottom, float right)
{
	BLOCKI_ASSERT(left <= right, "Rectangle left must be before right");
	BLOCKI_ASSERT(top <= bottom, "Rectangle top must be before bottom");
	return Rectangle(top, left, bottom, right);
}

Rectangle::Rectangle(float top, float left, float bottom, float right)
	: m_Top(top)
	, m_Left(left)
	, m_Bottom(bottom)
	, m_Right(right)
{
}

float Rectangle::GetTop() const
{
	return m_Top;
}

float Rectangle::GetLeft() const
{
	return m_Left;
}

float Rectangle::GetBottom() const
{
	return m_Bottom;
}

float Rectangle::GetRight() const
{
	return m_Right;
}

float& Rectangle::ModifyTop()
{
	return m_Top;
}

float& Rectangle::ModifyLeft()
{
	return m_Left;
}

float& Rectangle::ModifyBottom()
{
	return m_Bottom;
}

float& Rectangle::ModifyRight()
{
	return m_Right;
}
}