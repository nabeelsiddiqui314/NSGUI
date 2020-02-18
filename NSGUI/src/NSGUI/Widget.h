#pragma once
#include "core/Core.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

namespace nsgui {

	class NSGUI_API Widget
	{
	public:
		Widget(Widget* parent);
		virtual ~Widget();
	public:
		void setPosition(const sf::Vector2f& pos);
		const sf::Vector2f& getPosition() const;
		const sf::Vector2f getAbsolutePosition() const;

		void setSize(const sf::Vector2f& size);
		const sf::Vector2f& getSize() const;
		
		virtual void processEvents(const sf::Event& evnt);
	protected:
		void addChild(Widget* child);
		void discardChild(Widget* child);
		void discardChildren();

		virtual bool onAdd(Widget* child) { return true; }

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

		Widget* m_parent;
		std::vector<Widget*> m_children;

		bool m_didContainCursor = false;
	};

}