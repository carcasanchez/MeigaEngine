#pragma once
#include "Window.h"
#include "Timer.h"
#include "ImGuiManager.h"

class App
{
public: 
	App();
	~App();
	int Start();
private:
	void Update();

	ImGuiManager imGuiManager;
	Window window;
	Timer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
};

