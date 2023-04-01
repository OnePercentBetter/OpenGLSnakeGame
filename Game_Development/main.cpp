#include "FuelEngine.h"
#include <iostream>

class SPRING_GAME_DEVELOPMENT_APP : public FuelEngine::FuelEngineApp
{
public:
	virtual void OnUpdate() override
	{
		std::cout << "Game is running" << std::endl;
	}
};
FUELENGINE_START(SPRING_GAME_DEVELOPMENT_APP);