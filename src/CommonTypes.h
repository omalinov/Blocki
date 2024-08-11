#pragma once

#include <vector>
#include <memory>
#include <cstdint>
#include <string>
#include <string_view>

#include "Memory.h"

namespace blocki
{
using Uint8 = std::uint8_t;

template <typename T, typename Allocator = BlockiStdAllocator<T>>
using Vector = std::vector<T, Allocator>;

template <typename T>
using UniquePtr = std::unique_ptr<T, BlockiDeleter<T>>;

template<class T, class... Args>
inline UniquePtr<T> MakeUnique(Args&&... args)
{
	return UniquePtr<T>(new (BlockiMalloc(sizeof(T))) T(std::forward<Args>(args)...));
}

template <typename T, typename Traits = std::char_traits<T>, typename Allocator = BlockiStdAllocator<T>>
using BasicString = std::basic_string<T, Traits, Allocator>;

template <typename T, typename Traits = std::char_traits<T>>
using BasicStringView = std::basic_string_view<T, Traits>;

using String = BasicString<char>;
using StringView = BasicStringView<char>;

class VectorFloat2
{
public:
	VectorFloat2(float x, float y);

	float GetX() const;
	float GetY() const;

	float& ModifyX();
	float& ModifyY();
private:
	float m_X;
	float m_Y;
};

class Rectangle
{
public:
	static Rectangle Create(float top, float left, float bottom, float right);

	Rectangle() = delete;

	float GetTop() const;
	float GetLeft() const;
	float GetBottom() const;
	float GetRight() const;

	float& ModifyTop();
	float& ModifyLeft();
	float& ModifyBottom();
	float& ModifyRight();
private:
	Rectangle(float top, float left, float bottom, float right);

	float m_Top;
	float m_Left;
	float m_Bottom;
	float m_Right;
};
}