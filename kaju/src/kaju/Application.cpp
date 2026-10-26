#include "kpch.h"
#include "Application.h"

namespace kaju
{
	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		KAJU_CORE_ASSERT(!s_Instance, "Application instance already exists");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		while (m_Running) {
			m_LayerStack.UpdateLayers();
			OnUpdate();
		}
	}

	void Application::OnEvent(Event& e){

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		m_LayerStack.ManageEvent(e);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
	
	
}