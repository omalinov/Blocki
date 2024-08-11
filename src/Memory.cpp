#include "Memory.h"
#include "BlockiAssert.h"

namespace blocki
{
IAllocator* gAllocator = nullptr;
}

void* BlockiMalloc(std::size_t size)
{
	return blocki::gAllocator->Allocate(static_cast<unsigned>(size));
}

void* BlockiAlignedMalloc(std::size_t size, unsigned alignment)
{
	return blocki::gAllocator->AlignedAllocate(static_cast<unsigned>(size), alignment);
}

void BlockiFree(void* ptr)
{
	blocki::gAllocator->Deallocate(ptr);
}

void BlockiAlignedFree(void* ptr)
{
	blocki::gAllocator->AlignedDeallocate(ptr);
}

void* operator new(size_t size)
{
	return BlockiMalloc(size);
}

void* operator new(size_t size, std::align_val_t align)
{
	return BlockiAlignedMalloc(size, static_cast<unsigned>(align));
}

void operator delete(void* ptr)
{
	BlockiFree(ptr);
}

void operator delete(void* ptr, std::align_val_t)
{
	BlockiAlignedFree(ptr);
}

void operator delete(void* ptr, const std::nothrow_t&)
{
	BlockiFree(ptr);
}

void* operator new[](std::size_t)
{
	BLOCKI_ASSERT(false, "Don't use this operator - use the provided macros instead!");
	return nullptr;
}

void* operator new[](size_t, const std::nothrow_t&) noexcept
{
	BLOCKI_ASSERT(false, "Don't use this operator - use the provided macros instead!");
	return nullptr;
}

void operator delete[](void*)
{
	BLOCKI_ASSERT(false, "Don't use this operator - use the provided macros instead!");
}

void operator delete[](void*, const std::nothrow_t&)
{
	BLOCKI_ASSERT(false, "Don't use this operator - use the provided macros instead!");
}