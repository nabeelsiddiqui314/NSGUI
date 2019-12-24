#pragma once
#include "Core.h"

namespace nsgui {

	class NSGUI_API Application
	{
	public:
		Application();
		virtual ~Application() {}
	public:
		virtual void onInit();
		void run();

	private:
		
	};

	Application* createApplication();
}