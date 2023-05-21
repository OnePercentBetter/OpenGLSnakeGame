#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

#pragma once


namespace FuelEngine
{
	class GLFWimplementation : public WindowImplementation
	{
	private:
		GLFWwindow* mWindow{ nullptr };

		struct Callbacks
		{
			std::function<void(const KeyPressed&)>keyPressedFunc{ [](const KeyPressed&) {} };
			std::function<void(const KeyReleased&)>keyReleasedFunc{ [](const KeyReleased&) {} };
			std::function<void()> windowCloseFunc{ []() {} };
		} mCallbacks;

	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void CreateWindow(int width, int height, const std::string&& windowName) override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		virtual int getWidth() const override;
		virtual int getHeight() const override;


		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)>callbackFunc) override;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)>callbackFunc) override;
		virtual void SetWindowClosedCallback(std::function<void()> callbackFunc) override;

		virtual ~GLFWimplementation();
	};

}