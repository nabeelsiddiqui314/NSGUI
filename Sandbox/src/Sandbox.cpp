#include <NSGUI.h>

class Sandbox : public nsgui::Application {
	void run() override {
		while (true) {}
	}
};

nsgui::Application* nsgui::createApplication() {
	return new Sandbox();
}