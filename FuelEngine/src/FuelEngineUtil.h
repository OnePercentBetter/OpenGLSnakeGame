#pragma once
#ifdef FUELENGINE_WINDOWS
	#ifdef FUELENGINE_LIB
		#define FUELENGINE_API __declspec(dllexport)
	#else
		#define FUELENGINE_API __declspec(dllimport)
	#endif
#else
	#define FUELENGINE_API 
#endif

//Start
#define FUELENGINE_START(ClassName) \
int main()\
{\
	ClassName game;\
	game.Run();\
	return 0;\
}