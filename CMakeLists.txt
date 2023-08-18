project(RType)
cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=gnu++11")

include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/client/include/
	${CMAKE_CURRENT_SOURCE_DIR}/client/include/network/asio
	${CMAKE_CURRENT_SOURCE_DIR}/client/include/network/abstraction
	${CMAKE_CURRENT_SOURCE_DIR}/client/include/graphics
	${CMAKE_CURRENT_SOURCE_DIR}/client/include/graphics/SFML
	${CMAKE_CURRENT_SOURCE_DIR}/client/include/graphics/Interfaces


	${CMAKE_CURRENT_SOURCE_DIR}/server/include/
	${CMAKE_CURRENT_SOURCE_DIR}/server/include/network/
	${CMAKE_CURRENT_SOURCE_DIR}/server/include/network/asio
	${CMAKE_CURRENT_SOURCE_DIR}/server/include/network/abstraction
	
	${CMAKE_CURRENT_SOURCE_DIR}/ECS/include/
	${CMAKE_CURRENT_SOURCE_DIR}/ECS/include/BasicEngine/
	${CMAKE_CURRENT_SOURCE_DIR}/lib/include
	${CMAKE_CURRENT_SOURCE_DIR}/ECS/include/system/

	${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(r-type_server
	server/src/main.cpp

	server/src/network/abstraction/AServer.cpp
	server/src/network/abstraction/AGameServer.cpp
	server/src/network/abstraction/AClient.cpp

	server/src/network/asio/AsioServer.cpp
	server/src/network/asio/AsioClient.cpp
	server/src/network/asio/AsioGameServer.cpp

	ECS/src/GameEngine.cpp
	ECS/src/Manager.cpp
	ECS/src/ComponentManager.cpp
	ECS/src/ISystemNetwork.cpp
	ECS/src/system/SystemCollision.cpp
)

add_executable(r-type_client
	client/src/main.cpp
	client/src/network/abstraction/ANetwork.cpp
	client/src/network/asio/AsioNetwork.cpp
	client/src/graphics/Window.cpp
	client/src/graphics/LoginScene.cpp
	client/src/graphics/LobbyScene.cpp
	client/src/graphics/GameScene.cpp
	client/src/graphics/Interfaces/ADrawable.cpp
	client/src/graphics/Misc.cpp
	client/src/graphics/SFML/SInput.cpp
	client/src/graphics/SFML/SRenderWindow.cpp
	client/src/graphics/SFML/SText.cpp
	client/src/graphics/SFML/SButton.cpp
	client/src/graphics/SFML/SSprite.cpp
	client/src/graphics/SFML/SSound.cpp
)

add_executable(r-type
	ECS/main.cpp
	ECS/src/Manager.cpp
	ECS/src/ComponentManager.cpp
	ECS/src/GameEngine.cpp
	ECS/src/ISystemNetwork.cpp
	ECS/src/system/SystemCollision.cpp
)

add_library(monster1 SHARED
	lib/src/Monster1.cpp
	ECS/src/Manager.cpp
	ECS/src/ComponentManager.cpp
)

add_library(monster2 SHARED
	lib/src/Monster2.cpp
	ECS/src/Manager.cpp
	ECS/src/ComponentManager.cpp
)

add_library(monster3 SHARED
	lib/src/Monster3.cpp
	ECS/src/Manager.cpp
	ECS/src/ComponentManager.cpp
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build/bin/)

add_custom_command(TARGET monster1 monster2 monster3 POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/build/lib ${CMAKE_CURRENT_SOURCE_DIR}/build/bin/lib
)

# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build/bin/)

target_link_libraries(r-type_server ${CONAN_LIBS} dl)
target_link_libraries(r-type_client ${CONAN_LIBS})
target_link_libraries(r-type dl)
