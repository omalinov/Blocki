#include "BlockiNodeInput.h"
#include "BlockiCommon.h"

namespace blocki
{
BlockiLength BlockiLength::CreateAuto()
{
	return BlockiLength(Type::Auto, 0.f);
}

BlockiLength BlockiLength::CreatePx(float value)
{
	return BlockiLength(Type::Px, value);
}

BlockiLength BlockiLength::CreatePercent(float value)
{
	return BlockiLength(Type::Percent, value);
}

BlockiLength::BlockiLength(Type type, float value)
	: m_Type(type)
	, m_Value(value)
{
}

BlockiOffsetBox BlockiOffsetBox::Create(float top, float left, float bottom, float right)
{
	return BlockiOffsetBox(top, left, bottom, right);
}

BlockiOffsetBox::BlockiOffsetBox(float top, float left, float bottom, float right)
	: m_Top(top)
	, m_Left(left)
	, m_Bottom(bottom)
	, m_Right(right)
{
}

float BlockiOffsetBox::GetTop() const
{
	return m_Top;
}

float BlockiOffsetBox::GetLeft() const
{
	return m_Left;
}

float BlockiOffsetBox::GetBottom() const
{
	return m_Bottom;
}

float BlockiOffsetBox::GetRight() const
{
	return m_Right;
}

float& BlockiOffsetBox::ModifyTop()
{
	return m_Top;
}

float& BlockiOffsetBox::ModifyLeft()
{
	return m_Left;
}

float& BlockiOffsetBox::ModifyBottom()
{
	return m_Bottom;
}

float& BlockiOffsetBox::ModifyRight()
{
	return m_Right;
}

BlockiNodeInput::BlockiNodeInput()
	: m_Margin(BlockiOffsetBox::Create(0.f, 0.f, 0.f, 0.f))
	, m_Border(BlockiOffsetBox::Create(0.f, 0.f, 0.f, 0.f))
	, m_Padding(BlockiOffsetBox::Create(0.f, 0.f, 0.f, 0.f))
	, m_Content(BlockiOffsetBox::Create(0.f, 0.f, 0.f, 0.f))
	, m_Top(BlockiLength::CreateAuto())
	, m_Left(BlockiLength::CreateAuto())
	, m_Bottom(BlockiLength::CreateAuto())
	, m_Right(BlockiLength::CreateAuto())
{
}

const BlockiOffsetBox& BlockiNodeInput::GetMargin() const
{
	return m_Margin;
}

const BlockiOffsetBox& BlockiNodeInput::GetBorder() const
{
	return m_Border;
}

const BlockiOffsetBox& BlockiNodeInput::GetPadding() const
{
	return m_Padding;
}

const BlockiOffsetBox& BlockiNodeInput::GetContent() const
{
	return m_Content;
}

BlockiOffsetBox& BlockiNodeInput::ModifyMargin()
{
	return m_Margin;
}

BlockiOffsetBox& BlockiNodeInput::ModifyBorder()
{
	return m_Border;
}

BlockiOffsetBox& BlockiNodeInput::ModifyPadding()
{
	return m_Padding;
}

BlockiOffsetBox& BlockiNodeInput::ModifyContent()
{
	return m_Content;
}
}