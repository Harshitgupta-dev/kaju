#pragma once
#include "kaju/core.h"
#include "event.h"
namespace kaju {

	class KAJU_API KeyEvent : public kaju::Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

		inline int getKeyCode() { return m_keyCode; }
	protected:
		KeyEvent(int code) : m_keyCode(code) {}
		int m_keyCode;
	};

	class KAJU_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int code, int repeat):KeyEvent(code) , m_repeatCount(repeat){}
		inline int GetRepeatCount() const { return m_repeatCount; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_repeatCount;
	};

	class KAJU_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int code) :KeyEvent(code){}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode ;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)

	};
};

