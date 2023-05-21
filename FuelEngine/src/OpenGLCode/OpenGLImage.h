#pragma once

#include "pch.h"
#include "../ImplImage.h"

namespace FuelEngine
{
	class OpenGLImage : public ImplImage {
	public:
		OpenGLImage(const std::string& imageFile);
		OpenGLImage(std::string&& imagefile);

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		virtual void Activate() override;

		~OpenGLImage();
	private:
		int mWidth{ 0 };
		int mHeight{ 0 };
		unsigned int mImage{ 0 };


	};
}
