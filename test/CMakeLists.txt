cmake_minimum_required(VERSION 3.7.2)
project(rock_paper_scissors_tests)

add_subdirectory(lib/googletest)

include_directories(${ROCK_PAPER_SCISSORS_HEADERS_DIR})

set(SOURCE_FILES src/RockPaperScissorsTest.cpp src/RockPaperScissorsAppTest.cpp src/MockRockPaperScissors.h)

add_executable(rock_paper_scissors_tests ${SOURCE_FILES})
target_link_libraries(rock_paper_scissors_tests rock_paper_scissors gtest_main gtest gmock)