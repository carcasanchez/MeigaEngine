#include "App.h"

App::App() : window(800, 600, "Meiga")
{
}

int App::Start()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
			return *ecode;

		Update();
	}
}

void App::Update()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	window.GetGfx().ClearBuffer(c, c, 1.0f);
	window.GetGfx().DrawTestTriangle(timer.Peek(), (float)window.mouse.GetPosX()/400.0f -1, ((float)-window.mouse.GetPosY()/300.0f )+1);
	window.GetGfx().DrawTestTriangle(timer.Peek(), -(float)window.mouse.GetPosX()/400.0f -1, -((float)-window.mouse.GetPosY()/300.0f )+1);
	window.GetGfx().EndFrame();
}
