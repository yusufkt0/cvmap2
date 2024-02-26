cmake_minimum_required(VERSION 3.5)

project(cvmap++)

SET("OpenCV_DIR" "/usr/share/OpenCV")
find_package( OpenCV REQUIRED )
include_directories(include/)
add_executable(cvmap++
    src/main.cpp
    include/main.hpp
)

target_link_libraries(cvmap++ ${OpenCV_LIBRARIES})