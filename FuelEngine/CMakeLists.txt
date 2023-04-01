set(HEADER_FILES
	src/FuelEngineUtil.h
	src/FuelEngineApp.h

)

set(SOURCE_FILES
	src/FuelEngineApp.cpp
)

add_library(FuelEngine SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DFUELENGINE_LIB)