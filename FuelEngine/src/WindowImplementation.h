#pragma once
#include "pch.h"


namespace FuelEngine
{
	class WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) = 0;
		virtual void CreateWindow(int width, int height, const std::string&& windowName) = 0;

		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;

	};
}
