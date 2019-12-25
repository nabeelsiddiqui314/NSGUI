#pragma once
#include "Core.h"
#include <cstdint>
#include <string>
#include "AppWindow.h"

namespace nsgui {

	class NSGUI_API Application
	{
	public:
		Application(std::uint32_t width, std::uint32_t height, const std::string& title);
		virtual ~Application() {}
	public:
		virtual void onInit();
		void run();
	private:
		void onEvent(sf::Event& evnt);
	private:
		AppWindow m_window;
	};

	Application* createApplication();
}