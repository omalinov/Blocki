#include "blocki/IAllocator.h"

namespace blocki
{
// Implementing the constructors and destructors of these members here
// blocks them from being inlined in clients code, which might break
// virtual tables on some compilers.

IAllocator::IAllocator()
{
}

IAllocator::~IAllocator()
{
}
}