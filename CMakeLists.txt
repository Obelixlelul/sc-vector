cmake_minimum_required(VERSION 2.6)
project(Vector)

#Bring the headers into the project
include_directories(include)

#However, the file (Glob...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(app ${SOURCES})

#To create cmake inside the build folder when its not working in tradicional methods
#cmake -S . -Bbuild