#pragma once

#include "CommonTypes.h"
#include "StylingTypes.h"

namespace blocki
{
class Node;
// A block container box either contains only block-level boxes or establishes an inline formatting context and thus contains only inline-level boxes
// Not all block container boxes are block-level boxes: non-replaced inline blocks and non-replaced table cells are block containers but not block-level boxes.
class Box
{
	enum class Type
	{
		Inline,
		Block
	};
	Node* m_Node;
	Type m_Type;
	Vector<Box> m_Children;
};

class ContainingBlock
{
	Rectangle m_Rectangle;
	Direction m_Direction;
};
}