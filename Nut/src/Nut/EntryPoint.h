#pragma once

#ifdef NUT_PLATFORM_WINDOWS

extern Nut::Application* Nut::CreateApplication();

int main(int argc, char** argv)
{
	Nut::Log::Init();
	NUT_CORE_INFO("INIT");
	NUT_CORE_TRACE("INIT1");
	int a = 5;
	NUT_FATAL("Hello, Var={0}", a);


	auto app = Nut::CreateApplication();
	app->Run();
	delete app;
}

#endif