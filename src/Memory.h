#pragma once

#include <new>
#include <limits>

#include "blocki/IAllocator.h"

void* BlockiMalloc(std::size_t size);
void* BlockiAlignedMalloc(std::size_t size, unsigned alignment);
void BlockiFree(void* ptr);
void BlockiAlignedFree(void* ptr);
void* operator new(std::size_t size);
void* operator new(std::size_t size, std::align_val_t align);
void operator delete(void* ptr);
void operator delete(void* ptr, std::align_val_t);
void operator delete(void* ptr, const std::nothrow_t&);
void* operator new[](std::size_t);
void* operator new[](size_t, const std::nothrow_t&) noexcept;
void operator delete[](void*);
void operator delete[](void*, const std::nothrow_t&);

namespace blocki
{
extern IAllocator* gAllocator;

template <typename T>
class BlockiStdAllocator
{
public:
	typedef T value_type;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;

public:
	template <typename U>
	struct rebind
	{
		typedef BlockiStdAllocator<U> other;
	};

public:
	BlockiStdAllocator()
	{
	}

	~BlockiStdAllocator()
	{
	}

	BlockiStdAllocator(const BlockiStdAllocator& rhs)
	{
	}

	template <typename U>
	BlockiStdAllocator(const BlockiStdAllocator<U>& rhs)
	{
	}

	T* allocate(size_type cnt)
	{
		return reinterpret_cast<T*>(BlockiMalloc(cnt * sizeof(T)));
	}

	void deallocate(T* p, size_type)
	{
		BlockiFree(p);
	}

	size_type max_size() const
	{
		return std::numeric_limits<size_type>::max() / sizeof(T);
	}

	template <class U, class... Args>
	void construct(U* p, Args&&... args)
	{
		new(const_cast<typename std::remove_cv<U>::type*>(p)) U(std::forward<Args>(args)...);
	}

	void destroy(T* p)
	{
		p->~T();
	}

	bool operator==(const BlockiStdAllocator&) const
	{
		return true;
	}

	bool operator!=(const BlockiStdAllocator& rhs) const
	{
		return !operator==(rhs);
	}
private:
	template <typename U> friend class BlockiStdAllocator;
};

template<typename T>
struct BlockiDeleter
{
	BlockiDeleter()
	{
	}

	template <typename U>
	BlockiDeleter(const BlockiDeleter<U>& rhs)
	{
		static_assert(std::is_base_of<T, U>::value, "Only inherited casting is allowed");
		static_assert(std::has_virtual_destructor<T>::value, "Type needs virtual destructor");
	}

	void operator()(T* ptr) const
	{
		if (!ptr)
		{
			return;
		}
		ptr->~T();
		operator delete(ptr);
	}
};

}