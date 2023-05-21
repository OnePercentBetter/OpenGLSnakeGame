#include "pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"

namespace FuelEngine
{
	OpenGLShader::OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile)
	{

		std::string vShader;
		std::ifstream ifile{ vertexFile };
		std::string Line;
		while (std::getline(ifile, Line))
		{
			vShader += Line;
			vShader += "\n";
		}
		ifile.close();
		const char* cVShader = vShader.c_str();
		// Create Shader Program
		// We first create individual shader objects
		// Then we create a shader program to link all shaders
		unsigned int vertex;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &cVShader, NULL);
		glCompileShader(vertex);

		int success;
		char infoLog[1024];
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type VERTEX:\n" << infoLog << "\n -- ----------------------------" << std::endl;
		}

		// Fragment 

		std::string fShader;
		std::ifstream i2file{ fragmentFile };
		while (std::getline(i2file, Line))
		{
			fShader += Line;
			fShader += "\n";
		}
		i2file.close();
		const char* cfShader = fShader.c_str();

		unsigned int fragment;
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &cfShader, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type FRAGMENT:\n" << infoLog << "\n -- ----------------------------" << std::endl;
		}

		mProgram = glCreateProgram();
		glAttachShader(mProgram, vertex);
		glAttachShader(mProgram, fragment);
		glLinkProgram(mProgram);
		glGetProgramiv(mProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mProgram, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type Program: \n" << infoLog << "\n -- ----------------------------" << std::endl;
		}
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	OpenGLShader::OpenGLShader(std::string&& vertexFile, std::string&& fragmentFile)
	{
		std::string vShader;
		std::ifstream ifile{ vertexFile };
		std::string Line;
		while (std::getline(ifile, Line))
		{
			vShader += Line;
			vShader += "\n";
		}
		ifile.close();
		const char* cVShader = vShader.c_str();
		// Create Shader Program
		// We first create individual shader objects
		// Then we create a shader program to link all shaders
		unsigned int vertex;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &cVShader, NULL);
		glCompileShader(vertex);

		int success;
		char infoLog[1024];
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type VERTEX:\n" << infoLog << "\n -- ----------------------------" << std::endl;
		}

		// Fragment 

		std::string fShader;
		std::ifstream i2file{ fragmentFile };
		while (std::getline(i2file, Line))
		{
			fShader += Line;
			fShader += "\n";
		}
		ifile.close();
		const char* cfShader = fShader.c_str();

		unsigned int fragment;
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &cfShader, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type FRAGMENT:\n" << infoLog << "\n -- ----------------------------" << std::endl;
		}

		mProgram = glCreateProgram();
		glAttachShader(mProgram, vertex);
		glAttachShader(mProgram, fragment);
		glLinkProgram(mProgram);
		glGetProgramiv(mProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mProgram, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type Program: \n" << infoLog << "\n -- ----------------------------" << std::endl;
		}
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(mProgram);
	}

	void OpenGLShader::Activate()
	{
		glUseProgram(mProgram);
	}
	void OpenGLShader::Pass2FloatValues(const std::string& name, float val1, float val2)
	{
		//Request ScreenSize Uniform Identifier
		glUseProgram(mProgram);
		GLint location{ glGetUniformLocation(mProgram, name.c_str()) };
		glUniform2f(location, val1, val2);
	}
	void OpenGLShader::Pass2FloatValues(std::string&& name, float val1, float val2)
	{
		glUseProgram(mProgram);
		GLint location{ glGetUniformLocation(mProgram, name.c_str()) };
		glUniform2f(location, val1, val2);
	}
}