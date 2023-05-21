#pragma once
#include "pch.h"
#include "GameWindow.h"
#include "GLFWCode/GLFWimplementation.h"

namespace FuelEngine
{
	GameWindow::GameWindow() {
#ifdef FUELENGINE_GLFW
		mImplementation = new GLFWimplementation;
#else
		#ERROR_only_GLFW_is_supported
#endif
	}

	void GameWindow::Init()
	{
		if (!mInstance) {
			mInstance = std::unique_ptr<GameWindow>(new GameWindow);
		}
	}
	std::unique_ptr<GameWindow>& GameWindow::GetWindow()
	{
		return mInstance;
	}
	void GameWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mInstance->mImplementation->CreateWindow(width, height, windowName);
	}
	void GameWindow::CreateWindow(int width, int height, std::string&& windowName)
	{
		mInstance->mImplementation->CreateWindow(width, height, std::move(windowName));
	}
	void GameWindow::SwapBuffers()
	{
		mInstance->mImplementation->SwapBuffers();
	}
	void GameWindow::PollEvents()
	{
		mInstance->mImplementation->PollEvents();
	}
	int GameWindow::getWidth()
	{
		return mInstance->mImplementation->getWidth();
	}
	int GameWindow::getHeight()
	{
		return mInstance->mImplementation->getHeight();
	}
	GameWindow::~GameWindow()
	{
		if (mImplementation != nullptr) {
			delete mImplementation;
		}
	}
	void GameWindow::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mImplementation->SetKeyPressedCallback(callbackFunc);
	}
	void GameWindow::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mImplementation->SetKeyReleasedCallback(callbackFunc);
	}
	void GameWindow::SetWindowClosedCallback(std::function<void()> callbackFunc)
	{
	}
}