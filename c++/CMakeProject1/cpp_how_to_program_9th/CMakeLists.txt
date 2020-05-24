# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 设置boost


# 将源代码添加到此项目的可执行文件。
# commission_employee.cpp
add_library(commission_employee commission_employee.h commission_employee.cpp)
add_library(base_plus_commission_employee_inheritance base_plus_commission_employee_inheritance.h base_plus_commission_employee_inheritance.cpp)
add_executable (commission_employee_inheritance base_plus_commission_employee_inheritance_test.cpp)
target_link_libraries(commission_employee_inheritance base_plus_commission_employee_inheritance commission_employee)

# TODO: 如有需要，请添加测试并安装目标。
