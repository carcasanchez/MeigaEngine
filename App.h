#pragma once
#include "Window.h"
#include "Timer.h"

class App
{
public: 
	App();
	int Start();

private:
	void Update();
	Window window;
	Timer timer;
};

