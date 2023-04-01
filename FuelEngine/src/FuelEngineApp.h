#pragma once

#include "FuelEngineUtil.h"

namespace FuelEngine
{
	class FUELENGINE_API FuelEngineApp
	{
	public:
		virtual void OnUpdate() = 0;

		void Run();


	private:



	};
}

