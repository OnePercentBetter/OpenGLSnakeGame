#pragma once
#include "pch.h"
#include "FuelEngineUtil.h"
#include "FuelEngineEvents.h"

constexpr int FPS{ 60 };

namespace FuelEngine
{
	class FUELENGINE_API FuelEngineApp
	{
	public:
		FuelEngineApp();
		virtual void OnUpdate() = 0;

		void Run();
		
		//Callback Function launched in response to event
		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);
		void DefaultWindowCloseHandler();
	private:
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;


		bool mGameWindowShouldClose{ false };
	};
}

