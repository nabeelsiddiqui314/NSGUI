#pragma once

#ifdef NS_BUILD_DLL
	#define NSGUI_API _declspec(dllexport)
#else
	#define NSGUI_API _declspec(dllimport)
#endif