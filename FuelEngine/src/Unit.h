#pragma once
#include "FuelEngineUtil.h"
#include "Image.h"
#include "RendererTypes.h"

namespace FuelEngine
{
	class FUELENGINE_API Unit
	{
	public:
		Unit(const std::string & imag, ScreenCoord coords);
		Unit(std::string&& image, ScreenCoord coords);

		int GetWidth() const;
		int GetHeight() const;

		ScreenCoord GetCoords() const;
		void SetCoords(ScreenCoord newCoords);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);
	private:
		Image mImage;
		ScreenCoord mPosition;

		friend class Renderer;
		friend FUELENGINE_API bool UnitsOverlap(const Unit& a, const Unit& b);
	};

	FUELENGINE_API bool UnitsOverlap(const Unit& a, const Unit& b);
}
