#include "FuelEngine.h"
#include <iostream>

class SPRING_GAME_DEVELOPMENT_APP : public FuelEngine::FuelEngineApp
{
public:
	SPRING_GAME_DEVELOPMENT_APP()
	{
		FuelEngine::GameWindow::Init();
		FuelEngine::GameWindow::CreateWindow(800, 600, "Test Name");
	}
	virtual void OnUpdate() override
	{
		std::cout << "Game is running" << std::endl;
		
		FuelEngine::GameWindow::SwapBuffers();
		FuelEngine::GameWindow::PollEvents();
	}
};
FUELENGINE_START(SPRING_GAME_DEVELOPMENT_APP);