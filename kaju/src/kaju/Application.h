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

        void PushLayer(Layer* layer) { m_LayerStack.PushLayer(layer); }
        void PushOverlay(Layer* layer) { m_LayerStack.PushOverlay(layer); }

    protected:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };
}