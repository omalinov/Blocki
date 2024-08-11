#include "LayoutAlgorithm.h"

namespace blocki
{
namespace
{
bool DoesDisplayImplyBlockLevelElement(Display display)
{
	return display == Display::Block || display == Display::ListItem || display == Display::Table;
}

bool DoesDisplayImplyInlineLevelElement(Display display)
{
	return display == Display::Inline || display == Display::InlineBlock || display == Display::InlineTable;
}
}

void CalculateLayout(Node* root, Viewport viewport, Direction direction)
{

}
}