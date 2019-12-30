#pragma once

#include "NSGUI/core/EntryPoint.h"

#define NSGUI_INIT_APPLICATION(x) nsgui::Application* nsgui::createApplication() { return new x(); }

#include "NSGUI/core/Application.h"