cmake_minimum_required(VERSION 3.15)
project(hw1)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw1 main.cpp User.cpp User.h database/data/Database.cpp database/data/Database.h Profile.cpp Profile.h model/Response.cpp model/Response.h exceptions/Exceptions.cpp exceptions/Exceptions.h extentions/Extentions.cpp extentions/Extentions.h database/DataBaseRepository.cpp database/DataBaseRepository.h)