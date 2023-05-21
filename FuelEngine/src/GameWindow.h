#pragma once
#include "pch.h"
#include "FuelEngineUtil.h"
#include "WindowImplementation.h"
#include "FuelEngineEvents.h"

namespace FuelEngine
{
	class FUELENGINE_API GameWindow
	{
	public:
		static void Init();
		static std::unique_ptr<GameWindow>& GetWindow();

		static void CreateWindow(int width, int height, const std::string& windowName); //rvalue
		static void CreateWindow(int width, int  height, std::string&& windowName); //lvalue

		static void SwapBuffers();
		static void PollEvents();

		static int getWidth();
		static int getHeight();
	

		~GameWindow();


		void SetKeyPressedCallback(std::function<void(const KeyPressed&)>callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)>callbackFunc);
		void SetWindowClosedCallback(std::function<void()> callbackFunc);


	private:
		GameWindow(); // Private so there can only be one instance
		inline static std::unique_ptr<GameWindow> mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };
	};
}