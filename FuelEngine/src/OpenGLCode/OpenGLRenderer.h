#pragma once
#include "ImplRenderer.h"
#include "Image.h"
#include "Shader.h"

namespace FuelEngine
{
	class OpenGLRenderer : public ImplRenderer
	{
	public:
		OpenGLRenderer();

		virtual void Draw(Image& image,
			TextureBox texCoords,
			Shader& shader,
			ScreenCoord Coords) override;

		virtual void Clear() override;

	private:
		unsigned int mVBO, mVAO, mEBO;



	};
}
