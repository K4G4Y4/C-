cmake_minimum_required(VERSION 3.24)
project(PASSWORD_01)

set(CMAKE_CXX_STANDARD 20)

add_executable(PASSWORD_01 main.cpp Class_password.cpp Class_password.h Labels.cpp Labels.h User_interface.cpp User_interface.h Input_output_file.cpp Input_output_file.h Encryption.cpp Encryption.h Labels.cpp Password_func.cpp Password_func.h)
