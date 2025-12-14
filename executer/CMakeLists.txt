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

add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_LIST_DIR}/../external/SDL3-3.2.28/lib/x64/SDL3.dll"
        $<TARGET_FILE_DIR:Game>
)
