#pragma once
#include "Window.h"
#include "Timer.h"

class App
{
public: 
	App();
	~App();
	int Start();
private:
	void Update();
	Window window;
	Timer timer;

	std::vector<std::unique_ptr<class Box>> boxes;
};

