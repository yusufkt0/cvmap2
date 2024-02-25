cmake_minimum_required(VERSION 3.5)

project(cvmap++)

SET("OpenCV_DIR" "/usr/share/OpenCV")
find_package( OpenCV REQUIRED )
include_directories(include/)
add_executable(cvmap++
    src/main.cpp
    src/map.cpp
    src/cam.cpp
    include/main.hpp
    include/map.hpp
    include/cam.hpp
)

target_link_libraries(cvmap++ ${OpenCV_LIBRARIES})