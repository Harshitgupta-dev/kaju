#pragma once
#include "../Layer.h"
#include "../core.h"
#include "../events/Application-event.h"
#include "../events/mouse-event.h"

//
//WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
//AppTick, AppUpdate, AppRender,
//KeyPressed, KeyReleased,
//MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled

namespace kaju {

	class KAJU_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();


		void  OnUpdate() override;
		void  OnEvent(kaju::Event& event) override;
		void  OnAttach() override;
		void  OnDetach() override;

		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);

		bool OnWindowCloseEvent(WindowCloseEvent& event);
		bool OnWindowResizeEvent(WindowResizeEvent& event);

	private:
		float m_Time = 0.0f;

	};

}