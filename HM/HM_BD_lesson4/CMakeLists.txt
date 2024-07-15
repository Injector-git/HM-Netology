cmake_minimum_required(VERSION 3.20)

project(HM_BD_lesson4)

add_executable(HM_BD_lesson4 main.cpp)

add_subdirectory(C:\\Libpqxx\\libpqxx-7.9.1 libpqxx-build) # Укажите путь к libpq++

target_compile_features(HM_BD_lesson4 PRIVATE cxx_std_17) # Включите C++17

target_link_libraries(HM_BD_lesson4 PRIVATE pqxx) # Слинкуйте libpq++ к проекту
