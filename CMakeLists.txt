cmake_minimum_required(VERSION 3.28)
project(git_employee_management_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(git_employee_management_system main.cpp
        worker_manager.h
        worker_manager.cpp)
