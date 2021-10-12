cmake_minimum_required(VERSION 3.17)
project(AppKitLib)

set(CMAKE_CXX_STANDARD 20)

link_directories("/opt/homebrew/lib")

include(FindPkgConfig)

add_library(AppKitLib SHARED gfx/Gfx.cpp gfx/Gfx.h audio/Audio.c audio/Audio.h core/GameException.cpp core/GameException.h keyboard/KeyboardEvents.cpp keyboard/KeyboardEvents.h keyboard/KeyboardListener.h gfx/TextObject.cpp gfx/TextObject.h gfx/Texture.cpp gfx/Texture.h gfx/GfxObject.cpp gfx/GfxObject.h physics/CollisionReactor.cpp physics/CollisionReactor.h core/ObjectRegistry.cpp core/ObjectRegistry.h physics/Object.cpp physics/Object.h)

find_package(Boost REQUIRED COMPONENTS system thread)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

include_directories(${Boost_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} Boost::system Boost::thread)