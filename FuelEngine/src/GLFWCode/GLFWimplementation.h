#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

#pragma once


namespace FuelEngine
{
	class GLFWimplementation : public WindowImplementation
	{
	private:
		GLFWwindow* mWindow{ nullptr };

	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void CreateWindow(int width, int height, const std::string&& windowName) override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		virtual int getWidth() const override;
		virtual int getHeight() const override;

	};

}