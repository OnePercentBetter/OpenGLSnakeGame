#include "FuelEngineApp.h"
#include <iostream>

namespace FuelEngine
{
	// Game Loop
	void FuelEngineApp::Run()
	{
		while (true)
		{
			OnUpdate();

		}
	}
}