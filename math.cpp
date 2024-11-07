#include <cmath>

struct float3
{
    float x, y, z;

    float3 normalize() const
    {
        float length = std::sqrt(x * x + y * y + z * z);
        return {x / length, y / length, z / length};
    }

    float3 operator*(float scalar) const
    {
        return {x * scalar, y * scalar, z * scalar};
    }

    float3 operator+(float3 other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }
};