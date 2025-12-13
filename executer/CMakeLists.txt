cmake_minimum_required(VERSION 3.12)

project(Game)

set(CMAKE_CXX_STANDARD 20)

set(GAME_SRC
	src/main.cpp
)

add_executable(Game
	${GAME_SRC}
)

target_link_libraries(Game PRIVATE Engine)
