#include "kpch.h"
#include "ImGuiLayer.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include "../Application.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace kaju {

#define DISPATCH_EVENT_FN(x) dispatcher.Dispatch<x>(BIND_EVENT_FN(ImGuiLayer::On##x))

	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}
	ImGuiLayer::~ImGuiLayer(){}


	void ImGuiLayer::OnUpdate() {
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(static_cast<float>(app.GetWindow().GetWidth()), static_cast<float>(app.GetWindow().GetHeight()));

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	}

	void ImGuiLayer::OnAttach() {
		kaju_core_info("ImGuiLayer attached");
		auto context = ImGui::CreateContext();
		KAJU_CORE_ASSERT(context, "Unable to create ImGui context");
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= (ImGuiBackendFlags_HasMouseCursors | ImGuiBackendFlags_HasSetMousePos);
		ImGui_ImplOpenGL3_Init("#version 410");
		
	}
	void ImGuiLayer::OnDetach() {}

	void ImGuiLayer::OnEvent(kaju::Event& event) {
		std::cout << event << std::endl;
		EventDispatcher dispatcher(event);
		DISPATCH_EVENT_FN(MouseButtonPressedEvent);
		DISPATCH_EVENT_FN(MouseButtonReleasedEvent);
		DISPATCH_EVENT_FN(MouseMovedEvent);
		DISPATCH_EVENT_FN(MouseScrolledEvent);
		DISPATCH_EVENT_FN(WindowCloseEvent);
		DISPATCH_EVENT_FN(WindowResizeEvent);
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& event) {
		ImGui::GetIO().MouseDown[event.GetMouseButton()] = true;
		return false;
	}
	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event){
		ImGui::GetIO().MouseDown[event.GetMouseButton()] = false;
		return false;
	}
	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& event){
		ImGui::GetIO().MousePos = ImVec2(event.GetX(), event.GetY());
		return false;
	}
	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& event){
		ImGui::GetIO().MouseWheelH += event.GetXOffset();
		ImGui::GetIO().MouseWheel += event.GetYOffset();
		return false;
	}

	bool ImGuiLayer::OnWindowCloseEvent(WindowCloseEvent& event) { return false; }
	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& event) { return false; }
  
}