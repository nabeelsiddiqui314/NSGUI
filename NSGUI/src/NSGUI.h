#pragma once

#include "NSGUI/EntryPoint.h"

#define NSGUI_INIT_APPLICATION(x) nsgui::Application* nsgui::createApplication() { return new x(); }

#include "NSGUI/Application.h"