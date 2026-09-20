#include <kaju.h>
#include <iostream>

class sandbox : public kaju::Application {
public:
	sandbox() {}
	~sandbox() {}
	void run() override;
};

kaju::Application* CreateApplication() {
	return new sandbox;
}

void sandbox::run() {
	std::cout << "run is called";
	while (true);
}

