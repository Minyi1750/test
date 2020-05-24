# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
#set(CMAKE_TOOLCHAIN_FILE F:/Download/tar/vcpkg-master/scripts/buildsystems/vcpkg.cmake)
project ("CMakeProject1")

# 包含子项目。
# add_subdirectory ("CMakeProject1")
add_subdirectory ("cpp_how_to_program_9th")
