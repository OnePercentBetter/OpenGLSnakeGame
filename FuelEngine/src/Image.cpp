#include "pch.h"
#include "Image.h"
#include "OpenGLCode/OpenGLImage.h"

namespace FuelEngine
{
	Image::Image(const std::string& imageFile) {
#ifdef FUELENGINE_OPENGL
		mImplementation = std::unique_ptr<ImplImage>{ new OpenGLImage{imageFile} };
#else
		#OpenGL_Available
#endif
	}

	Image::Image(std::string&& imageFile) {
#ifdef FUELENGINE_OPENGL
		mImplementation = std::unique_ptr<ImplImage>{ new OpenGLImage{imageFile} };
#else
		#OpenGL_Available
#endif
	}
	int Image::GetHeight() const {
		return mImplementation->GetHeight();
	}
	int Image::GetWidth() const {
		return mImplementation->GetWidth();
	}
	void Image::Activate() {
		mImplementation->Activate(); 
	} 
}