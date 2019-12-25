#include <NSGUI.h>

class Sandbox : public nsgui::Application {
public:
	Sandbox() : Application(800, 600, "Sandbox") {}
};

NSGUI_INIT_APPLICATION(Sandbox)