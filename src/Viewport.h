#pragma once
#include "CommonTypes.h"

namespace blocki
{
class Viewport
{
	Viewport(float width, float height);

	float GetWidth() const;
	float GetHeight() const;
private:
	VectorFloat2 m_Size;
};
}