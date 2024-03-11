# CMakeList.txt: проект CMake для More_complex_project; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("More_complex_project")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (More_complex_project "More_complex_project.cpp" "More_complex_project.h" 
"Fig.h"  
"EquilateralTriangle.h" "EquilateralTriangle.cpp" 
"Figure.h" "Figure.cpp" 
"Parallelogram.h" "Parallelogram.cpp" 
"Quadrangle.h" "Quadrangle.cpp" 
"Rhombus.h" "Rhombus.cpp" 
"RighTriangle.h" "RighTriangle.cpp" 
"Square.h" "Square.cpp" 
"IsoscelesTriangle.h" "IsoscelesTriangle.cpp" 
"MyRectangle.h" "MyRectangle.cpp" 

"Triangle.h" "Triangle.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET More_complex_project PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
