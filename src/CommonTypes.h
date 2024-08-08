#include <vector>
#include <memory>

namespace blocki
{
template <typename T, typename Allocator = std::allocator<T>>
using BlockiVector = std::vector<T, Allocator>;

template <typename T>
using BlockinUniquePtr = std::unique_ptr<T>;
}