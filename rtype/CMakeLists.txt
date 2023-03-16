cmake_minimum_required (VERSION 3.8)

project ("rtype")
project (r-type_client)
project (r-type_server)

if (WIN32)
	find_program(conan_path conan)
	message(${conan_path})
	execute_process(COMMAND ${conan_path} "install" "${PROJECT_SOURCE_DIR}" "-s" "compiler=Visual Studio" "-s" "compiler.version=16" "-s" "build_type=Debug" WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
else()
	add_definitions("-fPIC")
endif()
include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# rtype Client
Set(Boost_INSTALL_DIR ${CONAN_BOOST_ROOT})
include_directories(${CMAKE_INCLUDE_PATH} Client/hpp/ ${CONAN_INCLUDE_DIRS_BOOST})
set(CLIENT_BUILD_DIR "${CMAKE_BINARY_DIR}/bin/")
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Boost REQUIRED)
find_package(Threads REQUIRED)

add_executable (r-type_client
"Client/src/Client.cpp"
"Client/src/tcp_client.cpp"
"Client/src/main.cpp"
"Client/src/Particle_System.cpp"
"Client/src/Game.cpp"
)

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
target_link_libraries(r-type_client Threads::Threads)
target_link_libraries(r-type_client sfml-graphics sfml-window sfml-system sfml-audio)
target_link_libraries(r-type_client -lboost_serialization)
# target_link_libraries(r-type_client Boost::Boost)

# rtype Server
include_directories(${CMAKE_INCLUDE_PATH} Server/hpp/)
include_directories(${CMAKE_INCLUDE_PATH} Game_Engine/hpp/)
set(SERVER_BUILD_DIR "${CMAKE_BINARY_DIR}/bin/")

add_executable (r-type_server
"Server/src/main.cpp"
"Server/src/Server.cpp"
"Server/src/loop.cpp"
"Server/src/Enemy.cpp"
"Server/src/Enemy2.cpp"
"Server/src/Enemy3.cpp"
"Server/src/Enemy4.cpp"
"Server/src/EnemyExplosion.cpp"
"Server/src/myEvent.cpp"
"Server/src/myEventBoss.cpp"
"Server/src/tcp_server.cpp"

"Game_Engine/cpp/Comp_Anim.cpp"
"Game_Engine/cpp/Comp_TextSprite.cpp"
"Game_Engine/cpp/Comp_Sound.cpp"
"Game_Engine/cpp/EntityManager.cpp"
"Game_Engine/cpp/EventShoot.cpp"
"Game_Engine/cpp/System_Anim.cpp"
"Game_Engine/cpp/System_Colision.cpp"
"Game_Engine/cpp/System_Display.cpp"
"Game_Engine/cpp/System_Event.cpp"
"Game_Engine/cpp/System_Physics.cpp"
"Game_Engine/cpp/System_Shoot.cpp"
)

target_link_libraries(r-type_server ${CONAN_LIBS} ${CONAN_LIB_DIRS_BOOST} -lboost_serialization)
target_link_libraries(r-type_server sfml-graphics sfml-window sfml-system sfml-audio)
add_definitions("-Wall")
add_definitions("-Wextra")
add_definitions("-g")
#target_link_libraries(r-type_server boost::boost)
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set_target_properties(r-type_server PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${SERVER_BUILD_DIR}")
set_target_properties(r-type_server PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${SERVER_BUILD_DIR}")
set_target_properties(r-type_server PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${SERVER_BUILD_DIR}")
