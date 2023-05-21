#pragma once
#include "FuelEngineUtil.h"
namespace FuelEngine
{
	// Three Different Types of Events
	class FUELENGINE_API KeyPressed {
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;


	private:
		int mKeyCode;
	};

	class FUELENGINE_API KeyReleased {
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;


	private:
		int mKeyCode;
	};

	class FUELENGINE_API WindowClosed
	{

	};
}
