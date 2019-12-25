#include "AppWindow.h"

namespace nsgui {

	AppWindow::AppWindow(std::uint32_t width, std::uint32_t height, const std::string& title) {
		m_window.create(sf::VideoMode(width, height), title);
	}

	void AppWindow::setEventCallback(const EventCallback& evntCallback) {
		m_eventCallback = evntCallback;
	}

	bool AppWindow::run() {
		sf::Event evnt;
		while (m_window.pollEvent(evnt)) {
			m_eventCallback(evnt);

			if (evnt.type == sf::Event::Closed) {
				m_window.close();
			}
		}

		m_window.clear();

		m_window.display();

		return m_window.isOpen();
	}

}