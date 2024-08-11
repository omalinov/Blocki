#include "Viewport.h"

namespace blocki
{
Viewport::Viewport(float width, float height)
	: m_Size(width, height)
{
}

float Viewport::GetWidth() const
{
	return m_Size.GetX();
}

float Viewport::GetHeight() const
{
	return m_Size.GetY();
}
}