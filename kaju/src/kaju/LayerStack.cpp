#include "kpch.h"
#include "LayerStack.h"

namespace kaju {
	LayerStack::LayerStack(){
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack(){
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer){
		m_Layers.emplace(m_LayerInsert, layer);
	}
	
	void LayerStack::PopLayer(Layer* layer){
		auto l = std::find(begin(), end(), layer);
		if (l != end()) {
			m_Layers.erase(l);
			m_LayerInsert--;
		}
	}

	void LayerStack::PushOverlay(Layer* layer){
		m_Layers.emplace_back(layer);
	}

	void LayerStack::PopOverlay(Layer* layer){

		auto l = std::find(begin(), end(), layer);
		if (l != end()) {
			m_Layers.erase(l);
		}
	}

	void LayerStack::UpdateLayers() {
		for (Layer* layer : m_Layers)
			layer->OnUpdate();
	}

	void LayerStack::ManageEvent(Event& e) {
		for (auto it = end(); it != begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled()) break;
		}
	}
}