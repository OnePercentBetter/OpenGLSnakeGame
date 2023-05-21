#include "pch.h"
#include "OpenGLImage.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "FuelEngineUtil.h"

namespace FuelEngine
{
	OpenGLImage::OpenGLImage(const std::string& imageFile) {
		glGenTextures(1, &mImage);
		glBindTexture(GL_TEXTURE_2D, mImage);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		//Declare Channels
		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(imageFile.c_str(), &mWidth, &mHeight, &nrChannels, 0);
		if (data == nullptr)
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}
	OpenGLImage::OpenGLImage(std::string&& imageFile) {
		glGenTextures(1, &mImage);
		glBindTexture(GL_TEXTURE_2D, mImage);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//Declare Channels
		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(imageFile.c_str(), &mWidth, &mHeight, &nrChannels, 0);
		if (data == nullptr)
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}
	void OpenGLImage::Activate() {
		glBindTexture(GL_TEXTURE_2D, mImage);
	} 
	OpenGLImage::~OpenGLImage() {
		glDeleteTextures(1, &mImage);
	}
	int OpenGLImage::GetWidth() const {
		return mWidth;
	}
	int OpenGLImage::GetHeight() const {
		return mHeight;
	}
}
