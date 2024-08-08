#include "BlockiNode.h"
#include <cassert>

int main()
{
	blocki::BlockiNode aNode;
	blocki::BlockiNodeInput& input = aNode.ModifyInput();
	input.ModifyBorder().ModifyRight() = 35.f;
	assert(aNode.GetInput	().GetBorder().GetRight() == 35.f);
	return 0;
}