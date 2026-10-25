//step 1 include kaju engine header file 
#include <kaju.h>

//step 2 create a child class of application and override the onUpdate function 
class sandbox : public kaju::Application {
public:
	void OnUpdate() override;
};

//step 3 create a function named CreateApplication of type application pointer
// which should return a pointer to your child class 

kaju::Application* CreateApplication() {
	return new sandbox;
}
	
void sandbox::OnUpdate() {
	m_Window->OnUpdate();
}

