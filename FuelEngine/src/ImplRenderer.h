#pragma once
#include "Shader.h"
#include "RendererTypes.h"
#include "Image.h"

namespace FuelEngine
{
	class ImplRenderer
	{
	public:
		virtual void Draw(Image& image,
			TextureBox texCoords,
			Shader& shader,
			ScreenCoord Coords) = 0;
		virtual void Clear() = 0;
	};
}