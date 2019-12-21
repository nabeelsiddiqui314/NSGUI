#pragma once
#include "Core.h"

namespace nsgui {

	class NSGUI_API Application
	{
	public:
		Application() = default;
		virtual ~Application() {}
	public:
		virtual void run() = 0;
	};

	Application* createApplication();
}