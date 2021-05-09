#include "App.h"
#include "Sheet.h"
#include "Box.h"
#include "SkinnedBox.h"
#include <random>
#include "Surface.h"
#include"GDIPlusManager.h"

GDIPlusManager gdiManager;

App::App() : window(800, 600, "Meiga")
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<float> adist(0.0f, 3.1415f * 2.0f);
	std::uniform_real_distribution<float> ddist(0.0f, 3.1415f * 2.0f);
	std::uniform_real_distribution<float> odist(0.0f, 3.1415f * 0.3f);
	std::uniform_real_distribution<float> rdist(6.0f, 20.0f);


	for (auto i = 0; i < 80; i++)
	{
		drawables.push_back(std::make_unique<SkinnedBox>(
			window.GetGfx(), rng, adist,
			ddist, odist, rdist));
	}
	window.GetGfx().SetProjection(DirectX::XMMatrixPerspectiveLH(1.0f, 3.0f / 4.0f, 0.5f, 40.0f));



}

App::~App()
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
	auto dt = timer.Mark();

	window.GetGfx().ClearBuffer(0.07f, 0, 0.12f);

	for (auto& b : drawables)
	{
		b->Update(dt);
		b->Draw(window.GetGfx());
	}

	window.GetGfx().EndFrame();
}
