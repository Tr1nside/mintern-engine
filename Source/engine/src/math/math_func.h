#pragma once

#include <numbers>

namespace mintern {
namespace math {
inline float toRadians(float degrees) {
    return degrees * (std::numbers::pi / 180.0f);
}
}  // namespace math
}  // namespace mintern