#pragma once

#include <iostream>

#ifdef KAJU_PLATFORM_WINDOWS

extern kaju::Application* CreateApplication();

int main() {
	kaju::Log::init();
	auto APP = CreateApplication();
	APP->Run();
	delete APP;
}

#else
#error windows only!
#endif //kaju_platform_windows
