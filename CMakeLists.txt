cmake_minimum_required(VERSION 3.26.1)
project(chess_engine_v1)

Message("")
Message( STATUS "CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR} )
Message( STATUS "CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR} )
Message( STATUS "CMAKE_COMMAND: " ${CMAKE_COMMAND} )
Message( STATUS "CMAKE_VERSION: " ${CMAKE_VERSION} )
Message( STATUS "CMAKE_C_COMPILER: " ${CMAKE_C_COMPILER} )
Message( STATUS "CMAKE_PROJECT_NAME: " ${CMAKE_PROJECT_NAME} )
Message( STATUS "CMAKE_FINDCMAKE: " ${CMAKE_SOURCE_DIR}/CMAKE )

# ------- Set Vars ------- #

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMAKE")
set(SOURCE_FILES
        src/main.cpp
        src/SDLWindow.cpp
        src/SDLWindow.h
        src/bitboard.cpp
        src/bitboard.h
        src/types.h
        src/pieces/pawn.h
        src/pieces/king.h
        src/pieces/knight.h
        src/pieces/rook.h
        src/pieces/bishop.h
        src/pieces/queen.h
        src/bitboard.cpp
        src/SDLWindow.h
        src/SDLWindow.cpp)

Message("")
Message( STATUS "SOURCE entry point : " ${SOURCE_FILES} )
Message("")

# ------- End Set Vars --- #

# ------- Tests --- #

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        bitboard_test
        tests/bitboard_test.cpp
)
target_link_libraries(
        bitboard_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(bitboard_test)

# ------- End Tests ----- #

# ------- Executable ----- #

ADD_EXECUTABLE(chess_engine_v1 ${SOURCE_FILES})

# ------- End Executable - #

# ------- Finds ---------- #

FIND_PACKAGE(SDL2 REQUIRED)
Message("")
Message( STATUS "FINDING SDL2" )
IF (${SDL2_FOUND})
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message( STATUS "SDL2_INCLUDE_DIR:" ${SDL2_INCLUDE_DIR})
    Message( STATUS "SDL2_LIBRARY: " ${SDL2_LIBRARY})
ELSE()
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message( FATAL_ERROR "SDL2 NOT FOUND" )
ENDIF()

FIND_PACKAGE(SDL2_IMAGE)
Message("")
Message( STATUS "FINDING SDL2_IMAGE" )
Message( STATUS "SDL2_IMAGE_FOUND: " ${SDL2_IMAGE_FOUND})
IF (${SDL2_IMAGE_FOUND})
    Message( STATUS "SDL2_IMAGE_INCLUDE_DIR: " ${SDL2_IMAGE_INCLUDE_DIR})
    Message( STATUS "SDL2_IMAGE_LIBRARY: " ${SDL2_IMAGE_LIBRARY})
ELSE()
    Message( FATAL_ERROR "SDL2_IMAGE NOT FOUND" )
ENDIF()

FIND_PACKAGE(SDL2TTF)
Message("")
Message( STATUS "FINDING SDL2TTF" )
Message( STATUS "SDL2TTF_FOUND: " ${SDL2TTF_FOUND} )
IF (${SDL2TTF_FOUND})
    Message( STATUS "SDL2TTF_INCLUDE_DIR: " ${SDL2TTF_INCLUDE_DIR})
    Message( STATUS "SDL2TTF_LIBRARY: " ${SDL2TTF_LIBRARY})
ELSE()
    Message( FATAL_ERROR "SDL2TTF NOT FOUND" )
ENDIF()
Message("")

FIND_PACKAGE(SDL2Mixer)

Message( STATUS "FINDING SDL2Mixer" )
Message( STATUS "SDL2Mixer_FOUND: " ${SDL2Mixer_FOUND} )

Message("")

file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# ------- End Finds ------ #

# ------- Inc & Link ---- #
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2Mixer_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2Mixer_LIBRARY})

# ------- End ----------- #


