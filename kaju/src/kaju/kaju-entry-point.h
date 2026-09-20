#pragma once

#include <iostream>
#include "Application.h"

#ifdef KAJU_PLATFORM_WINDOWS

extern kaju::Application* CreateApplication();
int main() {
	std::cout << "we are in the main\n";
	auto app = CreateApplication();
	app->run();
	delete app;
}

#else
#error windows only!
#endif //kaju_platform_windows
