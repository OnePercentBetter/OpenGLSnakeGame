#include "pch.h"
#include "FuelEngineApp.h"


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