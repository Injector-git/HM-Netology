# CMakeList.txt: проект CMake для CMake_dynamic_library; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMake_dynamic_library")

# Добавьте источник в исполняемый файл этого проекта.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(Leaver SHARED  "Leaver.h" "Leaver.cpp")
add_executable (CMake_dynamic_library "CMake_dynamic_library.cpp" "Leaver.h" "Leaver.cpp")
target_link_libraries(CMake_dynamic_library Leaver)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMake_dynamic_library PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
