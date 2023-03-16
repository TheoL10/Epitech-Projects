cmake_minimum_required (VERSION 3.8)

project ("Game_engine")
project (ecs)

if (WIN32)
	find_program(conan_path conan)
	message(${conan_path})
	execute_process(COMMAND ${conan_path} "install" "${PROJECT_SOURCE_DIR}" "-s" "compiler=Visual Studio" "-s" "compiler.version=16" "-s" "build_type=Debug" WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
else()
	add_definitions("-fPIC")
endif()
include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# rtype Server
include_directories(${CMAKE_INCLUDE_PATH} ../../Game_Engine/hpp/)
set(SERVER_BUILD_DIR "${CMAKE_BINARY_DIR}/bin/")

add_executable (ecs
"src/main.cpp"
"src/myEvent.cpp"
"src/myEventBoss.cpp"
"src/EnemyExplosion.cpp"
"src/Enemy.cpp"
"src/Enemy2.cpp"
"src/Enemy3.cpp"

"../../Game_Engine/cpp/System_Physics.cpp"
"../../Game_Engine/cpp/System_Shoot.cpp"
"../../Game_Engine/cpp/System_Event.cpp"
"../../Game_Engine/cpp/System_Display.cpp"
"../../Game_Engine/cpp/System_Anim.cpp"
"../../Game_Engine/cpp/System_Colision.cpp"
"../../Game_Engine/cpp/Comp_TextSprite.cpp"
"../../Game_Engine/cpp/Comp_Anim.cpp"
"../../Game_Engine/cpp/Comp_Sound.cpp"
"../../Game_Engine/cpp/EntityManager.cpp"
"../../Game_Engine/cpp/EventShoot.cpp"
)

target_link_libraries(ecs ${CONAN_LIBS} ${CONAN_LIB_DIRS_BOOST} -lboost_serialization)
target_link_libraries(ecs sfml-graphics sfml-window sfml-system sfml-audio)
#target_link_libraries(ecs boost::boost)
add_definitions("-Wall -Wextra")
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set_target_properties(ecs PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${SERVER_BUILD_DIR}")
set_target_properties(ecs PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${SERVER_BUILD_DIR}")
set_target_properties(ecs PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${SERVER_BUILD_DIR}")
