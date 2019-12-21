#pragma once
#include "Application.h"

extern nsgui::Application* nsgui::createApplication();

int main() {
	auto app = nsgui::createApplication();
	app->run();
	delete app;

	return 0;
}