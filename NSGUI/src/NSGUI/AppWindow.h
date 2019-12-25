#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <functional>
#include "Core.h"

namespace nsgui {

	class NSGUI_API AppWindow
	{
	public:
		typedef std::function<void(sf::Event&)> EventCallback;
	public:
		AppWindow(std::uint32_t width, std::uint32_t height, const std::string& title);
		~AppWindow() = default;
	public:
		void setEventCallback(const EventCallback& evntCallback);
		bool run();
	private:
		sf::RenderWindow m_window;
		EventCallback m_eventCallback;
	};

}