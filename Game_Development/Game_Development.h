#pragma once
#pragma once

#include "FuelEngine.h"
#include <iostream>
#include <functional>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

class SPRING_GAME_DEVELOPMENT_APP : public FuelEngine::FuelEngineApp
{
public:
	SPRING_GAME_DEVELOPMENT_APP();

	virtual void OnUpdate() override;
	void MyKeyPressedFunc(const FuelEngine::KeyPressed& e);

private:
	FuelEngine::Renderer renderer;
	FuelEngine::Unit mHead;
	FuelEngine::Image Final;
	std::vector<FuelEngine::Unit> element;
	bool Ending;
	int xRand;
	int yRand;
	FuelEngine::Unit mFood;
	int i;
	std::vector<std::string> Score;
};

FUELENGINE_START(SPRING_GAME_DEVELOPMENT_APP);
