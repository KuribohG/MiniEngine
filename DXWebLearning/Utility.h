#pragma once

#include <cassert>

#ifdef _DEBUG

#define ASSERT(x, ...) assert(x);
#define ASSERT_SUCCEEDED(hr, ...) \
	if (FAILED(hr)) \
	{ \
		printf(__VA_ARGS__); \
		__debugbreak(); \
	}

#else

#define ASSERT(x, ...) (void)(x);
#define ASSERT_SUCCEEDED(hr, ...) (void)(hr);

#endif