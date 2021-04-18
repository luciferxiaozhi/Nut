#pragma once

#include "Core.h"

namespace Nut {

	class NUT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// To be defined by CLIENT
	Application* CreateApplication();
}

