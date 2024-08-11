#pragma once

#include "StylingTypes.h"
#include "Viewport.h"

namespace blocki
{
class Node;

void CalculateLayout(Node* root, Viewport viewport, Direction direction);
}