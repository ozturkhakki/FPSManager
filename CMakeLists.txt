project(FPSManager)

cmake_minimum_required(VERSION 2.8)

# Add source files directories to source list
aux_source_directory(. SRC_LIST)
aux_source_directory(./FPSManager SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

# Add c++11 features
add_definitions(-std=c++11)
