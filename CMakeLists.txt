cmake_minimum_required(VERSION 3.5)

project(cvmap++)

SET("OpenCV_DIR" "/usr/share/OpenCV")
find_package( OpenCV REQUIRED )

add_executable(cvmap++
    src/main.cpp
    src/map.cpp
    include/main.h
    include/map.h
)

target_link_libraries(cvmap++ ${OpenCV_LIBRARIES})