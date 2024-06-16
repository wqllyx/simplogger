cmake_minimum_required(VERSION 3.15)

project(mylogger 
    DESCRIPTION "logger器"
    LANGUAGES "CXX"
)

file(GLOB SRC "${PROJECT_SOURCE_DIR}/Logger/*.cpp")
message(STATUS "${SRC}")
add_library(compile_flags INTERFACE)
target_compile_features(compile_flags INTERFACE cxx_std_11)

add_executable(logger main.cpp ${SRC})

target_link_libraries(logger INTERFACE compile_flags)
target_include_directories(logger PUBLIC "$(PROJCET_SOURCE_DIR)/Logger")
