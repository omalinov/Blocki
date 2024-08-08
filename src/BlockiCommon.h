#include <cassert>

#define BLOCKI_ASSERT(condition, message) assert(condition && message)

namespace blocki
{
bool FloatClose(float lhs, float rhs);
}