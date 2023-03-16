cmake_minimum_required(VERSION 3.0)
project(bomberman)

set(CMAKE_CXX_STANDARD 14)

add_executable(bomberman 
src/Engine.cpp 
src/main.cpp 
src/MenuManager.cpp
src/process.cpp 
src/raylib.cpp 
src/SceneGame.cpp 
src/SceneLevelSelect.cpp 
src/SceneMenu.cpp
src/ScenePause.cpp
src/SceneSaveSelect.cpp 
src/SceneSettings.cpp 
src/SceneVersus.cpp
)

if (UNIX)
	find_package(raylib REQUIRED)
	target_link_libraries(bomberman raylib)
endif (UNIX)

if (WIN32)
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
	find_package(raylib REQUIRED)
	target_link_libraries(bomberman raylib)
endif (WIN32)

target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
target_compile_definitions(${PROJECT_NAME} PUBLIC SAVE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/save/") # Set the asset path macro to the absolute path on the dev machine
