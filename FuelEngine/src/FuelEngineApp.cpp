#include "pch.h"
#include "FuelEngineApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Renderer.h"
#include "Shader.h"
#include "Image.h"
#include "GameWindow.h"


namespace FuelEngine
{
	FuelEngineApp::FuelEngineApp()
	{
		GameWindow::Init();
		GameWindow::CreateWindow(800, 600, "Test Name");

		// SetWindowCloseCallback(std::bind(&FuelEngineApp::DefaultWindowCloseHandler, this));
		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler();  });

	}
	// Game Loop
	void FuelEngineApp::Run()
	{
	
		mNextFrameTime = std::chrono::steady_clock::now();

		while (!mGameWindowShouldClose)
		{

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			FuelEngine::GameWindow::SwapBuffers();
			FuelEngine::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		}
	}
	void FuelEngineApp::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);

	}
	void FuelEngineApp::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}
	void FuelEngineApp::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		GameWindow::GetWindow()->SetWindowClosedCallback(callbackFunc);
	}
	void FuelEngineApp::DefaultWindowCloseHandler()
	{
		mGameWindowShouldClose = true;
	}
}