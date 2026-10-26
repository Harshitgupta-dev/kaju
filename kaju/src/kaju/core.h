#pragma once
#ifdef KAJU_PLATFORM_WINDOWS
	#ifdef KAJU_BUILD_DLL
#define KAJU_API _declspec(dllexport)
	#else
#define KAJU_API _declspec(dllimport)
	#endif // KAJU_BUILD_DLL
#else
	#error windows only!
#endif //kaju_platform_windows


#ifdef KAJU_ENABLE_ASSERT
#define KAJU_ASSERT(x, ...) {if(!(x)) { kaju_error("ASSERTION FAILED : {0}" , __VA_ARGS__); __debugbreak();}}
#define KAJU_CORE_ASSERT(x, ...) {if(!(x)) { kaju_core_error("ASSERTION FAILED : {0}" , __VA_ARGS__); __debugbreak();}}
#else
#define KAJU_ASSERT(x, ...)
#define KAJU_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)