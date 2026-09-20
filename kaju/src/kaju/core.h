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
