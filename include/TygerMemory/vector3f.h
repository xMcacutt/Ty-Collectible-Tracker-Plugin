#pragma once
#ifdef TYGERMEM_EXPORTS
#define TYGERMEM __declspec(dllexport)
#else
#define TYGERMEM __declspec(dllimport)
#endif

#include <cstddef>  // For std::size_t
#include <cstring>  // For memcpy
#include <cmath>    // For sqrt

class TYGERMEM Vector3f {
public:
	float x, y, z;

	Vector3f(float x = 0.0f, float y = 0.0f, float z = 0.0f);

	operator const void* () const;

	float distance_to(const Vector3f& other) const;

	std::size_t toBytes(unsigned char* buffer) const;

	static Vector3f fromBytes(const unsigned char* buffer);
};
