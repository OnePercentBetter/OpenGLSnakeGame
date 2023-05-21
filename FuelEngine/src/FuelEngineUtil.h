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

#if FUELENGINE_DEBUG==2
	#define FUELENGINE_LOG(x) std::cout<<"Log: " <<x<<std::endl;
	#define FUELENGINE_ERROR(x) std::cerr<<"Error: " <<x<<std::endl;

#elif FUELENGINE_DEBUG==1
	#define FUELENGINE_LOG(x)
	#define FUELENGINE_ERROR(x) std::cerr<<"Error: " <<x<<std::endl;
#else
	#define FUELENGINE_LOG(x)
	#define FUELENGINE_ERROR(x)
#endif