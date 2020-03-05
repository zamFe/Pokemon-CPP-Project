cmake_minimum_required(VERSION 3.13)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp GameManager.cpp GameManager.h "Pokemon classes/Pokemon.cpp" "Pokemon classes/Pokemon.h" "Pokemon classes/Movesets.h" "Pokemon classes/Moves.h" Visuals/Animations.cpp Visuals/Animations.h "Pokemon classes/Moves.cpp" "Pokemon classes/Stats.cpp" "Pokemon classes/Stats.h" Visuals/Displays.cpp Visuals/Displays.h Players/Character.cpp Players/Character.h Players/AI.cpp Players/AI.h Players/Player.cpp Players/Player.h "Pokemon classes/Type.cpp" "Pokemon classes/Type.h")