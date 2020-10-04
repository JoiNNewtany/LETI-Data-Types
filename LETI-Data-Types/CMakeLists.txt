# CMakeList.txt : CMake project for LETI-Data-Types, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (DataTypes "src/main.cpp" "src/data_types_helper.cpp" "include/LETI-Data-Types/data_types_helper.hpp")
