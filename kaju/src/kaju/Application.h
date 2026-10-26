#pragma once
#include "core.h"
#include "window.h"
#include "events/event.h"
#include "events/Application-event.h"
#include "Layer.h"
#include "LayerStack.h"

namespace kaju
{
    class KAJU_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
        void virtual OnUpdate() = 0;
        void OnEvent(Event& e);

        void PushLayer(Layer* layer) { m_LayerStack.PushLayer(layer); layer->OnAttach(); }
        void PushOverlay(Layer* layer) { m_LayerStack.PushOverlay(layer); layer->OnAttach(); }
        
        inline Window& GetWindow() { return *m_Window; }
        inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        static Application* s_Instance;
    };
}