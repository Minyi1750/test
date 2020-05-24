# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 设置boost

#set(BOOST_ROOT F:/Download/tar/vcpkg-master/installed/x86-windows)
#set(BOOST_ROOT D:/src/boost/boost_1_72_0/boost_1_72_0)
#set(Boost_INCLUDE_DIRS D:/src/boost/boost_1_72_0_installbak/include/boost-1_72)
#find_package(Boost REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})
#message(STATUS ${Boost_INCLUDE_DIRS} ${Boost_LIBRARIES})
set(SFML_ROOT F:/Download/tar/vcpkg-master/installed/x86-windows)
find_package(SFML REQUIRED)
# Note: 7 target(s) were omitted.
#target_link_libraries(main )


# 将源代码添加到此项目的可执行文件。
add_executable (TextQuery boost_string_demo.cpp)
#target_link_libraries(TextQuery ${Boost_LIBRARIES})

# TODO: 如有需要，请添加测试并安装目标。
