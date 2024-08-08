#include "CommonTypes.h"
#include "BlockiNodeInput.h"
#include "BlockiNodeResult.h"

namespace blocki
{
class BlockiNode
{
public:
	BlockiNodeInput& ModifyInput();
	const BlockiNodeInput& GetInput() const;

	void AppendChild(BlockinUniquePtr<BlockiNode>&& child);
private:
	BlockiNodeInput m_Input;
	BlockiNodeResult m_Result;
	BlockiVector<BlockinUniquePtr<BlockiNode>> m_Children;
};

void CalculateLayout(BlockiNode* root, float width, float height, BlockiDirection direction);
}