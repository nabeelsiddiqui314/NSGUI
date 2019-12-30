#include "Application.h"
#include "AppWindow.h"

namespace nsgui {
	Application::Application(std::uint32_t width, std::uint32_t height, const std::string& title)
	: m_window(width, height, title) {
		m_window.setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	}

	void Application::onInit() {}

	void Application::run() {
		while (m_window.run()) {}
	}

	void Application::onEvent(sf::Event& evnt) {

	}
}