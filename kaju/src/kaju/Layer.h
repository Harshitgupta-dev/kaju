#pragma once
#include "core.h"
#include "events/event.h"

namespace kaju {

	class KAJU_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnUpdate() {} 
		virtual void OnEvent(kaju::Event& event) {}
		virtual void OnAttach() {}
		virtual void OnDetach() {}

		inline const std::string GetName() { return m_DebugName; }
	private:
		std::string m_DebugName;
	};
}
