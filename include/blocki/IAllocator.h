#pragma once

#include "blocki/Config.h"

namespace blocki
{
class BLOCKI_API IAllocator
{
public:
	IAllocator();
	virtual ~IAllocator();

	virtual void* Allocate(unsigned size) = 0;
	virtual void* AlignedAllocate(unsigned size, unsigned alignment) = 0;
	virtual void Deallocate(void* ptr) = 0;
	virtual void AlignedDeallocate(void* ptr) = 0;
};
}