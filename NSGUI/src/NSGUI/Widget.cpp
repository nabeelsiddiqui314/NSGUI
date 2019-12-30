#include "Widget.h"
#include <SFML/Graphics/Rect.hpp>

namespace nsgui {
	Widget::Widget(Widget* parent) : m_parent(parent) {}

	Widget::~Widget() {
		discardChildren();
	}

	void Widget::setPosition(const sf::Vector2f& pos) {
		m_position = pos;
	}

	const sf::Vector2f& Widget::getPosition() const {
		return m_position;
	}

	const sf::Vector2f Widget::getAbsolutePosition() const {
		if(!m_parent)
			return m_position;

		auto& parentPos = m_parent->getPosition();
		sf::Vector2f position = {getPosition().x + parentPos.x, getPosition().y + parentPos.y };

		return position;
	}

	void Widget::setSize(const sf::Vector2f& size) {
		m_size = size;
	}

	const sf::Vector2f& Widget::getSize() const {
		return m_size;
	}

	void Widget::onEvent(const sf::Event& evnt) {
		switch (evnt.type) {
		case sf::Event::MouseMoved:
			onMouseMove(evnt.mouseMove.x, evnt.mouseMove.y);
			
			if (sf::FloatRect(getAbsolutePosition(), getSize()).contains(evnt.mouseMove.x, evnt.mouseMove.y)) {
				if (!m_didContainCursor) {
					m_didContainCursor = true;
					onMouseEnter(evnt.mouseMove.x, evnt.mouseMove.y);
				}
			}
			else if (m_didContainCursor) {
				m_didContainCursor = false;
				onMouseLeave(evnt.mouseMove.x, evnt.mouseMove.y);
			}

			break;
		case sf::Event::MouseButtonPressed:
			onMouseClick(evnt.mouseButton.x, evnt.mouseButton.y, evnt.mouseButton.button);
			break;
		case sf::Event::MouseButtonReleased:
			onMouseRelease(evnt.mouseButton.x, evnt.mouseButton.y, evnt.mouseButton.button);
			break;
		case sf::Event::KeyPressed:
			onKeyPress(evnt.key);
			break;
		case sf::Event::KeyReleased:
			onKeyRelease(evnt.key);
			break;
		case sf::Event::TextEntered:
			onTextEnter(evnt.text);
			break;
		}
	}

	void Widget::addChild(Widget* child) {
		auto iter = std::find(m_children.begin(), m_children.end(), child);

		if (iter != m_children.end() && onAdd(child)) {
			m_children.emplace_back(child);
		}
	}

	void Widget::discardChild(Widget* child) {
		auto iter = std::find(m_children.begin(), m_children.end(), child);

		if (iter != m_children.end()) {
			delete *iter;
			m_children.erase(iter);
		}
	}

	void Widget::discardChildren() {
		for (auto iter = m_children.begin(); iter != m_children.end(); iter++) {
			delete *iter;
			iter = m_children.erase(iter);
		}
	}

}