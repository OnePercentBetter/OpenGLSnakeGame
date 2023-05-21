#pragma once

#include "pch.h"

namespace FuelEngine
{
	class ImplImage {
	public:
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;

		virtual ~ImplImage() {};

		virtual void Activate() = 0;

	};
}
