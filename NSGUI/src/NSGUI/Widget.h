#pragma once
#include "Core.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

namespace nsgui {

	class NSGUI_API Widget
	{
	public:
		Widget() = default;
		virtual ~Widget() {}
	public:
		void setPosition(const sf::Vector2f& pos);
		const sf::Vector2f& getPosition() const;
		const sf::Vector2f getAbsolutePosition() const;

		void setSize(const sf::Vector2f& size);
		const sf::Vector2f& getSize() const;

		void onEvent(const sf::Event& evnt);
	protected:
		virtual void onMouseMove(int x, int y) {}
		virtual void onMouseClick(int x, int y, const sf::Mouse::Button& button) {}
		virtual void onMouseRelease(int x, int y, const sf::Mouse::Button& button) {}
		virtual void onKeyPress(const sf::Event::KeyEvent& key) {}
		virtual void onKeyRelease(const sf::Event::KeyEvent& key) {}
		virtual void onMouseEnter(int x, int y) {}
		virtual void onMouseLeave(int x, int y) {}
		virtual void onTextEnter(const sf::Event::TextEvent& text) {}
	private:
		sf::Vector2f m_position;
		sf::Vector2f m_size;

		bool m_didContainCursor = false;
	};

}