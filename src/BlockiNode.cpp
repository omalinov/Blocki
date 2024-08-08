#include "BlockiNode.h"

namespace blocki
{
BlockiNodeInput& BlockiNode::ModifyInput()
{
	return m_Input;
}

const BlockiNodeInput& BlockiNode::GetInput() const
{
	return m_Input;
}

void BlockiNode::AppendChild(BlockinUniquePtr<BlockiNode>&& child)
{
	m_Children.push_back(std::move(child));
}
}