include_directories(../FuelEngine/include)

set(SOURCE_FILES GameDevelopment.cpp)
set(HEADER_FILES)

add_executable(GAME_DEVELOPMENT_PROJECT  Game_Development.cpp)

target_link_libraries(GAME_DEVELOPMENT_PROJECT PRIVATE FuelEngine)