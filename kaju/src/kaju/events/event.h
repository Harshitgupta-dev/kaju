#pragma once
#include "../core.h"
#include "../../kpch.h"

namespace kaju {
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }
#define EVENT_CLASS_TYPE(type)  static EventType getStaticType() { return EventType::##type; }\
									 EventType getEventType() const override { return getStaticType(); }\
									 const char* getName() const override { return #type; }

	class KAJU_API Event {
	public:
		friend class EventDispatcher;

		virtual kaju::EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); };

		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() & category;
		}
		inline bool Handled() const { return m_handled; }
	protected:
		Event() {}
		bool m_handled = false;
	};

	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	private:
		Event& m_Event;
	public:
		EventDispatcher(Event& e) :m_Event(e) {}
		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.getEventType() == T::getStaticType()) {
				m_Event.m_handled = func(*(T*)&m_Event);
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}

}