add_executable(SPRING_GAME main.cpp)

include_directories(../FuelEngine/include)

target_link_libraries(SPRING_GAME FuelEngine)